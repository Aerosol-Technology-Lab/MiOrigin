#include "PageTimer.hpp"
#include "Home.hpp"

#include "Calibration.h"
#include "../driver/miclone.hpp"
#include "../driver/touchscreen.h"
#include "utils.h"

extern PageSystem_t devicePageManager;

_PageTimer::_PageTimer()
    : buttonStop(false)
{
    pageArgs = nullptr;

    new (&buttonStop) Button(drawingWrapper, "STOP", 200, 100, 140, 100);
    buttonStop.setButtonSize(2);
    buttonStop.setTextColor(CMXG_WHITE);
    buttonStop.setButtonColor(CMXG_RED);
    buttonStop.onPress = [](uint16_t x, uint16_t y, uint8_t z) {
    };
    buttonStop.onHoverEnter = [](uint16_t x, uint16_t y, uint8_t z) {
    };
    buttonStop.onHoverExit = [](uint16_t x, uint16_t y, uint8_t z) {
    };
    buttonStop.onRelease = [](uint16_t x, uint16_t y, uint8_t z) {
        Driver::miclone_stop();
        // PageSystem_findSwitch(&devicePageManager, "home-page", 0);
    };
};

_PageTimer PageTimer;
