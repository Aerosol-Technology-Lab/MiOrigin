#pragma once

#include <stdint.h>
#include <FreeRTOS.h>

namespace Driver
{
    extern const char *MICLONE_FORMAT;

    extern SemaphoreHandle_t MiCloneHandlerSemaphore;
    extern TaskHandle_t MiCloneTaskHandler;

    typedef struct {

        uint16_t rate;
        uint32_t time;
    } MiCloneData_t;

    void MiCloneTask(void *args);

    bool begin();

    /**
     * @brief Starts the MiClone software
     * 
     * @param rate 
     * @param time 
     * @return true 
     * @return false 
     */
    bool miclone_start(uint16_t rate=600, uint32_t time=0);

    bool miclone_stop();
}
