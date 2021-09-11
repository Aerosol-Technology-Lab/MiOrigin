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

void _NumberFieldPage::draw()
{
        
    drawValue();
    for (size_t i = 0; i < sizeof(buttons) / sizeof(buttons[0]); ++i) {
        Serial.printf("Drawing button %d\n", i);
        NumberFieldPage.buttons[i]->draw();
    }
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
    
    // assert(false && "There is no clean up for this and this has not been initialized.");

    Serial.println("-> Stage 2");


    const uint16_t x = 250;
    const uint16_t y = 10;
    const uint16_t width = 68;
    const uint16_t gap = 8;
    for (size_t i = 1; i < 10; ++i) {

        char buffer[12];
        sprintf(buffer, "%d", i);
        uint16_t nX = x + ((i - 1) % 3) * (width + gap);
        uint16_t nY = y + ((i - 1) / 3) * (width + gap);
        NumberFieldPage.buttons[i] = new Button(drawingWrapper, buffer, nX, nY, width, width);
    }

    Serial.println("-> Stage 3");


    // I know this is ugly but this removes complex data passing
    #define NUMBERFIELDPAGE_GENERATE_BUTTONS(i) \
    NumberFieldPage.buttons[i]->setTextColor(CMXG_BLACK);                                   \
    NumberFieldPage.buttons[i]->setButtonColor(CMXG_CYAN);                                  \
    NumberFieldPage.buttons[i]->setButtonSize(3);                                           \
    NumberFieldPage.buttons[i]->onPress = [](uint16_t x, uint16_t y, uint8_t z) {           \
    };                                                                                      \
    NumberFieldPage.buttons[i]->onHoverEnter = [](uint16_t x, uint16_t y, uint8_t z) {      \
    };                                                                                      \
    NumberFieldPage.buttons[i]->onHoverExit = [](uint16_t x, uint16_t y, uint8_t z) {       \
    };                                                                                      \
    NumberFieldPage.buttons[i]->onRelease = [](uint16_t x, uint16_t y, uint8_t z) {         \
        NumberFieldPage.props->changeValue(&NumberFieldPage.props, i);                      \
        NumberFieldPage.draw();                                                             \
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
    

    // 0 button
    {
        const char *buffer = "0";
        uint16_t nX = x + (1) * (width + gap);
        uint16_t nY = y + (3) * (width + gap);
        NumberFieldPage.buttons[0] = new Button(drawingWrapper, buffer, nX, nY, width, width);
        NUMBERFIELDPAGE_GENERATE_BUTTONS(0);
    }
    #undef NUMBERFIELDPAGE_GENERATE_BUTTONS

    // delete button
    {
        const char *buffer = "X";
        uint16_t nX = x;
        uint16_t nY = y + (3) * (width + gap);
        NumberFieldPage.buttons[10] = new Button(drawingWrapper, buffer, nX, nY, width, width);
        NumberFieldPage.buttons[10]->setButtonSize(3);
        NumberFieldPage.buttons[10]->setTextColor(CMXG_WHITE);
        NumberFieldPage.buttons[10]->setButtonColor(CMXG_RED);
        NumberFieldPage.buttons[10]->onPress = [](uint16_t x, uint16_t y, uint8_t z) {            
        };                                                                                      
        NumberFieldPage.buttons[10]->onHoverEnter = [](uint16_t x, uint16_t y, uint8_t z) {       
        };                                                                                      
        NumberFieldPage.buttons[10]->onHoverExit = [](uint16_t x, uint16_t y, uint8_t z) {       
        };                                                                                      
        NumberFieldPage.buttons[10]->onRelease = [](uint16_t x, uint16_t y, uint8_t z) {        
            NumberFieldPage.props->changeValue(&NumberFieldPage.props, -1);
            NumberFieldPage.draw();                                                             \
        };
    }

    // enter button
    {
        const char *buffer = "OK";
        uint16_t nX = x + ((3 - 1) % 3) * (width + gap);
        uint16_t nY = y + (3) * (width + gap);
        NumberFieldPage.buttons[11] = new Button(drawingWrapper, buffer, nX, nY, width, width);
        NumberFieldPage.buttons[11]->setButtonSize(3);
        NumberFieldPage.buttons[11]->setTextColor(CMXG_BLACK);
        NumberFieldPage.buttons[11]->setButtonColor(CMXG_GREEN);
        NumberFieldPage.buttons[11]->onPress = [](uint16_t x, uint16_t y, uint8_t z) {            
        };                                                                                      
        NumberFieldPage.buttons[11]->onHoverEnter = [](uint16_t x, uint16_t y, uint8_t z) {     
        };                                                                                      
        NumberFieldPage.buttons[11]->onHoverExit = [](uint16_t x, uint16_t y, uint8_t z) {      
        };                                                                                      
        NumberFieldPage.buttons[11]->onRelease = [](uint16_t x, uint16_t y, uint8_t z) {        
            // todo this might be problamatic because props is private
            Driver::postDigitizerArgs = new void*[3];
            Driver::postDigitizerArgs[0] = &devicePageManager;
            Driver::postDigitizerArgs[1] = NumberFieldPage.props->returnPageName;
            Driver::postDigitizerArgs[2] = NumberFieldPage.props->returnPageArgs;
            Driver::postDigitizerAction = [](void **args) {
                
                PageSystem_findSwitch(reinterpret_cast<PageSystem_t *>(args[0]), reinterpret_cast<char *>(args[1]), args[2]);
                delete[] args;
            };
        };
    }
    Serial.println("-> Stage 5");

    draw();

    Driver::touchscreen_register_on_press(ts_onPress);
    Driver::touchscreen_register_on_release(ts_onRelease);
}

void _NumberFieldPage::onExit()
{
    Driver::touchscreen_register_on_press(nullptr);
    Driver::touchscreen_register_on_release(nullptr);
    
    // delete buttons
    for (size_t i = 0; i < sizeof(buttons) / sizeof(buttons[0]); ++i) {
        if (NumberFieldPage.buttons[i]) {
            delete NumberFieldPage.buttons[i];
            NumberFieldPage.buttons[i] = nullptr;
        }
    }

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
        NumberFieldPage.buttons[i]->performAction(x, y, 0, true);
        NumberFieldPage.buttons[i]->draw();
    }
}

