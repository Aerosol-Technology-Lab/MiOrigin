#include "miclone.hpp"
#include <Arduino.h>
#include <Stream.h>
#include <FreeRTOS.h>
#include "../config.h"

namespace Driver
{
    const char *MICLONE_FORMAT = "/1ZJ0J0J2M3000J6gV3000IP3000V%dOD3000GJ2M15000J0R\r\n";

    void MiCloneTask(void *args)
    {
        #ifdef SAFE_CODE
        if (!args) {
            assert(false && "TODO: Implement this");
            vTaskDelete()
        }
        #endif

        MiCloneData_t micloneData = *reinterpret_cast<MiCloneData_t *>(args);
        free(args);

        miclone_send_start(micloneData.rate);
        TickType_t sleepTime = micloneData.time ? micloneData.time / portTICK_PERIOD_MS : portMAX_DELAY;
        vTaskDelay(sleepTime);
        
        miclone_send_stop(0);
        xSemaphoreTake(MiCloneHandlerSemaphore, portMAX_DELAY);
        TaskHandle_t thisTask = MiCloneTaskHandler;
        MiCloneTaskHandler = nullptr;

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
        if (MiCloneTaskHandler) {
            xSemaphoreGive(MiCloneHandlerSemaphore);
            return false;
        }

        MiCloneData_t *micloneData = reinterpret_cast<MiCloneData_t *>(malloc(sizeof(MiCloneData_t)));
        micloneData->rate = rate;
        micloneData->time = time;
        
        xTaskCreate(MiCloneTask,
                    "miclone-tsk",
                    1024,
                    micloneData,
                    1,
                    &MiCloneTaskHandler
                    );

        xSemaphoreGive(MiCloneHandlerSemaphore);
        return true;
    }
    
    bool miclone_stop()
    {
        // nothing for now
        xSemaphoreTake(MiCloneHandlerSemaphore, portMAX_DELAY);

        if (MiCloneTaskHandler) {
            vTaskDelete(MiCloneTaskHandler);
            MiCloneTaskHandler = nullptr;
            miclone_send_stop(0);
        }
        else {
            miclone_send_stop(1);
        }
        
        xSemaphoreGive(MiCloneHandlerSemaphore);
    }
    
    void miclone_send_start(uint16_t rate)
    {
        _micloneStream->printf(MICLONE_FORMAT, rate / 5);
    }
    
    void miclone_send_stop(uint8_t stopType)
    {
        _micloneStream->print("/1TR\r\n/1J0R\r\n");

        switch (stopType) {
        case 1:
            _micloneStream->print("/1\r\n");    // todo: find out when this special case happens
        case 0:                                 // looks like it happens when device is already stopped and you call this again
        default:
            _micloneStream->print("/\r\n");     // todo: analyze when this is specifically called. Looks like
            break;                              // looks like it happens only when the collector is already running
        
        }
    }
    
    SemaphoreHandle_t MiCloneHandlerSemaphore = nullptr;
    TaskHandle_t MiCloneTaskHandler = nullptr;
    Stream *_micloneStream = nullptr;
}
