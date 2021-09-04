#include "NumberFieldComponent.hpp"
#include "../pages/NumberFieldPage.hpp"
#include "../pagesystem/pagesystem.h"
#include <stdio.h>
#include <string.h>

#ifdef DEV_DEBUG
#include <HardwareSerial.h>
#endif

NumberFieldComponent::NumberFieldComponent(DrawingWrapper &drw,
                                           int32_t *value, 
                                           uint16_t x, 
                                           uint16_t y, 
                                           uint16_t width, 
                                           uint16_t height, 
                                           const char *label,
                                           const char *postfix
                                           )
    : BoundedArea(x, y, width, height)
    , drw(drw)
    , value(value)
{
    strncpy(this->postfix, postfix, GRAPHICS_NUMBERFIELDCOMPONENT_POSTFIX_SIZE - 1);
    strncpy(this->label, label, GRAPHICS_NUMBERFIELDCOMPONENT_LABEL_SIZE - 1);
}

void NumberFieldComponent::draw()
{
    const int offset = 3;
    drw.drawRect(x, y, width, height, 0, CMXG_WHITE);
    drw.drawRect(x + offset, y + offset, width - 2 * offset, height - 2 * offset, 0, CMXG_BLACK);
    drw.setCursor(x + offset, y + offset, 2);
    drw.setTextColor(CMXG_WHITE, CMXG_WHITE);
    char buffer[32];
    int32_t realVal = value ? *value : 0;
    sprintf(buffer, "%d %s", realVal, postfix);
    drw.print(buffer);

    if (strnlen(label, GRAPHICS_NUMBERFIELDCOMPONENT_LABEL_SIZE)) {
        drw.setTextColor(CMXG_WHITE, CMXG_BLACK);
        drw.setCursor(x + 3, y + height, 2);
        drw.print(label);
    }
}

void NumberFieldComponent::performAction(uint16_t x, uint16_t y, uint8_t z,bool pressed)
{
    static bool previousClickState = false;
    static bool previousInBoundsState = false;

    bool hit = inBounds(x, y);

    // if (onPress         && pressed  && hit  && previousClickState  ) onPress(x, y, z);
    // if (onHoverEnter    && pressed  && hit                                ) onHoverEnter(x, y, z);
    // if (onHoverExit     && pressed  && !hit && previousInBoundsState) onHoverExit(x, y, z);
    if (!pressed && hit                                ) onRelease(x, y, z);

    previousClickState = pressed;
    previousInBoundsState = hit;
}

void NumberFieldComponent::onRelease(uint16_t x, uint16_t y, uint8_t z)
{
    _NumberFieldPage::Props_t *props = new _NumberFieldPage::Props_t;
    strncpy(props->label, label, GRAPHICS_NUMBERFIELDCOMPONENT_LABEL_SIZE);
    strncpy(props->postfix, postfix, GRAPHICS_NUMBERFIELDCOMPONENT_POSTFIX_SIZE);
    strncpy(props->returnPageName, returnPageName, PAGE_NAME_SIZE);
    props->value = value;

    assert(false && "Implement this");
    // PageSystem_switch(NumberFieldPage::page);
    
    Serial.println("-> Number Field Component Released!");
}
