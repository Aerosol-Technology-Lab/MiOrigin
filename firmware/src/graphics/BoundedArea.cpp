#pragma once

#include "BoundedArea.hpp"
#include <stdint.h>

BoundedArea::BoundedArea(uint16_t x, uint16_t y, uint16_t width, uint16_t height)
    : x(x),
      y(y),
      width(width),
      height(height)
{ }

bool BoundedArea::inBounds(uint16_t px, uint16_t py)
{
    return (px >= x) && (px < x + width) &&
           (py >= y) && (py < y + height);
}
