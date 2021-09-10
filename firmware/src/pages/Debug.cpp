#include "Debug.hpp"
#include <memory>
#include "../driver/miclone.hpp"
#include "../utils.h"
#include "Calibration.h"
#include "../driver/touchscreen.h"
#include "../driver/tftdisplay.h"
#include "../pagesystem/pagesystem.h"

_Debug::_Debug()
{
    pageArgs = nullptr;
    buttons = nullptr;
    // buttonsSize;
}

void _Debug::onStart(void *pageArgs)
{
    DebugPage.pageArgs = pageArgs;
}

void _Debug::onLoad(void *, void *args) {

    size_t counter = 0;
    DebugPage.buttons = reinterpret_cast<Button *>(malloc(sizeof(Button) * DebugPage.buttonsSize));

    Serial.println("Not done loading debug");

    // limits possible flow rates
    if      (DebugPage.flowRateValue > DEBUG_MAX_FLOW_RATE) DebugPage.flowRateValue = DEBUG_MAX_FLOW_RATE;
    else if (DebugPage.flowRateValue < DEBUG_MIN_FLOW_RATE) DebugPage.flowRateValue = DEBUG_MIN_FLOW_RATE;

    // placement new
    new (DebugPage.buttons + counter) Button(drawingWrapper, "START", 360, 10, 100, 100);
    DebugPage.buttons[counter].setTextColor(CMXG_WHITE);
    DebugPage.buttons[counter].setButtonColor(CMXG_GREEN);
    DebugPage.buttons[counter].onPress = [](uint16_t x, uint16_t y, uint8_t z) {
        // Serial.printf("Start was pressed on %dx, %dy, %dz", x, y, z);
    };
    DebugPage.buttons[counter].onHoverEnter = [](uint16_t x, uint16_t y, uint8_t z) {
        // Serial.printf("I was hovered enter on %dx, %dy, %dz", x, y, z);
    };
    DebugPage.buttons[counter].onHoverExit = [](uint16_t x, uint16_t y, uint8_t z) {
        // Serial.printf("I was hovered exit on %dx, %dy, %dz", x, y, z);
    };
    DebugPage.buttons[counter].onRelease = [](uint16_t x, uint16_t y, uint8_t z) {
        // Serial.printf("I was released on %dx, %dy, %dz", x, y, z);
        Serial.printf("Starting MiClone with %d ul/min flow rate and %d ms", DebugPage.flowRateValue, DebugPage.timerValue);
        Driver::miclone_start(DebugPage.flowRateValue, DebugPage.timerValue);
    };
    ++counter;
    
    new (DebugPage.buttons + counter) Button(drawingWrapper, "STOP", 360, 120, 100, 100);
    DebugPage.buttons[counter].setTextColor(CMXG_WHITE);
    DebugPage.buttons[counter].setButtonColor(CMXG_RED);
        DebugPage.buttons[counter].onPress = [](uint16_t x, uint16_t y, uint8_t z) {
    };
    DebugPage.buttons[counter].onHoverEnter = [](uint16_t x, uint16_t y, uint8_t z) {
    };
    DebugPage.buttons[counter].onHoverExit = [](uint16_t x, uint16_t y, uint8_t z) {
    };
    DebugPage.buttons[counter].onRelease = [](uint16_t x, uint16_t y, uint8_t z) {
        Serial.printf("Stop button released on %dx, %dy, %dz", x, y, z);
        Driver::miclone_stop();
    };
    ++counter;

    // new (DebugPage.buttons + counter) Button(drawingWrapper, "CALIBRATE", 360, 230, 100, 50);
    new (DebugPage.buttons + counter) Button(drawingWrapper, "Initialize", 360, 230, 100, 50);
    DebugPage.buttons[counter].setTextColor(CMXG_BLACK);
    DebugPage.buttons[counter].setButtonColor(CMXG_CYAN);
        DebugPage.buttons[counter].onPress = [](uint16_t x, uint16_t y, uint8_t z) {
    };
    DebugPage.buttons[counter].onHoverEnter = [](uint16_t x, uint16_t y, uint8_t z) {
    };
    DebugPage.buttons[counter].onHoverExit = [](uint16_t x, uint16_t y, uint8_t z) {
    };
    DebugPage.buttons[counter].onRelease = [](uint16_t x, uint16_t y, uint8_t z) {
        PageSystem_findSwitch(&devicePageManager, CALIBRATION_PAGE_NAME, (void *) 0);
    };
    ++counter;

    /* Initialize Flow Rate Timer */
    DebugPage.flowRate = new NumberFieldComponent(drawingWrapper, &(DebugPage.flowRateValue), 20, 80, 250, 40, "Flow Rate\0", "ul/min");
    const char *returnPageName = "debug-page";
    DebugPage.flowRate->setReturnPageName(returnPageName, strlen(returnPageName));
    DebugPage.flowRate->setProperty(
        [](void *_props, int8_t c) -> void {

            NumberFieldDefs::Props_t &props = *reinterpret_cast<NumberFieldDefs::Props_t*>(_props);
            int32_t &flowRate = **reinterpret_cast<int32_t**>(props.value);     // why does this happen???

            Serial.printf("The flow rate before change is: %d\n", flowRate);

            if (c < 0) {
                flowRate /= 10;
            }
            else if (c < 10) {
                flowRate = flowRate * 10 + c;
            }
            else {
                // do nothing
            }

            Serial.println("Things did change");
            Serial.printf("The flow rate is: %d", flowRate);
        },
        [](void *_props, char *buffer, size_t size) -> void {

            NumberFieldDefs::Props_t &props = *reinterpret_cast<NumberFieldDefs::Props_t*>(_props);
            int32_t &flowRate = *reinterpret_cast<int32_t*>(props.value);

            char numBuff[16];
            sprintf(numBuff, "%d", flowRate);

            strncpy(buffer, numBuff, std::min(sizeof(numBuff), size));
        }
        );
    
    DebugPage.timerComponent = new NumberFieldComponent(drawingWrapper, &DebugPage.timerValue, 20, 160, 250, 40, "Timer", "min:sec");

    
    Serial.println("Done loading debug");
    
    drawingWrapper.fillScreen(CMXG_BL_DATUM);
    drawingWrapper.setTextSize(1);
    for (size_t i = 0; i < DebugPage.buttonsSize; ++i) DebugPage.buttons[i].draw();
    DebugPage.flowRate->draw();
    // DebugPage.timerComponent->draw(); // todo enable timer component


    Driver::touchscreen_register_on_press(DebugPage.ts_onPress);
    Driver::touchscreen_register_on_release(DebugPage.ts_onRelease);
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
    uint16_t x, y;
    Calibration.translateFromRaw(x, y);
    for (size_t i = 0; i < DebugPage.buttonsSize; ++i) {
        DebugPage.buttons[i].performAction(x, y, 0, true);
    }
    DebugPage.flowRate->performAction(x, y, 0, true);

    Driver::tft.setCursor(10, 10);
    Driver::tft.setTextSize(2);
    Driver::tft.setTextColor(TFT_CYAN);
    Driver::tft.println("Bioaerosol Collector");
    Driver::tft.setCursor(10, 80);
    Driver::tft.setTextSize(2);
    Driver::tft.setTextColor(TFT_WHITE);
    // Driver::tft.println("300 ul/min");
    // Driver::tft.setTextSize(1);
    // Driver::tft.setCursor(10, 110);
    // Driver::tft.println("Rate");
    
    dev_println("DEBUG on press handler");
}

void _Debug::ts_onRelease()
{
    uint16_t x, y;
    Calibration.translateFromRaw(x, y);

    drawingWrapper.setTextSize(1);
    for (size_t i = 0; i < DebugPage.buttonsSize; ++i) {
        DebugPage.buttons[i].performAction(x, y, 0, false);     // todo fix this!!
    }

    if (DebugPage.flowRate) DebugPage.flowRate->performAction(x, y, 0, false);
    
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

    delete DebugPage.flowRate;
    DebugPage.flowRate = nullptr;

    delete DebugPage.timerComponent;
    DebugPage.timerComponent = nullptr;
}

int32_t _Debug::flowRateValue = 300;
int32_t _Debug::timerValue = 15 * 60 * 1000;

_Debug DebugPage;


