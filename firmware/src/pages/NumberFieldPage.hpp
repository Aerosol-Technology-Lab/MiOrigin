#pragma once

#include "../graphics/NumberFieldDefs.hpp"
#include "../pagesystem/page.h"
#include "../graphics/Button.hpp"
#include <stdint.h>

#define PAGES_NUMBERFIELDPAGE_NAME "numfield"

class _NumberFieldPage
{
private:
    NumberFieldDefs::Props_t *props;

    const size_t numButtons = 12;
    Button *buttons[12] = { 0 };

public:
    _NumberFieldPage();

    static void draw();

    static void onStart(void *);
    static void onLoad(void *, void *);
    static void onExit();

    static void generatePage(Page_t &page);
    static Page_t generatePage();

    static void ts_onPress();
    static void ts_onRelease();
    // static void generatePage(Page_t &page)


private:
    static void drawValue();
};

extern _NumberFieldPage NumberFieldPage;
