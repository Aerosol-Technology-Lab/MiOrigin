#pragma once

#include "AppPageConfig.hpp"

#define DEBUG_PAGE_NAME "debug-page"

class _Debug
{
private:
    void *pageArgs;
    Button *buttons;
    size_t buttonsSize = 3;
    NumberFieldComponent *flowRate;
    NumberFieldComponent *timerComponent;
    static int32_t flowRateValue;
    static int32_t timerValue;

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
