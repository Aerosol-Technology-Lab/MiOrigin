#include "common.h"
#include <Arduino.h>
#include <Wire.h>
#include <assert.h>
#include <esp_int_wdt.h>
#include <esp_task_wdt.h>

SPIClass *vspi;
SPIClass *hspi;

/**
 * @brief Forces the ESP32 to perform a hard reset by triggering
 *        the panic handler
 * 
 */
void hardReset()
{
    esp_task_wdt_init(1, true);
    esp_task_wdt_add(NULL);
    while(true);
}

void Common_Init()
{
    Wire.begin(I2C_SDA, I2C_SCL);
    
    vspi = new SPIClass(VSPI);
    hspi = new SPIClass(HSPI);

    pinMode(HSPI_MOSI, OUTPUT);
    pinMode(HSPI_MISO, INPUT_PULLDOWN);
    
    vspi->begin(VSPI_SCLK, VSPI_MISO, VSPI_MOSI, LCD_CS);
    hspi->begin(HSPI_SCLK, HSPI_MISO, HSPI_MOSI, SD_CS);

    pinMode(TCH_CS, OUTPUT);
    digitalWrite(TCH_CS, HIGH);
    
    delay(200);

    Serial.println("DONE!");
}

size_t readUntilEnd(char *buffer, size_t bufferSize, Stream &stream)
{
    // block until first byte is read
    Serial.print("@ Stage 1");
    while (!Serial.available()) {
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }

    
    size_t bytesRead = 0;

    Serial.print("@ Stage 2");
    // read minimum two bytes
    while (bytesRead < 2) {
        if (Serial.available()) {
            bytesRead += Serial.readBytesUntil('\n', buffer, bufferSize - bytesRead);
        }
        delay(10);
    }

    Serial.print("@ Stage 3");
    while (bytesRead < 2 || *((uint16_t *) (buffer + bytesRead - 2)) != LINE_TERMINATION) {
        if (Serial.available()) {
            bytesRead += Serial.readBytesUntil('\n', buffer + bytesRead, bufferSize - bytesRead);
            Serial.println();
            Common_HEX_print(buffer);
        }
        delay(10);
    }

    Serial.print("@ Stage 4");
    *((uint16_t *) (buffer + bytesRead - 2)) = 0;

    return bytesRead - 2;
}

void Common_USBC_Handler(void *params)
{
    const TickType_t waitDelay = 500 / portTICK_PERIOD_MS;
    
    while (true) {
        if (Serial.available()) {
            char buffer[512] ;
            readUntilEnd(buffer, sizeof(buffer), Serial);
            
            // process if there's data in the buffer
            if (strlen(buffer)) {

                if (!strcmp(buffer, "!update-firmware")) { }
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

void Common_HEX_print(char *cstr, Stream &stream)
{
    while (*cstr != 0) {
        stream.print(*cstr, HEX);
        cstr++;
    }
}
