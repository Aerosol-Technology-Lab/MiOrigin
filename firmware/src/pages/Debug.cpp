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
    for (auto *&button : buttons) {
        button = nullptr;
    }
    // buttonsSize;
}

void _Debug::onStart(void *pageArgs)
{
    DebugPage.pageArgs = pageArgs;
}

void _Debug::onLoad(void *, void *args) {

    size_t counter = 0;

    Serial.println("Not done loading debug");

    // limits possible flow rates
    if      (DebugPage.flowRateValue > DEBUG_MAX_FLOW_RATE) DebugPage.flowRateValue = DEBUG_MAX_FLOW_RATE;
    else if (DebugPage.flowRateValue < DEBUG_MIN_FLOW_RATE) DebugPage.flowRateValue = DEBUG_MIN_FLOW_RATE;

    // placement new
    DebugPage.buttons[counter] = new Button(drawingWrapper, "START", 360, 10, 100, 100);
    DebugPage.buttons[counter]->setTextColor(CMXG_WHITE);
    DebugPage.buttons[counter]->setButtonColor(CMXG_GREEN);
    DebugPage.buttons[counter]->onPress = [](uint16_t x, uint16_t y, uint8_t z) {
    };
    DebugPage.buttons[counter]->onHoverEnter = [](uint16_t x, uint16_t y, uint8_t z) {
    };
    DebugPage.buttons[counter]->onHoverExit = [](uint16_t x, uint16_t y, uint8_t z) {
    };
    DebugPage.buttons[counter]->onRelease = [](uint16_t x, uint16_t y, uint8_t z) {
        Driver::miclone_start(DebugPage.flowRateValue, DebugPage.timerValue);
    };
    ++counter;
    
    DebugPage.buttons[counter] = new Button(drawingWrapper, "STOP", 360, 120, 100, 100);
    DebugPage.buttons[counter]->setTextColor(CMXG_WHITE);
    DebugPage.buttons[counter]->setButtonColor(CMXG_RED);
        DebugPage.buttons[counter]->onPress = [](uint16_t x, uint16_t y, uint8_t z) {
    };
    DebugPage.buttons[counter]->onHoverEnter = [](uint16_t x, uint16_t y, uint8_t z) {
    };
    DebugPage.buttons[counter]->onHoverExit = [](uint16_t x, uint16_t y, uint8_t z) {
    };
    DebugPage.buttons[counter]->onRelease = [](uint16_t x, uint16_t y, uint8_t z) {
        Driver::miclone_stop();
    };
    ++counter;

    // new (DebugPage.buttons + counter) Button(drawingWrapper, "CALIBRATE", 360, 230, 100, 50);
    DebugPage.buttons[counter] = new Button(drawingWrapper, "Initialize", 360, 230, 100, 50);
    DebugPage.buttons[counter]->setTextColor(CMXG_BLACK);
    DebugPage.buttons[counter]->setButtonColor(CMXG_CYAN);
        DebugPage.buttons[counter]->onPress = [](uint16_t x, uint16_t y, uint8_t z) {
    };
    DebugPage.buttons[counter]->onHoverEnter = [](uint16_t x, uint16_t y, uint8_t z) {
    };
    DebugPage.buttons[counter]->onHoverExit = [](uint16_t x, uint16_t y, uint8_t z) {
    };
    DebugPage.buttons[counter]->onRelease = [](uint16_t x, uint16_t y, uint8_t z) {
        PageSystem_findSwitch(&devicePageManager, CALIBRATION_PAGE_NAME, (void *) 0);
    };
    ++counter;

    /* Initialize Flow Rate Timer */
    DebugPage.flowRate = new NumberFieldComponent(drawingWrapper, &(DebugPage.flowRateValue), 20, 80, 250, 40, "Flow Rate", "ul/min");
    const char *returnPageNameFlowRate = "debug-page";
    DebugPage.flowRate->setReturnPageName(returnPageNameFlowRate, strlen(returnPageNameFlowRate));
    DebugPage.flowRate->setProperty(
        [](void *_props, int8_t c) -> void {

            NumberFieldDefs::Props_t &props = *reinterpret_cast<NumberFieldDefs::Props_t*>(_props);
            int32_t &flowRate = **reinterpret_cast<int32_t**>(props.value);     // why does this happen???

            if (c < 0) {
                flowRate /= 10;
            }
            else if (c < 10) {
                flowRate = flowRate * 10 + c;
            }
            else {
                // do nothing
            }

            if (flowRate > 999999 || flowRate < 0) flowRate = 999999;
        },
        [](void *_props, char *buffer, size_t size) -> void {

            NumberFieldDefs::Props_t &props = *reinterpret_cast<NumberFieldDefs::Props_t*>(_props);
            int32_t &flowRate = *reinterpret_cast<int32_t*>(props.value);

            char numBuff[16];
            sprintf(numBuff, "%d", flowRate);

            strncpy(buffer, numBuff, std::min(sizeof(numBuff), size));
        }
        );
    
    DebugPage.timerComponent = new NumberFieldComponent(drawingWrapper, &(DebugPage.timerValue), 20, 160, 250, 40, "Timer", "min:sec");
    const char *returnPageNameTimer = "debug-page\0";
    DebugPage.timerComponent->setReturnPageName(returnPageNameTimer, strlen(returnPageNameTimer));
    DebugPage.timerComponent->setProperty(
        [](void *_props, int8_t c) -> void {

            NumberFieldDefs::Props_t &props = *reinterpret_cast<NumberFieldDefs::Props_t*>(_props);
            int32_t &timer = **reinterpret_cast<int32_t**>(props.value);     // why does this happen???

            char buffer[12];
            convert_MS2HMSF_format(buffer, sizeof(buffer) / sizeof(buffer[0]), timer);

            // shift everything to the right, hard coded for performance
            if (c < 0) {

                buffer[7] = buffer[6];
                buffer[6] = buffer[4];
                buffer[4] = buffer[3];
                buffer[3] = buffer[1];
                buffer[1] = buffer[0];
                buffer[0] = '0';
            }
            else if (c <= 9) {

                buffer[0] = buffer[1];
                buffer[1] = buffer[3];
                buffer[3] = buffer[4];
                buffer[4] = buffer[6];
                buffer[6] = buffer[7];
                buffer[7] = '0' + c;
            }

            timer = atoi(buffer) * 60 * 60 * 1000 + atoi(buffer + 3) * 60 * 1000 + atoi(buffer + 6) * 1000;
        },
        [](void *_props, char *buffer, size_t size) -> void {

            NumberFieldDefs::Props_t &props = *reinterpret_cast<NumberFieldDefs::Props_t*>(_props);
            int32_t &timer = *reinterpret_cast<int32_t*>(props.value);

            char numBuff[16];
            // sprintf(numBuff, "%d", timer);
            convert_MS2HMSF_format(numBuff, sizeof(numBuff) / sizeof(numBuff[0]), timer);

            strncpy(buffer, numBuff, std::min(sizeof(numBuff), size));
        }
        );


    Driver::tft.setCursor(10, 10);
    Driver::tft.setTextSize(2);
    Driver::tft.setTextColor(TFT_CYAN);
    Driver::tft.println("Bioaerosol Collector");
    Driver::tft.setCursor(10, 80);
    Driver::tft.setTextSize(2);
    Driver::tft.setTextColor(TFT_WHITE);

    
    drawingWrapper.fillScreen(CMXG_BL_DATUM);
    drawingWrapper.setTextSize(1);
    for (size_t i = 0; i < DEBUG_NUM_BUTTONS; ++i) DebugPage.buttons[i]->draw();
    DebugPage.flowRate->draw();
    DebugPage.timerComponent->draw();
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
    if (DebugPage.buttons) {

        for (size_t i = 0; i < DEBUG_NUM_BUTTONS; ++i) {
            DebugPage.buttons[i]->performAction(x, y, 0, true);
        }
    }
    if (DebugPage.flowRate) DebugPage.flowRate->performAction(x, y, 0, true);
    if (DebugPage.timerComponent) DebugPage.timerComponent->performAction(x, y, 0, false);
    
    dev_println("DEBUG on press handler");
}

void _Debug::ts_onRelease()
{
    uint16_t x, y;
    Calibration.translateFromRaw(x, y);

    drawingWrapper.setTextSize(1);
    if (DebugPage.buttons) {

        for (size_t i = 0; i < DEBUG_NUM_BUTTONS; ++i) {
            DebugPage.buttons[i]->performAction(x, y, 0, false);     // todo fix this!!
        }
    }

    if (DebugPage.flowRate) DebugPage.flowRate->performAction(x, y, 0, false);
    if (DebugPage.timerComponent) DebugPage.timerComponent->performAction(x, y, 0, false);
    
    dev_println("DEBUG on release handler");
}

void _Debug::onExit()
{
    Driver::touchscreen_register_on_press(nullptr);
    Driver::touchscreen_register_on_release(nullptr);
    
    for (Button *&button : DebugPage.buttons) {

        delete button;
        button = nullptr;
    }

    delete DebugPage.flowRate;
    DebugPage.flowRate = nullptr;

    delete DebugPage.timerComponent;
    DebugPage.timerComponent = nullptr;
}

int32_t _Debug::flowRateValue = 300;
int32_t _Debug::timerValue = 15 * 60 * 1000;

_Debug DebugPage;


