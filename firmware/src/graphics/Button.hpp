#pragma once

// #define GRAPHICS_BUTTON_DYNAMIC_MEMORY

#define GRAPHICS_BUTTON_MAX_NAME_LENGTH 32

#include "BoundedArea.hpp"
#include <stdint.h>
#include "GraphicsConfig.hpp"
#include "DrawingWrapper.hpp"

#ifdef GRAPHICS_BUTTON_DYNAMIC_MEMORY
#include <string>
using name_t = std::string;

#else
using name_t = const char *;

#endif

class Button : public BoundedArea
{
private:

    #ifndef GRAPHICS_BUTTON_DYNAMIC_MEMORY
    char name[GRAPHICS_BUTTON_MAX_NAME_LENGTH];
    #else
    std::string name;
    #endif

protected:

    Font_t font;
    uint32_t radius;
    Color textColor;
    Color buttonColor;
    uint8_t buttonSize = 1;

    DrawingWrapper &drw;

public:
    Button(bool initialize=true);
    Button(DrawingWrapper &drw, name_t name="",uint16_t x=0, uint16_t y=0, uint16_t width=0, uint16_t height=0, Font_t fnt=2);

    void setTextColor(Color textColor);

    void setButtonColor(Color buttonColor);
    
    void setButtonSize(uint8_t size);
    
    void draw();

    void performAction(uint16_t x, uint16_t y, uint8_t z, bool pressed);

    void (*onPress)(uint16_t x, uint16_t y, uint8_t z);
    
    void (*onHoverEnter)(uint16_t x, uint16_t y, uint8_t z);

    void (*onHoverExit)(uint16_t x, uint16_t y, uint8_t z);
    
    void (*onRelease)(uint16_t x, uint16_t y, uint8_t z);

    // Button& operator=(const Button &other);
};
