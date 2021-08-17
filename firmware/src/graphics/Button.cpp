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
    
    state.raw = 0;
}

void Button::setTextColor(Color color)
{
    textColor = color;
}

void Button::setButtonColor(Color buttonColor)
{
    this->buttonColor = buttonColor;
}

void Button::draw()
{
    uint16_t xmid = (x + width)  / 2;
    uint16_t ymid = (y + height) / 2;
    drw.drawRect(x, y, width, height, radius, buttonColor);
    drw.setTextDatum(CMXG_MC_DATUM);
    drw.setCursor(xmid, ymid, font);
    drw.setTextColor(textColor, textColor);
    drw.print(name);
}

void Button::performAction(uint16_t x, uint16_t y, uint8_t z,bool pressed)
{
    bool hit = inBounds(x, y);

    // todo: refactor this code so that hit is in an if statement
    if (onPress      &&  hit  && !state.previousClickState  ) onPress(x, y, z);
    if (onHoverEnter &&  hit                                ) onHoverEnter(x, y, z);
    if (onHoverExit  && !hit &&  state.previousInBoundsState) onHoverExit(x, y, z);
    if (onRelease    && !hit &&  state.previousInBoundsState) onRelease(x, y, z);

    state.previousClickState = pressed;
    state.previousInBoundsState = hit;
}

// Button& Button::operator=(const Button &other)
// {

// }
