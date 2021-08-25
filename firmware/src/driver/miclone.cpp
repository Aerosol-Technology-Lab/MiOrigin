#include "miclone.hpp"
#include <Arduino.h>
#include <FreeRTOS.h>
#include "../config.h"

namespace Driver
{
    const char *MICLONE_FORMAT = "/1ZJ0J0J2M3000J6gV3000IP3000V%dOD3000GJ2M15000J0R\r\n\r\n";

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

        Serial2.printf(Driver::MICLONE_FORMAT, micloneData.rate / 5);
        TickType_t sleepTime = micloneData.time ? micloneData.time : portMAX_DELAY;
        vTaskDelay(sleepTime / portTICK_PERIOD_MS);
        
        xSemaphoreTake(MiCloneHandlerSemaphore, portMAX_DELAY);
        TaskHandle_t thisTask = MiCloneTaskHandler;
        MiCloneTaskHandler = nullptr;

        xSemaphoreGive(MiCloneHandlerSemaphore);
        
        vTaskDelete(thisTask);
    }
    
    bool begin()
    {
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

        xSemaphoreGive(MiCloneHandlerSemaphore);
        return true;
    }
    
    SemaphoreHandle_t MiCloneHandlerSemaphore = nullptr;
    TaskHandle_t MiCloneTaskHandler = nullptr;
}
