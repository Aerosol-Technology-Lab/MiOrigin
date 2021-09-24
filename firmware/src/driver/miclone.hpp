#pragma once

#include <stdint.h>
#include <FreeRTOS.h>
#include <Stream.h>
#include <HardwareSerial.h>

#define MICLONE_STACK_SIZE 2 * 1024

namespace Driver
{
    extern const char *MICLONE_FORMAT;

    extern SemaphoreHandle_t MiCloneHandlerSemaphore;
    extern Stream *_micloneStream;
    
    // task information
    extern TaskHandle_t _MiCloneTaskHandler;
    extern StaticTask_t _MiCloneTaskBuffer;
    extern StackType_t _MiCloneStack[ MICLONE_STACK_SIZE ];
    
    typedef struct {

        uint16_t rate;
        uint32_t time;
    } MiCloneData_t;

    void MiCloneTask(void *args);

    bool miclone_begin(Stream *stream=&Serial2);

    /**
     * @brief Starts the MiClone software
     * 
     * @param rate 
     * @param time 
     * @return true 
     * @return false 
     */
    bool miclone_start(uint16_t rate=300, uint32_t time=0);

    /**
     * @brief High level function to stop bioaersol collector. Use this function tas
     *          the primary method to stop the collector
     * 
     * @return true Stop successful
     * @return false The driver did not see that the controller is running, but a force
     *              stop command is sent anyway
     */
    bool miclone_stop();
    
    /**
     * @brief Initializes bioaerosol collector
     */
    void miclone_initialize();

    void miclone_send_start(uint16_t rate);

    /**
     * @brief Sends stop command to RS232. This should not normally called
     *          and instead, you should rely on miclone_stop()
     * 
     * @param stopType stop type mode. Use stopType 1 when forcing a stop
     */
    void miclone_send_stop(uint8_t stopType=1);

}
