#include "NumberFieldPage.hpp"
#include "Calibration.h"
#include "AppPageConfig.hpp"
#include "../driver/touchscreen.h"

_NumberFieldPage::_NumberFieldPage()
{
    props = nullptr;
}

void _NumberFieldPage::onStart(void *_)
{ }

void _NumberFieldPage::onLoad(void *, void *args)
{
    NumberFieldPage.props = reinterpret_cast<_NumberFieldPage::Props_t *>(args);
    drawingWrapper.fillScreen(CMXG_BLACK);

    Driver::touchscreen_register_on_press(ts_onPress);
    Driver::touchscreen_register_on_release(ts_onRelease);
}

void _NumberFieldPage::onExit()
{
    Driver::touchscreen_register_on_press(nullptr);
    Driver::touchscreen_register_on_release(nullptr);

    if (NumberFieldPage.props) {
        delete NumberFieldPage.props;
        NumberFieldPage.props = nullptr;
    }
}

void _NumberFieldPage::generatePage(Page_t &page)
{
    strncpy(page.name, PAGES_NUMBERFIELDPAGE_NAME, PAGE_NAME_SIZE);
    page.params = nullptr;
    page.onStart = onStart;
    page.onLoad = onLoad;
    page.onExit = onExit;
}

Page_t _NumberFieldPage::generatePage()
{
    Page_t page;
    generatePage(page);
    return page;
}

void _NumberFieldPage::ts_onPress()
{
    uint16_t x, y;
    Calibration.translateFromRaw(x, y);
}

void _NumberFieldPage::ts_onRelease()
{
    uint16_t x, y;
    Calibration.translateFromRaw(x, y);
}

Page_t _NumberFieldPage::page;
_NumberFieldPage NumberFieldPage;
