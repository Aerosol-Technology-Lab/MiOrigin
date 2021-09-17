#pragma once

#define GRAPHICS_NUMBERFIELDCOMPONENT_LABEL_SIZE 10
#define GRAPHICS_NUMBERFIELDCOMPONENT_POSTFIX_SIZE 10

#include "NumberFieldDefs.hpp"
#include "BoundedArea.hpp"
#include "DrawingWrapper.hpp"
#include "../pagesystem/page.h"
#include <stdint.h>
#include <string.h>

class NumberFieldComponent : public BoundedArea
{
private:
    DrawingWrapper &drw;
    void *value;
    char label[GRAPHICS_NUMBERFIELDCOMPONENT_LABEL_SIZE]  = { 0 };
    char postfix[GRAPHICS_NUMBERFIELDCOMPONENT_POSTFIX_SIZE]  = { 0 };
    char returnPageName[PAGE_NAME_SIZE] = { 0 };
    
    NumberFieldDefs::ChangeValue_f changeValue;
    // void (*changeValue)(char c);
    NumberFieldDefs::GetValue_f getValue;
    // void (*getValue)(char *buffer, size_t size);
    
    
public:
    static Page_t page;

    NumberFieldComponent(DrawingWrapper &drw,
                         void *value, 
                         uint16_t x=0, 
                         uint16_t y=0, 
                         uint16_t width=0, 
                         uint16_t height=0,
                         const char *label="",
                         const char *postfix=""
                         );
    
    void setProperty(NumberFieldDefs::ChangeValue_f changeValue, NumberFieldDefs::GetValue_f getValue);
    
    void setReturnPageName(const char *buffer, size_t size);
    
    void draw();

    void performAction(uint16_t x, uint16_t y, uint8_t z, bool pressed);

    // void (*onPress)(uint16_t x, uint16_t y, uint8_t z);
    
    // void (*onHoverEnter)(uint16_t x, uint16_t y, uint8_t z);

    // void (*onHoverExit)(uint16_t x, uint16_t y, uint8_t z);
    
    void onRelease(uint16_t x, uint16_t y, uint8_t z);

private:
    void setPropsFromCurrent(NumberFieldDefs::Props_t &props);
};
