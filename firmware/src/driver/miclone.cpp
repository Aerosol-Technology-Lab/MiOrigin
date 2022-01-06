#include "miclone.hpp"
#include <Arduino.h>
#include <Stream.h>
#include <FreeRTOS.h>
#include "../config.h"

#ifdef DEV_DEBUG
#include "utils.h"
#endif

namespace Driver
{
    // const char *MICLONE_FORMAT  = "/1ZJ0J0J3M3000J7gV3000IP3000V%dOD3000GJ3M15000J0R\r\n";
    // const char *MICLONE_FORMAT  = "/1ZJ0J0J6gV3000IP3000OV%dD3000GJ2M30000J0R\r\n";
    // const char *MICLONE_FORMAT  = "/1ZJ0J0J7gV3000IP3000OV%dD3000GJ3M30000J0R\r\n";
    const char *MICLONE_FORMAT  = "/1ZJ0J0J7gV3000IP3000OV%dD3000GJ3M30000J0R\r\n";
    
    void MiCloneTask(void *args)
    {
        #ifdef SAFE_CODE
        // if (!args) {
            // assert(false && "TODO: Implement this");
            // vTaskDelete()
        // }
        #endif

        MiCloneData_t micloneData = *reinterpret_cast<MiCloneData_t *>(args);
        free(args);

        for (int i = 0; i < 3; ++i) {

            miclone_send_start(micloneData.rate);
            vTaskDelay(1000 / portTICK_PERIOD_MS);
        }

        
        TickType_t sleepTime = micloneData.time ? (micloneData.time / portTICK_PERIOD_MS) : portMAX_DELAY;
        Serial.printf("-> [MICLONE] timer is %dms and actual sleep time is: %d\n", micloneData.time, sleepTime);
        vTaskDelay(sleepTime);
        
        for (int i = 0; i < 3; ++i) {

            miclone_send_stop();
            vTaskDelay(1000 / portTICK_PERIOD_MS);
        }

        xSemaphoreTake(MiCloneHandlerSemaphore, portMAX_DELAY);
        TaskHandle_t thisTask = _MiCloneTaskHandler;
        _MiCloneTaskHandler = nullptr;

        Serial.println("[MICLONE] This task is done!");

        xSemaphoreGive(MiCloneHandlerSemaphore);
        
        vTaskDelete(thisTask);
    }
    
    bool miclone_begin(Stream *stream)
    {
        if (MiCloneHandlerSemaphore) return false;

        _micloneStream = stream;
        MiCloneHandlerSemaphore = xSemaphoreCreateMutex();
        return true;
    }
    
    bool miclone_start(uint16_t rate, uint32_t time)
    {
        xSemaphoreTake(MiCloneHandlerSemaphore, portMAX_DELAY);
        
        // task handler exists, so it's already started
        if (_MiCloneTaskHandler) {
            xSemaphoreGive(MiCloneHandlerSemaphore);
            return false;
        }

        MiCloneData_t *micloneData = reinterpret_cast<MiCloneData_t *>(malloc(sizeof(MiCloneData_t)));
        micloneData->rate = rate;
        micloneData->time = time;
        
        _MiCloneTaskHandler = xTaskCreateStatic(MiCloneTask,
                          "miclone-tsk",
                          MICLONE_STACK_SIZE,
                          micloneData,
                          1,
                          _MiCloneStack,
                          &_MiCloneTaskBuffer
        );

        xSemaphoreGive(MiCloneHandlerSemaphore);
        return true;
    }
    
    bool miclone_stop()
    {
        // nothing for now
        xSemaphoreTake(MiCloneHandlerSemaphore, portMAX_DELAY);

        if (_MiCloneTaskHandler) {
            vTaskSuspend(_MiCloneTaskHandler);
            vTaskDelete(_MiCloneTaskHandler);
            _MiCloneTaskHandler = nullptr;
            // miclone_send_stop(0);
            miclone_send_stop(2);
        }
        else {
            miclone_send_stop(2);
        }
        
        xSemaphoreGive(MiCloneHandlerSemaphore);
    }
    
    void miclone_send_start(uint16_t rate)
    {
        _micloneStream->printf(MICLONE_FORMAT, rate / 5);
        #ifdef DEV_DEBUG
        Serial.printf("Starting milone with rate %d and val %d", rate, rate/5);
        Serial.printf(MICLONE_FORMAT, rate / 5);
        #endif
    }
    
    void miclone_send_stop(uint8_t stopType)
    {
        Serial.println("[MICLONE] Sending stop signal");
        _micloneStream->print("/1TR\r\n/1J0R\r\n");

        if (stopType == 2) {
            _micloneStream->print("/1J0TR\r\n");
            return;
        }

        switch (stopType) {
        case 1:
            _micloneStream->print("/1\r\n");    // todo: find out when this special case happens
        case 0:                                 // looks like it happens when device is already stopped and you call this again
        default:
            _micloneStream->print("/1\r\n");     // todo: analyze when this is specifically called. Looks like
            break;                              // looks like it happens only when the collector is already running
        
        }
    }
    
    SemaphoreHandle_t MiCloneHandlerSemaphore = nullptr;
    Stream *_micloneStream = nullptr;

    TaskHandle_t _MiCloneTaskHandler = nullptr;
    StaticTask_t _MiCloneTaskBuffer;
    StackType_t _MiCloneStack[ MICLONE_STACK_SIZE ];
}
