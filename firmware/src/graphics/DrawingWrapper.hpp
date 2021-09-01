#pragma once

#include <stdint.h>
#include "GraphicsConfig.hpp"

struct DrawingWrapper
{
    DrawingWrapper()
    {
        drawPixel    = nullptr;
        drawRect     = nullptr;
        print        = nullptr;
        println      = nullptr;
        setTextColor = nullptr;
    }
    
    void (*drawPixel)(uint16_t x, uint16_t y, Color color);

    void (*drawRect)(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t radius, Color color);
    
    void (*print)(const char *str);

    void (*println)(const char *str);

    void (*printf)(const char *str, ...);

    void (*setCursor)(uint16_t x, uint16_t y, uint8_t font);

    void (*setTextDatum)(uint8_t d);

    /**
     * @brief Fuction pointer to change text color on display
     * 
     * @note if foreground is equal to background, then the text
     *          is 'transparent'. This should be implemented in
     *          the definition.
     * 
     * @param foreground foreground color
     * @param background background color
     */
    void (*setTextColor)(Color foreground, Color background);

    void (*setScreenColor)(Color color);
};
