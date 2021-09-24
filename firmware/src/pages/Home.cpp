#include "Home.hpp"

#include "Calibration.h"
#include "../driver/miclone.hpp"
#include "../driver/touchscreen.h"
#include "utils.h"

_Home::_Home()
{
    pageArgs = nullptr;
    flowRateValue = 300;
    timerMinValue = 15;
    timerSecValue = 0;
    
    // assign the functions
    button_start = reinterpret_cast<Button *>(buttons);
    button_stop = button_start + 1;
    button_initialize = button_stop + 1;

    new (button_start) Button(drawingWrapper, "START", 360, 10, 100, 100);
    button_start->setButtonSize(2);
    button_start->setTextColor(CMXG_BLACK);
    button_start->setButtonColor(CMXG_GREEN);
    button_start->onPress = [](uint16_t x, uint16_t y, uint8_t z) {
    };
    button_start->onHoverEnter = [](uint16_t x, uint16_t y, uint8_t z) {
    };
    button_start->onHoverExit = [](uint16_t x, uint16_t y, uint8_t z) {
    };
    button_start->onRelease = [](uint16_t x, uint16_t y, uint8_t z) {
        uint32_t time = (Home.timerMinValue * 60 + Home.timerSecValue) * 1000;
        Driver::miclone_start(Home.flowRateValue, time);
    };

    new (button_stop) Button(drawingWrapper, "STOP", 360, 120, 100, 100);
    button_stop->setButtonSize(2);
    button_stop->setTextColor(CMXG_WHITE);
    button_stop->setButtonColor(CMXG_RED);
    button_stop->onPress = [](uint16_t x, uint16_t y, uint8_t z) {
    };
    button_stop->onHoverEnter = [](uint16_t x, uint16_t y, uint8_t z) {
    };
    button_stop->onHoverExit = [](uint16_t x, uint16_t y, uint8_t z) {
    };
    button_stop->onRelease = [](uint16_t x, uint16_t y, uint8_t z) {
        Driver::miclone_stop();
    };

    new (button_initialize) Button(drawingWrapper, "Initialize", 360, 230, 100, 50);
    button_initialize->setTextColor(CMXG_BLACK);
    button_initialize->setButtonColor(CMXG_CYAN);
    button_initialize->onPress = [](uint16_t x, uint16_t y, uint8_t z) {
    };
    button_initialize->onHoverEnter = [](uint16_t x, uint16_t y, uint8_t z) {
    };
    button_initialize->onHoverExit = [](uint16_t x, uint16_t y, uint8_t z) {
    };
    button_initialize->onRelease = [](uint16_t x, uint16_t y, uint8_t z) {
        // PageSystem_findSwitch(&devicePageManager, CALIBRATION_PAGE_NAME, (void *) 0);
        // todo: implement this
    };

    /* Flow Rate Timer */
    new (&component_flowRate) NumberFieldComponent(drawingWrapper, &Home.flowRateValue, 20, 80, 120, 40, "Flow Rate", "ul/min");
    component_flowRate.setReturnPageName(HOME_PAGE_NAME, 10);
    component_flowRate.setProperty(
        [](void *_props, int8_t c) -> void
        {
            if (c < 0)
            {
                Home.flowRateValue /= 10;
            }
            else if (c < 10)
            {
                Home.flowRateValue = Home.flowRateValue * 10 + c;
            }
            else
            {
                // do nothing
            }

            if (Home.flowRateValue > 9999 || Home.flowRateValue < 0)
                Home.flowRateValue = 9999;
        },
        [](void *_props, char *buffer, size_t size) -> void
        {
            char numBuff[16];
            sprintf(numBuff, "%d", Home.flowRateValue);

            strncpy(buffer, numBuff, std::min(sizeof(numBuff), size));
        },
        [](void *_props) -> void {
            
            Home.flowRateValue = 0;
        }
    );

    
    /* Minute Timer Component */
    new (&component_timerMinComponent) NumberFieldComponent(drawingWrapper, &Home.timerMinValue, 20, 160, 80, 40, "Minutes", "min");
    component_timerMinComponent.setReturnPageName(HOME_PAGE_NAME, 10);
    component_timerMinComponent.setProperty(
        [](void *_props, int8_t c) -> void {

            if (c < 0) {
                Home.timerMinValue /= 10;
            }
            else if (c < 10) {
                Home.timerMinValue = Home.timerMinValue * 10 + c;
            }
            else {
                // do nothing
            }

            if (Home.timerMinValue > 999999 || Home.timerMinValue < 0) Home.timerMinValue = 999999;
        },
        [](void *_props, char *buffer, size_t size) -> void {

            char numBuff[16];
            sprintf(numBuff, "%d", Home.timerMinValue);

            strncpy(buffer, numBuff, std::min(sizeof(numBuff), size));
        },
        [](void *_props) -> void {
            
            Home.timerMinValue = 0;
        }
        );

    new (&component_timerSecComponent) NumberFieldComponent(drawingWrapper, &Home.timerSecValue, 105, 160, 44, 40, "Sec", "sec");
    component_timerSecComponent.setReturnPageName(HOME_PAGE_NAME, 10);
    component_timerSecComponent.setProperty(
        [](void *_props, int8_t c) -> void {

            if (c < 0) {
                Home.timerSecValue /= 10;
            }
            else if (c < 10) {
                Home.timerSecValue = Home.timerSecValue * 10 + c;
            }
            else {
                // do nothing
            }

            // bounds check
            if (Home.timerSecValue < 0)       Home.timerSecValue = 0;
            else if (Home.timerSecValue > 60) Home.timerSecValue = 60;
        },
        [](void *_props, char *buffer, size_t size) -> void {

            char numBuff[16];
            sprintf(numBuff, "%d", Home.timerSecValue);
            strncpy(buffer, numBuff, std::min(sizeof(numBuff), size));
        },
        [](void *_props) -> void {
            
            Home.timerSecValue = 0;
        }
        );

    new (&sampleWasteToggle) Toggle(drawingWrapper, 48, 248 , 25, 14, CMXG_CYAN);
}

