#pragma once

#include <Arduino.h>
#include <XPT2046_Touchscreen.h>
#include <SPI.h>
#include <FreeRTOS.h>

// #define DRIVER_TS_ENABLE_DEBUG_PRINT

#define DRIVER_TS_CHECK_INTERVAL 17

namespace Driver
{
    extern XPT2046_Touchscreen ts;

    extern void (*postDigitizerAction)(void *);
    extern void *postDigitizerArgs;

    typedef void (*TouchscreenFunctionBehavior)();

    enum TouchscreenState : int8_t {
        TOUCHSCREEN_NONE = -1,
        TOUCHSCREEN_PRESSED = 0,
        TOUCHSCREEN_RELEASED = 1
    };

    struct {
        TouchscreenState state;
        int32_t interruptPin;
        bool GPIO_firstGroup;

        struct {
            uint16_t x;
            uint16_t y;
            uint8_t  z;
        } point;

        TouchscreenFunctionBehavior onPress;

        TouchscreenFunctionBehavior onRelease;
        
        struct {

            TouchscreenFunctionBehavior onPress;
            TouchscreenFunctionBehavior onRelease;
        } staged;
        
        TaskHandle_t busyInterruptHandler;
        
    } Touchscreen_cfg;
    
    static void IRAM_ATTR touchscreenISR()
    {
        switch(Touchscreen_cfg.state) {
            // the state of the touch screen is the previous state, not the current one
            case TOUCHSCREEN_PRESSED:
                Touchscreen_cfg.state = TOUCHSCREEN_RELEASED;
                if (Touchscreen_cfg.onRelease) Touchscreen_cfg.onRelease();
                break;

            case TOUCHSCREEN_RELEASED:
                Touchscreen_cfg.state = TOUCHSCREEN_PRESSED;
                if (Touchscreen_cfg.onPress) Touchscreen_cfg.onPress();
                break;

            case TOUCHSCREEN_NONE:
                // first time state changed, initialize and get pin state
                bool touched = Touchscreen_cfg.GPIO_firstGroup 
                                ? (GPIO.in >> Touchscreen_cfg.interruptPin) & 1
                                : (GPIO.in1.data >> (Touchscreen_cfg.interruptPin - 32)) & 1;
                // if touched, then the current state must be set opposite so that when the ISR function is recusrively called,
                // it processes the correct change state
                Touchscreen_cfg.state = !touched ? TOUCHSCREEN_PRESSED : TOUCHSCREEN_RELEASED;
                touchscreenISR();
                
                break;
        }
    }

    /**
     * @brief Initialized the touch screen high-level driver. This should be called first
     *          before doing anything with the touch screen.
     */
    void touchscreen_init();

    /**
     * @brief Begins the touch screen driver
     * 
     * @param spi Hardware SPI that is attached to touch screen
     * @param rotation rotation of touch screen
     * @param enableHardwareInterrupts enables hardware interrupts at pin "interruptPin". Not currently working
     *          @warning DO NOT USE and leave as false
     * @param interruptPin GPIO pin attatched to interrupt
     */
    void touchscreen_begin(SPIClass &spi,
                           uint8_t rotation=0,
                           bool enableHardwareInterrupts=false,
                           uint8_t interruptPin=32
                           );

    /**
     * @brief Acquires the x, y, and z coordinate of the raw points from the screen
     *          Because x, y, and z are pointers to a pointer to constant, these values
     *          will always be the updated values from the driver once acquired.
     * @example
     *          const uint16_t *x, *y;
     *          const uint8_t  *z;
     *          touchscreen_get_raw_points(&x, &y, &z);
     * 
     *          while (1) {
     *              // no need to call touchscreen_get_raw_points repeatedly
     *              do_something_with_points(*x, *y, *z);
     *          }
     * 
     * @param x x point
     * @param y y point
     * @param z pressure
     */
    void touchscreen_get_raw_points(const uint16_t **x, const uint16_t **y, const uint8_t **z);

    /**
     * @brief Enables a busy while loop to check if the touch screen is pressed or not
     * 
     * @param enable Enable (true) or disable (false) busy check loop
     * @return true requested operation is successful
     * @return false requested operation is unsuccessful
     */
    bool touchscreen_busy_check_interrupt(bool enable);

    /**
     * @brief Registers a function to call when the touch screen is pressed
     * @warning Don't use this. This is just a wrapper. Look at this function's definition
     * 
     * @param func Function called when touchscreen is pressed
     */
    void touchscreen_register_on_press(TouchscreenFunctionBehavior func);

    /**
     * @brief Registers a function to call when the touch screen is released
     * @warning Don't use this. This is just a wrapper. Look at this function's definition
     * 
     * @param func Function called when touchscreen is released
     */
    void touchscreen_register_on_release(TouchscreenFunctionBehavior func);

    /**
     * @brief Apply touch screen handler if staged
     */
    void touchscreen_apply_staged(); 

    /**
     * @brief RTOS task software based interrupt loop.
     * @warning do not use - this is an internal function used by the driver
     * 
     * @param args unused - pass nullptr
     */
    extern void busyInterruptFunction(void *args);
}
