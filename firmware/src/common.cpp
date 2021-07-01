#include "common.h"
#include <Arduino.h>
#include <assert.h>

SPIClass *vspi;
SPIClass *hspi;

void Common_Init()
{
    vspi = new SPIClass(VSPI);
    hspi = new SPIClass(HSPI);
    vspi->begin(VSPI_SCLK, VSPI_MISO, VSPI_MOSI, LCD_CS);
    hspi->begin(HSPI_SCLK, HSPI_MISO, HSPI_MOSI, SD_CS);
}

void readUntilEnd(char *buffer, Stream &stream)
{
    Serial.println("Implement 'readUntil' definition in common.cpp");
    assert(false);
}

void Common_USBC_Handler(void *params)
{
    const TickType_t waitDelay = 500 / portTICK_PERIOD_MS;
    
    while (true) {
        if (Serial.available()) {
            char buffer[512] ;
            readUntilEnd(buffer, Serial);
            
            // process if there's data in the buffer
            if (strlen(buffer)) {

                if (!strcmp(buffer, "!update-firmware"));
                // Serial.readBytes
                // todo
                #ifdef OTA0
                
                #endif
            }
        }
        else {
            vTaskDelay(waitDelay);
        }
    }
}