#include "Debug.hpp"
#include <memory>
#include "../driver/miclone.hpp"
#include "../utils.h"
#include "Calibration.h"
#include "../driver/touchscreen.h"
#include "../driver/tftdisplay.h"

_Debug::_Debug()
{
    pageArgs = nullptr;
    buttons = nullptr;
    buttonsSize = 2;
}

void _Debug::onStart(void *pageArgs)
{
    DebugPage.pageArgs = pageArgs;
}

void _Debug::onLoad(void *, void *args) {

    size_t counter = 0;
    DebugPage.buttons = reinterpret_cast<Button *>(malloc(sizeof(Button) * DebugPage.buttonsSize));

    Serial.println("Not done loading debug");

    // placement new
    new (DebugPage.buttons + counter) Button(drawingWrapper, "START", 10, 10, 200, 300);
    DebugPage.buttons[counter].setTextColor(CMXG_WHITE);
    DebugPage.buttons[counter].setButtonColor(CMXG_RED);
    DebugPage.buttons[counter].onPress = [](uint16_t x, uint16_t y, uint8_t z) {
        Serial.printf("I was pressed on %dx, %dy, %dz", x, y, z);
    };
    DebugPage.buttons[counter].onHoverEnter = [](uint16_t x, uint16_t y, uint8_t z) {
        Serial.printf("I was hovered enter on %dx, %dy, %dz", x, y, z);
    };
    DebugPage.buttons[counter].onHoverExit = [](uint16_t x, uint16_t y, uint8_t z) {
        Serial.printf("I was hovered exit on %dx, %dy, %dz", x, y, z);
    };
    DebugPage.buttons[counter].onRelease = [](uint16_t x, uint16_t y, uint8_t z) {
        Serial.printf("I was released on %dx, %dy, %dz", x, y, z);
        Driver::miclone_start();
    };
    ++counter;
    
    new (DebugPage.buttons + counter) Button(drawingWrapper, "STOP", 10, 10, 200, 300);

    Driver::tft.fillScreen(CMXG_BL_DATUM);
    Driver::touchscreen_register_on_press(DebugPage.ts_onPress);
    Driver::touchscreen_register_on_release(DebugPage.ts_onRelease);
    
    Serial.println("Done loading debug");
    
    for (size_t i = 0; i < DebugPage.buttonsSize; ++i) DebugPage.buttons[i].draw();
}

void _Debug::generatePage(Page_t &page)
{
    strncpy(page.name, DEBUG_PAGE_NAME, PAGE_NAME_SIZE);
    page.params = nullptr;
    page.onStart = DebugPage.onStart;
    page.onLoad = DebugPage.onLoad;
    page.onExit = DebugPage.onExit;
}

Page_t _Debug::generatePage()
{
    Page_t page;
    generatePage(page);
    return page;
}

void _Debug::ts_onPress()
{ 
    dev_println("PRESSED START!");
    uint16_t x, y;
    Calibration.translateFromRaw(x, y);
    dev_println("CALIBRATION DONE!");
    for (size_t i = 0; i < DebugPage.buttonsSize; ++i) {
        DebugPage.buttons[i].performAction(x, y, 0, true);
    }
    dev_println("DEBUG on press handler");
}

void _Debug::ts_onRelease()
{
    uint16_t x, y;
    Calibration.translateFromRaw(x, y);

    for (size_t i = 0; i < DebugPage.buttonsSize; ++i) {
        DebugPage.buttons[i].performAction(x, y, 0, true);
    }
    dev_println("DEBUG on release handler");
}

void _Debug::onExit()
{
    Driver::touchscreen_register_on_press(nullptr);
    Driver::touchscreen_register_on_release(nullptr);
    
    if (DebugPage.buttons) {

        for (size_t i = 0; i < DebugPage.buttonsSize; ++i) {
            // manually call destructor on allocated memory
            DebugPage.buttons[i].~Button();
        }
        free(DebugPage.buttons);
        DebugPage.buttons = nullptr;
    }
}

_Debug DebugPage;
