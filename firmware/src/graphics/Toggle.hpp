#pragma once

#include "BoundedArea.hpp"
#include "GraphicsConfig.hpp"
#include "DrawingWrapper.hpp"
#include <stdint.h>

class Toggle : public BoundedArea
{
protected:
    bool state;
    DrawingWrapper *drw;
    Color outerColor;
    Color innerColor;
    uint16_t outerRadius;
    uint16_t innerRadius;

public:
    Toggle();

    Toggle(DrawingWrapper &drw,
           uint16_t x, 
           uint16_t y, 
           uint16_t outerRadius, 
           uint16_t innerRadius, 
           Color innerColor=CMXG_GREEN, 
           Color outerColor=CMXG_LIGHTGREY
            );

    const bool & getValue();

    void setValue(bool state);

    void draw();    

    void performAction(uint16_t x, uint16_t y, uint8_t z, bool pressed);

protected:
    void onRelease(uint16_t x, uint16_t y, uint8_t z);
};
