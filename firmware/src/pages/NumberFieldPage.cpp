#include "NumberFieldPage.hpp"
#include "../graphics/NumberFieldDefs.hpp"
#include "Calibration.h"
#include "AppPageConfig.hpp"
#include "../driver/touchscreen.h"
#include "../graphics/Button.hpp"
#include <assert.h>

_NumberFieldPage::_NumberFieldPage()
{
    props = nullptr;
}

void _NumberFieldPage::onStart(void *_)
{ }

void _NumberFieldPage::onLoad(void *, void *args)
{
    #ifdef SAFE_CODE
    assert(args != nullptr);
    #endif // SAFE_CODE

    Serial.println("-> Stage 1");

    NumberFieldPage.props = reinterpret_cast<NumberFieldDefs::Props_t *>(args);
    drawingWrapper.fillScreen(CMXG_BLACK);

    // create buttons
    NumberFieldPage.buttons = reinterpret_cast<Button *>(malloc(sizeof(Button *) * NumberFieldPage.numButtons));
    // assert(false && "There is no clean up for this and this has not been initialized.");

    Serial.println("-> Stage 2");


    const uint16_t x = 200;
    const uint16_t y = 10;
    const uint16_t width = 40;
    const uint16_t gap = 5;
    for (size_t i = 1; i < 10; ++i) {

        char buffer[12];
        sprintf(buffer, "%d", i);
        uint16_t nX = x + ((i - 1) % 3) * (width + gap);
        uint16_t nY = y + ((i - 1) / 3) * (width + gap);
        new (NumberFieldPage.buttons + i) Button(drawingWrapper, buffer, nX, nY, gap, gap);
        NumberFieldPage.buttons[i].setTextColor(CMXG_WHITE);
        NumberFieldPage.buttons[i].setButtonColor(CMXG_BLUE);
    }

    Serial.println("-> Stage 3");


    // I know this is ugly but this removes complex data passing
    #define NUMBERFIELDPAGE_GENERATE_BUTTONS(i)     \
    NumberFieldPage.buttons[i].onPress = [](uint16_t x, uint16_t y, uint8_t z) {            \
    };                                                                                      \
    NumberFieldPage.buttons[i].onHoverEnter = [](uint16_t x, uint16_t y, uint8_t z) {       \
    };                                                                                      \
    NumberFieldPage.buttons[i].onHoverExit = [](uint16_t x, uint16_t y, uint8_t z) {        \
    };                                                                                      \
    NumberFieldPage.buttons[i].onRelease = [](uint16_t x, uint16_t y, uint8_t z) {          \
        NumberFieldPage.props->changeValue(&NumberFieldPage.props, i);                                           \
    };

    Serial.println("-> Stage 4");


    NUMBERFIELDPAGE_GENERATE_BUTTONS(1);
    NUMBERFIELDPAGE_GENERATE_BUTTONS(2);
    NUMBERFIELDPAGE_GENERATE_BUTTONS(3);
    NUMBERFIELDPAGE_GENERATE_BUTTONS(4);
    NUMBERFIELDPAGE_GENERATE_BUTTONS(5);
    NUMBERFIELDPAGE_GENERATE_BUTTONS(6);
    NUMBERFIELDPAGE_GENERATE_BUTTONS(7);
    NUMBERFIELDPAGE_GENERATE_BUTTONS(8);
    NUMBERFIELDPAGE_GENERATE_BUTTONS(9);
    
    #undef NUMBERFIELDPAGE_GENERATE_BUTTONS

    // 0 button
    {
        const char *buffer = "0";
        uint16_t nX = x + (1) * (width + gap);
        uint16_t nY = y + (2) * (width + gap);
        new (NumberFieldPage.buttons + 10) Button(drawingWrapper, buffer, nX, nY, gap, gap);
        NumberFieldPage.buttons[0].setTextColor(CMXG_WHITE);
        NumberFieldPage.buttons[0].setButtonColor(CMXG_RED);
        NumberFieldPage.buttons[0].onPress = [](uint16_t x, uint16_t y, uint8_t z) {            \
        };                                                                                      \
        NumberFieldPage.buttons[0].onHoverEnter = [](uint16_t x, uint16_t y, uint8_t z) {       \
        };                                                                                      \
        NumberFieldPage.buttons[0].onHoverExit = [](uint16_t x, uint16_t y, uint8_t z) {        \
        };                                                                                      \
        NumberFieldPage.buttons[0].onRelease = [](uint16_t x, uint16_t y, uint8_t z) {          \
        NumberFieldPage.props->changeValue(&NumberFieldPage.props, 0);                                           \
        };

    }

    // delete button
    {
        const char *buffer = "X";
        uint16_t nX = x;
        uint16_t nY = y + (2) * (width + gap);
        new (NumberFieldPage.buttons + 10) Button(drawingWrapper, buffer, nX, nY, gap, gap);
        NumberFieldPage.buttons[10].setTextColor(CMXG_WHITE);
        NumberFieldPage.buttons[10].setButtonColor(CMXG_RED);
        NumberFieldPage.buttons[10].onPress = [](uint16_t x, uint16_t y, uint8_t z) {            \
        };                                                                                      \
        NumberFieldPage.buttons[10].onHoverEnter = [](uint16_t x, uint16_t y, uint8_t z) {       \
        };                                                                                      \
        NumberFieldPage.buttons[10].onHoverExit = [](uint16_t x, uint16_t y, uint8_t z) {        \
        };                                                                                      \
        NumberFieldPage.buttons[10].onRelease = [](uint16_t x, uint16_t y, uint8_t z) {          \
            NumberFieldPage.props->changeValue(&NumberFieldPage.props, -1);                                           \
        };
    }

    // enter button
    {
        const char *buffer = "OK";
        uint16_t nX = x;
        uint16_t nY = y + (2) * (width + gap);
        new (NumberFieldPage.buttons + 11) Button(drawingWrapper, buffer, nX, nY, gap, gap);
        NumberFieldPage.buttons[11].setTextColor(CMXG_WHITE);
        NumberFieldPage.buttons[11].setButtonColor(CMXG_RED);
        NumberFieldPage.buttons[11].onPress = [](uint16_t x, uint16_t y, uint8_t z) {            \
        };                                                                                      \
        NumberFieldPage.buttons[11].onHoverEnter = [](uint16_t x, uint16_t y, uint8_t z) {       \
        };                                                                                      \
        NumberFieldPage.buttons[11].onHoverExit = [](uint16_t x, uint16_t y, uint8_t z) {        \
        };                                                                                      \
        NumberFieldPage.buttons[11].onRelease = [](uint16_t x, uint16_t y, uint8_t z) {          \
            // todo this might be problamatic because props is private
            PageSystem_findSwitch(&devicePageManager, NumberFieldPage.props->returnPageName, NumberFieldPage.props->returnPageArgs);
        };
    }
    Serial.println("-> Stage 5");

    drawingWrapper.fillScreen(CMXG_BLACK);
    
    delay(250);
    // draw
    // for (size_t i = 0; i < NumberFieldPage.numButtons; ++i) {
    for (size_t i = 1; i < 9; ++i) {
        delay(250);
        Serial.printf("Drawing button %d\n", i);
        delay(250);
        NumberFieldPage.buttons[i].draw();
    }

    Driver::touchscreen_register_on_press(ts_onPress);
    Driver::touchscreen_register_on_release(ts_onRelease);
}

void _NumberFieldPage::onExit()
{
    Driver::touchscreen_register_on_press(nullptr);
    Driver::touchscreen_register_on_release(nullptr);
    
    // delete buttons
    #ifdef SAFE_CODE
    assert(NumberFieldPage.buttons && "The buttons should not be null. Logic Error");
    #endif
    for (size_t i = 0; i < NumberFieldPage.numButtons; ++i) {
        NumberFieldPage.buttons[i].~Button();
    }
    free(NumberFieldPage.buttons);
    NumberFieldPage.buttons = nullptr;

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

        for (size_t i = 0; i < NumberFieldPage.numButtons; ++i) {
        NumberFieldPage.buttons[i].performAction(x, y, 0, true);
        NumberFieldPage.buttons[i].draw();
    }
}

void _NumberFieldPage::ts_onRelease()
{
    uint16_t x, y;
    Calibration.translateFromRaw(x, y);

    for (size_t i = 0; i < NumberFieldPage.numButtons; ++i) {
        NumberFieldPage.buttons[i].performAction(x, y, 0, false);
        NumberFieldPage.buttons[i].draw();
    }
}

_NumberFieldPage NumberFieldPage;