void _NumberFieldPage::ts_onRelease()
{
    uint16_t x, y;
    Calibration.translateFromRaw(x, y);

    for (size_t i = 0; i < NumberFieldPage.numButtons; ++i) {
        if (NumberFieldPage.buttons[i]) {

            NumberFieldPage.buttons[i]->performAction(x, y, 0, false);
            NumberFieldPage.buttons[i]->draw();
        }
    }
}

void _NumberFieldPage::drawValue()
{
    // draws text box
    const uint16_t x = 20;
    const uint16_t y = 40;
    const uint16_t width = 210;
    const uint16_t height = 40;
    const uint16_t gap = 5;

    char buffer[24];
    if (NumberFieldPage.props && NumberFieldPage.props->getValue) {
        NumberFieldPage.props->getValue(NumberFieldPage.props, buffer, sizeof(buffer) / sizeof(buffer[0]));
    }
    else {
        strcpy(buffer, "------");
    }

    // draw value
    drawingWrapper.drawRect(x, y, width, height, 0, CMXG_WHITE);
    drawingWrapper.drawRect(x + gap, y + gap, width - 2 * gap, height - 2 * gap, 0, CMXG_BLACK);
    drawingWrapper.setTextSize(2);
    drawingWrapper.setTextDatum(CMXG_CR_DATUM);
    drawingWrapper.setTextColor(CMXG_WHITE, CMXG_WHITE);
    drawingWrapper.drawString(buffer, x + width - gap - 3, y + height / 2);

    // draws labels
    drawingWrapper.setTextSize(2);
    drawingWrapper.setTextDatum(CMXG_BL_DATUM);
    drawingWrapper.drawString(NumberFieldPage.props->label, x, y - 3);


    // draw units
    drawingWrapper.setTextSize(1);
    const uint16_t yUnits = y + height + 3;
    drawingWrapper.setTextDatum(CMXG_TR_DATUM);
    drawingWrapper.drawString(NumberFieldPage.props->postfix, x + width - gap - 3, yUnits);
}

_NumberFieldPage NumberFieldPage;
