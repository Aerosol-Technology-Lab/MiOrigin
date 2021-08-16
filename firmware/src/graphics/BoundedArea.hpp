#pragma once

#include <stdint.h>

class BoundedArea
{
protected:
    // coordinates
    uint16_t x;
    uint16_t y;

    uint16_t width;
    uint16_t height;

    BoundedArea(uint16_t x=0, uint16_t y=0, uint16_t width=0, uint16_t height=0);

    bool inBounds(uint16_t px, uint16_t py);
};
