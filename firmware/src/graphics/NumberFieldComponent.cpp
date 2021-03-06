#include "NumberFieldComponent.hpp"
#include "../pages/NumberFieldPage.hpp"
#include "NumberFieldDefs.hpp"
#include "../pages/AppPageConfig.hpp"
#include "../driver/touchscreen.h"
#include <stdio.h>
#include <string.h>

#ifdef DEV_DEBUG
#include <HardwareSerial.h>
#endif

NumberFieldComponent::NumberFieldComponent()
{ }

NumberFieldComponent::NumberFieldComponent(DrawingWrapper &drw,
                                           void *value, 
                                           uint16_t x, 
                                           uint16_t y, 
                                           uint16_t width, 
                                           uint16_t height, 
                                           const char *label,
                                           const char *postfix
                                           )
    : BoundedArea(x, y, width, height)
    , drw(&drw)
    , value(value)
{
    strncpy(this->postfix, postfix, GRAPHICS_NUMBERFIELDCOMPONENT_POSTFIX_SIZE - 1);
    strncpy(this->label, label, GRAPHICS_NUMBERFIELDCOMPONENT_LABEL_SIZE - 1);
}

NumberFieldComponent::NumberFieldComponent(NumberFieldComponent &&component)
    : BoundedArea(component.x, component.y, component.width, component.height)
{
    drw = component.drw;
    component.drw = nullptr;

    value = component.value;
    component.value = nullptr;
    
    strcpy(label, component.label);
    strcpy(postfix, component.postfix);
    
    returnPageName = std::move(component.returnPageName);
    
    changeValue = component.changeValue;
    component.changeValue = nullptr;
    
    getValue = component.getValue;
    component.getValue = nullptr;

    clearValue = component.clearValue;
    component.clearValue = nullptr;
}

void NumberFieldComponent::setProperty(NumberFieldDefs::ChangeValue_f changeValue, NumberFieldDefs::GetValue_f getValue, NumberFieldDefs::ClearValue_f clearValue)
{
    this->changeValue = changeValue;
    this->getValue = getValue;
    this->clearValue = clearValue;
}

void NumberFieldComponent::setReturnPageName(const char *name, size_t size)
{
    // error: fix this
    // strncpy(returnPageName, name, std::min(size, sizeof(returnPageName) - 1));
    returnPageName = name;
    delay(80);
    Serial.printf("Page name is: %s and the returnPageName is: %s\n", name, returnPageName);
    delay(80);
}

void NumberFieldComponent::draw()
{
    const int offset = 3;
    drw->drawRect(x, y, width, height, 0, CMXG_WHITE);
    drw->drawRect(x + offset, y + offset, width - 2 * offset, height - 2 * offset, 0, CMXG_BLACK);
    
    #ifdef SAFE_CODE
    assert(getValue && "Get Value is not initialized for this Nuberfield Component");
    #endif
    
    char buffer[32];
    NumberFieldDefs::Props_t props;
    setPropsFromCurrent(props);
    getValue(&props, buffer, sizeof(buffer));
    drw->setTextColor(CMXG_WHITE, CMXG_WHITE);
    drw->setTextFont(CMXG_FONT_PRIMARY);
    drw->setTextSize(2);
    drw->setTextDatum(CMXG_CL_DATUM);
    drw->drawString(buffer, x + offset + 4, y + height / 2);

    if (strnlen(label, GRAPHICS_NUMBERFIELDCOMPONENT_LABEL_SIZE)) {
        drw->setTextSize(1);
        drw->setTextColor(CMXG_WHITE, CMXG_BLACK);
        drw->setCursor(x + 3, y + height, 2);
        drw->print(label);
    }
}

void NumberFieldComponent::performAction(uint16_t x, uint16_t y, uint8_t z,bool pressed)
{
    // static bool previousClickState = false;
    // static bool previousInBoundsState = false;

    bool hit = inBounds(x, y);

    // if (onPress         && pressed  && hit  && previousClickState  ) onPress(x, y, z);
    // if (onHoverEnter    && pressed  && hit                                ) onHoverEnter(x, y, z);
    // if (onHoverExit     && pressed  && !hit && previousInBoundsState) onHoverExit(x, y, z);
    if (!pressed && hit                                ) onRelease(x, y, z);

    // previousClickState = pressed;
    // previousInBoundsState = hit;
}

void NumberFieldComponent::onRelease(uint16_t x, uint16_t y, uint8_t z)
{
    Serial.println("-> I am pressed from the NumberFieldComponent");
    NumberFieldDefs::Props_t *props = new NumberFieldDefs::Props_t;
    setPropsFromCurrent(*props);
    

    // assert(false && "Implement this");
    // PageSystem_switch(NumberFieldPage::page);
    NumberFieldPage.generatePage(page);

    PageSystem_switch(&devicePageManager, &page, props);

    // Driver::postDigitizerArgs = reinterpret_cast<void **>(malloc(sizeof(void *) * 3));
    // Driver::postDigitizerArgs[0] = &devicePageManager;
    // Driver::postDigitizerArgs[1] = &page;
    // Driver::postDigitizerArgs[2] = props;
    // Driver::postDigitizerAction = [](void **args) {

    //     PageSystem_switch(reinterpret_cast<PageSystem_t *>(args[0]), reinterpret_cast<Page_t *>(args[1]), args[2]);
    //     delete[] args;
    // };
    
    Serial.println("-> Number Field Component Released!");
}

void NumberFieldComponent::setPropsFromCurrent(NumberFieldDefs::Props_t &props)
{
    strncpy(props.label, label, GRAPHICS_NUMBERFIELDCOMPONENT_LABEL_SIZE);
    strncpy(props.postfix, postfix, GRAPHICS_NUMBERFIELDCOMPONENT_POSTFIX_SIZE);
    props.returnPageName = returnPageName;
    props.value = value;
    props.changeValue = changeValue;
    props.getValue = getValue;
    props.clearValue = clearValue;
}

Page_t NumberFieldComponent::page;
