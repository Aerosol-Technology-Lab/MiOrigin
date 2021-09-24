#pragma once

#include "AppPageConfig.hpp"
#include <memory>

#define DEBUG_PAGE_NAME "debug-page"

#define DEBUG_MAX_FLOW_RATE 1000
#define DEBUG_MIN_FLOW_RATE   50

#define DEBUG_NUM_BUTTONS      3

class _Debug
{
private:
    void *pageArgs;
    std::shared_ptr<Button> buttons[DEBUG_NUM_BUTTONS];
    std::shared_ptr<NumberFieldComponent> flowRate;
    std::shared_ptr<NumberFieldComponent> timerMinComponent;
    std::shared_ptr<NumberFieldComponent> timerSecComponent;
    static int32_t flowRateValue;
    static int32_t timerMinValue;
    static int32_t timerSecValue;

public:
    _Debug();

    static void onStart(void *);
    static void onLoad(void *, void *);
    static void onExit();

    static void generatePage(Page_t &page);
    static Page_t generatePage();

    static void ts_onPress();
    static void ts_onRelease();
};

extern _Debug DebugPage;
