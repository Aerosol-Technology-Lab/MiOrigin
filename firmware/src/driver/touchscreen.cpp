#include "touchscreen.h"

#include <Arduino.h>
#include <XPT2046_Touchscreen.h>
#include "common.h"

void Driver::touchscreen_init()
{
    Touchscreen_cfg.state = Driver::TOUCHSCREEN_NONE;
    Touchscreen_cfg.onPress = nullptr;
    Touchscreen_cfg.onRelease = nullptr;
    Touchscreen_cfg.busyInterruptHandler = nullptr;
}

void Driver::touchscreen_begin(SPIClass &spi, uint8_t rotation, bool enableInterrupts, uint8_t interruptPin)
{
    ts.begin(spi);
    if (rotation) ts.setRotation(rotation);

    if (enableInterrupts) {
        Touchscreen_cfg.interruptPin = interruptPin;
        Touchscreen_cfg.GPIO_firstGroup = interruptPin < 32;
        pinMode(interruptPin, INPUT_PULLDOWN);
        attachInterrupt(digitalPinToInterrupt(interruptPin), touchscreenISR, HIGH);
    }
    else {
        Touchscreen_cfg.interruptPin = -1;
    }
    
}

bool Driver::touchscreen_busy_check_interrupt(bool enable)
{
    if (Touchscreen_cfg.interruptPin >= 0) return false;

    if (enable && Touchscreen_cfg.interruptPin < 0 && !Touchscreen_cfg.busyInterruptHandler) {

        xTaskCreate(
            busyInterruptFunction,
            "ts-interhnd",
            1024,
            nullptr,
            1,
            &Touchscreen_cfg.busyInterruptHandler
        );
        return true;
    }
    else if (!enable && Touchscreen_cfg.busyInterruptHandler) {
        vTaskDelete(Touchscreen_cfg.busyInterruptHandler);
        Touchscreen_cfg.busyInterruptHandler = nullptr;
        return true;
    }

    return false;
}

void Driver::touchscreen_register_on_press(TouchscreenFunctionBehavior func)
{
    Touchscreen_cfg.onPress = func;
}

void Driver::touchscreen_register_on_release(TouchscreenFunctionBehavior func)
{
    Touchscreen_cfg.onRelease = func;
}

void Driver::busyInterruptFunction(void *args)
{
    bool touched = false;
    
    while (true) {
        bool currentState = ts.touched();

#ifdef DRIVER_TS_ENABLE_DEBUG_PRINTnamespace Driver

        if (currentState) {
            
            Serial.println("-> I am so touched!");
        }
        else{
            Serial.println("-> Nothing. I feel nothing at all...");
        }

#endif

        if (currentState != touched) {
            
            uint16_t x, y;
            uint8_t z;
            ts.readData(&x, &y, &z);

            touched = currentState;
            if (touched) {
                if (!Touchscreen_cfg.onPress) {
                    vTaskDelay(1000 / portTICK_PERIOD_MS);
                    continue;
                }
                Touchscreen_cfg.onPress();
            }
            else {
                if (!Touchscreen_cfg.onRelease) {
                    vTaskDelay(1000 / portTICK_PERIOD_MS);
                    continue;
                }
                Touchscreen_cfg.onRelease();
            }
        }

        vTaskDelay(DRIVER_TS_CHECK_INTERVAL / portTICK_PERIOD_MS);
    }
}

namespace Driver
{
    XPT2046_Touchscreen ts(TCH_CS);
}