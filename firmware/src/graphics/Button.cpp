#include "Button.hpp"
#include <string.h>
#include "DrawingWrapper.hpp"

Button::Button(DrawingWrapper &drw, name_t name ,uint16_t x, uint16_t y, uint16_t width, uint16_t height, Font_t fnt)
    : BoundedArea(x, y, width, height)
    , font(fnt)
    , drw(drw)
{
    #ifdef GRAPHICS_BUTTON_DYNAMIC_MEMORY
    #error Dynamic memory for buttons feature is not yet supported
    #else
    
    strncpy(this->name, name, sizeof(this->name));
    
    #endif
}

void Button::setTextColor(Color color)
{
    textColor = color;
}

void Button::setButtonColor(Color buttonColor)
{
    this->buttonColor = buttonColor;
}

void Button::setButtonSize(uint8_t size)
{
    this->buttonSize = size;
}

void Button::draw()
{
    uint16_t xmid = (2 * x + width)  / 2;
    uint16_t ymid = (2 * y + height) / 2;
    drw.drawRect(x, y, width, height, radius, buttonColor);
    drw.setTextSize(buttonSize);
    drw.setTextDatum(CMXG_MC_DATUM);
    // drw.setCursor(xmid, ymid, font);
    drw.setTextColor(textColor, textColor);
    drw.drawString(name, xmid, ymid);
}

void Button::performAction(uint16_t x, uint16_t y, uint8_t z,bool pressed)
{
    static bool previousClickState = false;
    static bool previousInBoundsState = false;

    bool hit = inBounds(x, y);

    if (onPress         && pressed  && hit  && previousClickState  ) onPress(x, y, z);
    if (onHoverEnter    && pressed  && hit                                ) onHoverEnter(x, y, z);
    if (onHoverExit     && pressed  && !hit && previousInBoundsState) onHoverExit(x, y, z);
    if (onRelease       && !pressed && hit                                ) onRelease(x, y, z);

    previousClickState = pressed;
    previousInBoundsState = hit;
}

// Button& Button::operator=(const Button &other)
// {

// }
