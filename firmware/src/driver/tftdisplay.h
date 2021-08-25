#pragma once

#include <TFT_eSPI.h>
#include <FreeRTOS.h>
#include <stdint.h>

namespace Driver
{
    extern TFT_eSPI tft;
    extern TaskHandle_t _tftTaskHandle;
    extern bool tftHorizontal;
    
    void tft_begin(uint8_t rotation = 0);

    void tft_take(TickType_t waitTime=portMAX_DELAY);
    void tft_give();

    uint16_t tft_get_width();

    uint16_t tft_get_height();

    class TFTClaimMutex
    {
    public:
        TFTClaimMutex(TickType_t waitTime=portMAX_DELAY) {
            tft_take(waitTime);
        }
        ~TFTClaimMutex()
        {
            tft_give();
        }
    };
}

