#include <TFT_eSPI.h>
#include <FreeRTOS.h>
#include "tftdisplay.h"

namespace Driver
{
    TFT_eSPI tft;
    TaskHandle_t _tftTaskHandle;
    bool tftHorizontal;

    void tft_begin(uint8_t rotation)
    {
        tft.init();
        tft.setRotation(rotation);
        Driver::tftHorizontal = rotation % 2;
        _tftTaskHandle = xSemaphoreCreateMutex();
    }

    void tft_take(TickType_t waitTime)
    {
        xSemaphoreTake(_tftTaskHandle, waitTime);
    }

    void tft_give()
    {
        xSemaphoreGive(_tftTaskHandle);
    }

    uint16_t tft_get_width()
    {
        return Driver::tftHorizontal ? TFT_HEIGHT : TFT_WIDTH;
    }

    uint16_t tft_get_height()
    {
        return Driver::tftHorizontal ? TFT_WIDTH : TFT_HEIGHT;
    }
}


