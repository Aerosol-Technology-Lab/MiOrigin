#pragma once

#include <Arduino.h>
#include <limits>
#include <SPI.h>
#include <utility>

namespace XPT2046TestDriver
{
    SPISettings spiSettings(50, MSBFIRST, SPI_MODE0);
    
    uint16_t _cs = std::numeric_limits<uint16_t>::max();
    
    SPIClass *_spi;

    uint16_t _xRaw, _yRaw, _zRaw;

    void init(SPIClass *spi, uint16_t csPin)
    {
        XPT2046TestDriver::_spi = spi;
        XPT2046TestDriver::_cs = csPin;
    }

    void update()
    {
        SPI.beginTransaction(std::move(spiSettings));
    }

    void getRaw(uint16_t &xRaw, uint16_t &yRaw, uint16_t &zRaw)
    {
        xRaw = _xRaw;
        yRaw = _yRaw;
        zRaw = _zRaw;
    }
}
