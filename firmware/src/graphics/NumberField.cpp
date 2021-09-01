/*
#include "NumberField.hpp"
#include "GraphicsConfig.hpp"
#include <string.h>

NumberField::NumberField(DrawingWrapper &drw, uint16_t x, uint16_t y, uint16_t width, uint16_t height, Font_t fnt)
    : BoundedArea(x, y, width, height)
    , font(font)
    , drw(drw)
    , postfix("")
{
    returnPage = nullptr;
}

// NumberField::~NumberField()
// {
//     if (returnPage) delete returnPage;
// }

void NumberField::setPostfix(const char *name)
{
    strncpy(postfix, name, GRAPHICS_NUMBERFIELD_POSTFIX_SIZE - 1);
}

void NumberField::setReturnPage(Page_t *page)
{
    returnPage = page;
}

void NumberField::setValue(int32_t *value)
{
    this->value = value;
}

int32_t NumberField::getValue()
{
    return *value;
}

void NumberField::performAction(uint16_t x, uint16_t y, uint8_t z, bool pressed)
{
    static bool previousClickState = false;
    static bool previousInBoundsState = false;

    bool hit = inBounds(x, y);

    if (pressed  && hit  && previousClickState   ) onPress(x, y, z);
    if (pressed  && hit                          ) onHoverEnter(x, y, z);
    if (pressed  && !hit && previousInBoundsState) onHoverExit(x, y, z);
    if (!pressed && hit                          ) onRelease(x, y, z);

    previousClickState = pressed;
    previousInBoundsState = hit;
}

void NumberField::onStart(void *)
{

}

void NumberField::onLoad(void *_, void *args)
{
    drw.setScreenColor(CMXG_BLACK);
}

*/