void _Home::onStart(void *pageArgs)
{
    Home.pageArgs = pageArgs;
}

void _Home::onLoad(void *, void *args)
{
    Serial.println("-> Switched to home page");
    
    if      (Home.flowRateValue > HOME_MAX_FLOW_RATE) Home.flowRateValue = HOME_MAX_FLOW_RATE;
    else if (Home.flowRateValue < HOME_MIN_FLOW_RATE) Home.flowRateValue = HOME_MIN_FLOW_RATE;

    drawingWrapper.fillScreen(CMXG_BL_DATUM);
    // Driver::tft.setCursor(10, 10);
    // Driver::tft.setTextSize(2);
    // Driver::tft.setTextColor(TFT_CYAN);
    // Driver::tft.println("Bioaerosol Collector");
    // Driver::tft.setCursor(10, 80);
    // Driver::tft.setTextSize(2);
    // Driver::tft.setTextColor(TFT_WHITE);

    drawingWrapper.setTextColor(CMXG_YELLOW, CMXG_YELLOW);
    drawingWrapper.setTextFont(2);
    drawingWrapper.setTextSize(2);
    drawingWrapper.setTextDatum(CMXG_TL_DATUM);
    drawingWrapper.drawString("Bioaerosol Collector", 10, 10);

    drawingWrapper.setTextSize(1);
    drawingWrapper.setTextDatum(CMXG_CL_DATUM);
    drawingWrapper.setTextColor(CMXG_WHITE, CMXG_WHITE);
    drawingWrapper.drawString("Sample / Waste", 80, 248);

    drawingWrapper.setTextSize(1);
    Home.button_start->draw();
    Home.button_stop->draw();
    Home.button_initialize->draw();
    Home.component_flowRate.draw();
    Home.component_timerMinComponent.draw();
    Home.component_timerSecComponent.draw();
    Home.sampleWasteToggle.draw();

    Driver::touchscreen_register_on_press(Home.ts_onPress);
    Driver::touchscreen_register_on_release(Home.ts_onRelease);
}

void _Home::onExit()
{
    Driver::touchscreen_register_on_press(nullptr);
    Driver::touchscreen_register_on_release(nullptr);
}

void _Home::generatePage(Page_t &page)
{
    strncpy(page.name, HOME_PAGE_NAME, PAGE_NAME_SIZE);
    page.params = nullptr;
    page.onStart = Home.onStart;
    page.onLoad = Home.onLoad;
    page.onExit = Home.onExit;
}

Page_t _Home::generatePage()
{
    Page_t page;
    generatePage(page);
    return page;
}

void _Home::ts_onPress()
{
    uint16_t x, y;
    Calibration.translateFromRaw(x, y);
    
    Home.button_start->performAction(x, y, 0, true);
    Home.button_stop->performAction(x, y, 0, true);
    Home.button_initialize->performAction(x, y, 0, true);
    Home.component_flowRate.performAction(x, y, 0, true);
    Home.component_timerMinComponent.performAction(x, y, 0, true);
    Home.component_timerSecComponent.performAction(x, y, 0, true);
    Home.sampleWasteToggle.performAction(x, y, 0, true);

    dev_println("MAIN on press handler");
}

void _Home::ts_onRelease()
{
    uint16_t x, y;
    Calibration.translateFromRaw(x, y);
    
    Home.button_start->performAction(x, y, 0, false);
    Home.button_stop->performAction(x, y, 0, false);
    Home.button_initialize->performAction(x, y, 0, false);
    Home.component_flowRate.performAction(x, y, 0, false);
    Home.component_timerMinComponent.performAction(x, y, 0, false);
    Home.component_timerSecComponent.performAction(x, y, 0, false);
    Home.sampleWasteToggle.performAction(x, y, 0, false);

    dev_println("MAIN on release handler");
}

_Home Home;
