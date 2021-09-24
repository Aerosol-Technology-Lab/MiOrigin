#include "Toggle.hpp"
#include <Arduino.h>

Toggle::Toggle()
    : BoundedArea(0, 0, 0, 0)
{ }

Toggle::Toggle(DrawingWrapper &drw,
               uint16_t x, 
               uint16_t y, 
               uint16_t outerRadius, 
               uint16_t innerRadius, 
               Color innerColor, 
               Color outerColor
               )
               : BoundedArea(x - outerRadius, y - outerRadius, outerRadius * 2, outerRadius * 2)
               , drw(&drw)
               , outerColor(outerColor)
               , innerColor(innerColor)
               , outerRadius(outerRadius)
               , innerRadius(innerRadius)
{ }

const bool & Toggle::getValue()
{
    return state;
}

void Toggle::setValue(bool state) {
    this->state = state;
}

void Toggle::draw()
{
    drw->drawCircle(x + outerRadius, y + outerRadius, outerRadius, outerColor);
    Color c = state ? innerColor : CMXG_BLACK;
    drw->drawCircle(x + outerRadius, y + outerRadius, innerRadius, c);
}

void Toggle::performAction(uint16_t x, uint16_t y, uint8_t z, bool pressed)
{
    bool hit = inBounds(x, y);
    if (!pressed && hit                                ) onRelease(x, y, z);
}

void Toggle::onRelease(uint16_t x, uint16_t y, uint8_t z)
{
    Serial.println("-> Toggle toggled!");
    state = !state;
    draw();
}
