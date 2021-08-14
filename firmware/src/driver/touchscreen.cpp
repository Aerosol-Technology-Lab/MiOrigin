#include "touchscreen.h"

#include <Arduino.h>
#include <XPT2046_Touchscreen.h>
#include "common.h"

void Driver::touchscreen_begin(SPIClass &spi, uint8_t rotation, bool enableInterrupts, uint8_t interruptPin)
{
    ts.begin(spi);
    if (rotation) ts.setRotation(rotation);

    Touchscreen_cfg.state = Driver::TOUCHSCREEN_NONE;
    Touchscreen_cfg.onPress = nullptr;
    Touchscreen_cfg.onRelease = nullptr;

    if (enableInterrupts) {
        Touchscreen_cfg.interruptPin = interruptPin;
        Touchscreen_cfg.GPIO_firstGroup = interruptPin < 32;
        pinMode(interruptPin, INPUT_PULLDOWN);
        attachInterrupt(digitalPinToInterrupt(interruptPin), touchscreenISR, CHANGE);
    }
    
}


void Driver::touchscreen_register_on_press(TouchscreenFunctionBehavior func)
{
    Touchscreen_cfg.onPress = func;
}

void Driver::touchscreen_register_on_release(TouchscreenFunctionBehavior func)
{
    Touchscreen_cfg.onRelease = func;
}

namespace Driver
{
    XPT2046_Touchscreen ts(TCH_CS);
}
