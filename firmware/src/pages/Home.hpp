#pragma once

#include "../graphics/Toggle.hpp"
#include "AppPageConfig.hpp"
#include <memory>

#define HOME_PAGE_NAME "home-page"

#define HOME_MAX_FLOW_RATE 1000
#define HOME_MIN_FLOW_RATE  100

class _Home
{
private:
    void *pageArgs;
    NumberFieldComponent component_flowRate;
    NumberFieldComponent component_timerMinComponent;
    NumberFieldComponent component_timerSecComponent;

    // buttons
    uint8_t buttons[3 * sizeof(Button)];
    Button *button_start;
    Button *button_stop;
    Button *button_initialize;

    // toggles
#ifdef ENABLE_SAMPLE_WASTE_TOGGLE
    Toggle sampleWasteToggle;
#endif

    int32_t flowRateValue;
    int32_t timerMinValue;
    int32_t timerSecValue;

public:
    _Home();

    static void onStart(void *);
    static void onLoad(void *, void *);
    static void onExit();

    static void generatePage(Page_t &page);
    static Page_t generatePage();

    static void ts_onPress();
    static void ts_onRelease();
};

extern _Home Home;

