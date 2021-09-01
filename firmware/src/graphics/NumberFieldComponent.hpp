#pragma once

#define GRAPHICS_NUMBERFIELDCOMPONENT_LABEL_SIZE 10
#define GRAPHICS_NUMBERFIELDCOMPONENT_POSTFIX_SIZE 10

#include "BoundedArea.hpp"
#include "DrawingWrapper.hpp"
#include <stdint.h>
#include <string.h>

class NumberFieldComponent : public BoundedArea
{
private:
    DrawingWrapper &drw;
    int32_t *value;
    char label[GRAPHICS_NUMBERFIELDCOMPONENT_LABEL_SIZE];
    char postfix[GRAPHICS_NUMBERFIELDCOMPONENT_POSTFIX_SIZE];
    
public:
    NumberFieldComponent(DrawingWrapper &drw,
                         int32_t *value, 
                         uint16_t x=0, 
                         uint16_t y=0, 
                         uint16_t width=0, 
                         uint16_t height=0,
                         const char *label="",
                         const char *postfix=""
                         );
    
    void draw();

    void performAction(uint16_t x, uint16_t y, uint8_t z, bool pressed);

    // void (*onPress)(uint16_t x, uint16_t y, uint8_t z);
    
    // void (*onHoverEnter)(uint16_t x, uint16_t y, uint8_t z);

    // void (*onHoverExit)(uint16_t x, uint16_t y, uint8_t z);
    
    void onRelease(uint16_t x, uint16_t y, uint8_t z);
};
