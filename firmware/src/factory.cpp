// if true, compile factory firmware instead
#ifdef FACTORY

#ifndef FACTORY_CPP
#define FACTORY_CPP

#include <Arduino.h>
#include "common.h"
#include <SPIFFS.h>
#include <FS.h>
#include <SD.h>
#include <SPI.h>
#include <Update.h>
#include <esp_ota_ops.h>

/**
 * @brief Writes a file in SPIFFS so ota app knows factory firmware handed it control
 * 
 */
void handOff()
{
    File f = SPIFFS.open("/handoff", "w");
    f.close();
}

void setup() {
    Serial.begin(9600);
    Common_Init();

    if(!SD.begin(SD_CS, *vspi, 8000000U))
    {
        Serial.println("Error: Cannot open MicroSD card. Check if inserted an mounter corectly");
        for(;;);
    }

    File newFirmware = SD.open("/firmware.bin", "r");
    if (newFirmware) {
        if (!newFirmware.isDirectory()) {

            // check if firmware.bin can fit in ota partition
            const esp_partition_t *otaPartition = esp_partition_find_first(ESP_PARTITION_TYPE_APP, ESP_PARTITION_SUBTYPE_APP_OTA_0, nullptr);
            if (otaPartition->size < newFirmware.size()) {
                Serial.println("New firmware is larger than partiton size. Aborting");
                goto firmware_flash_abort;
            }
            
            SD.mkdir("/firmware");
            SD.remove("/firmware/firmware.bin");

            size_t firmwareSize = newFirmware.size();

            Update.begin(firmwareSize);
            size_t bytesRead = Update.writeStream(newFirmware);
            
            bool restartToFactory = false;
            
            if (bytesRead != firmwareSize) {
                Serial.println("Error: Bytes written to ota does not match the file size");

                // reboot to factory, ensuring that factory is booted after restart
                const esp_partition_t *factoryPartition = esp_partition_find_first(ESP_PARTITION_TYPE_APP, ESP_PARTITION_SUBTYPE_APP_FACTORY, nullptr); 
                esp_ota_set_boot_partition(factoryPartition);
                
                ESP.restart();
            }
            
            if (!Update.end()) {
                restartToFactory = true;
                Serial.println("Update did not complete correctly. Something went wrong.");
            }
            if (!Update.isFinished()) {
                restartToFactory = true;
                Serial.println("Update did not finish correctly. Something went wrong");
            }
            
            newFirmware.close();
            SD.rename("/firmware.bin", "/firmware/firmware.bin");

            // perform restart behaviour
            if (restartToFactory) {
                // set bootloader to restart to factory firmware again. This prevents booting to bad firmware
                const esp_partition_t *factoryPartition = esp_partition_find_first(ESP_PARTITION_TYPE_APP, ESP_PARTITION_SUBTYPE_APP_FACTORY, nullptr);

                if (factoryPartition) {
                    Serial.println("Fatal error: Cannot somehow find factory partition even though factory firmware is currently running.");
                    Serial.println("REBOOTING");
                    delay(1000);
                    ESP.restart();
                }
                 
                esp_ota_set_boot_partition(factoryPartition);
            }
            else {
                // write to flash that firmware is successful. This lets ota0 to understand that it was booted from factory and is
                // handing control to ota0
                handOff();
            }
            
            ESP.restart();
            
        }
        else {
            newFirmware.close();
            SD.remove("/firmware.bin");
        }
    }

    firmware_flash_abort:
    newFirmware.close();
    
    handOff();
    Serial.println("End of factory app, restarting in 2 seconds");
    ESP.restart();
    // check if firmware file exists in filesytem
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}

#endif
#endif