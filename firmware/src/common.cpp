#include "common.h"
#include <Arduino.h>
#include <assert.h>

SPIClass *vspi;
SPIClass *hspi;

void Common_Init()
{
    Serial.println("Running test code");
    vspi = new SPIClass(VSPI);
    hspi = new SPIClass(HSPI);

    pinMode(HSPI_MOSI, OUTPUT);
    pinMode(HSPI_MISO, INPUT_PULLDOWN);
    
    vspi->begin(VSPI_SCLK, VSPI_MISO, VSPI_MOSI, LCD_CS);
    hspi->begin(HSPI_SCLK, HSPI_MISO, HSPI_MOSI, SD_CS);

    pinMode(TCH_CS, OUTPUT);
    digitalWrite(TCH_CS, HIGH);
    
    digitalWrite(TCH_CS, LOW);
    digitalWrite(HSPI_MOSI, HIGH);
    delay(200);
    digitalWrite(HSPI_MOSI, LOW);
    delay(200);
    digitalWrite(HSPI_MOSI, HIGH);
    delay(200);
    digitalWrite(HSPI_MOSI, LOW);
    delay(200);
    digitalWrite(TCH_CS, HIGH);
    
    
    
    digitalWrite(TCH_CS, LOW);
    hspi->beginTransaction(SPISettings(4000000, MSBFIRST, SPI_MODE0));
    uint8_t buff[] = { 0xFF, 0x01, 0x02, 0x13, 0x44, 0xFF};
    hspi->transferBytes(buff, buff, sizeof(buff));
    digitalWrite(TCH_CS, HIGH);
    hspi->endTransaction();

    Serial.println("DONE!");
    // for (;;);
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