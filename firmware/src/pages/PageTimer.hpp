#pragma once

#include "../graphics/Button.hpp"
#include "AppPageConfig.hpp"
#include <memory>

#define TIMER_PAGE_NAME "timer-page"

class _PageTimer
{
private:
    void *pageArgs;

    Button buttonStop;

public:
    _PageTimer();

    static void onStart(void *);
    static void onLoad(void *, void *);
    static void onExit();

    static void generatePage(Page_t &page);
    static Page_t generatePage();

    static void ts_onPress();
    static void ts_onRelease();
};

extern _PageTimer PageTimer;
