// if true, compile factory firmware instead
#include "config.h"
#ifdef FACTORY

#ifndef FACTORY_CPP
#define FACTORY_CPP

#include <Arduino.h>
#define DEBUG
#include "utils.h"
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
    dev_println("Handing off");
    if (!SPIFFS.exists("/handoff")) {
        File f = SPIFFS.open("/handoff", "w+");
        f.close();
    }

    const esp_partition_t *partition = esp_partition_find_first(ESP_PARTITION_TYPE_APP, ESP_PARTITION_SUBTYPE_APP_OTA_0, nullptr);
    if (partition) {
        Serial.print("Found partition: ");
        Serial.println(partition->label);
        ESP_ERROR_CHECK(esp_ota_set_boot_partition(partition));

        const esp_partition_t *bootPartition = esp_ota_get_boot_partition();
        Serial.println(bootPartition->label);
    }
    else {
        Serial.println("Fatal error: Cannot find the main firmware partition (ota0)");
    }
}

void setup() {
    Serial.begin(9600);
    Serial.println("Starting Factory Firmware");
    
    Common_Init();

    const esp_partition_t *currentPartition = esp_ota_get_running_partition();
    Serial.print("The current partition address is: ");
    Serial.println(currentPartition->address, HEX);

    if (!SPIFFS.begin(true)) {
        while (true) {
            Serial.println("Fatal error: SPIFFS cannot be mounted");
        }
    }

    if(!SD.begin(SD_CS, *hspi, 4000000U))
    {
        Serial.println("Error: Cannot open MicroSD card. Check if inserted and mounted corectly");
        for(;;);
    }
    else {
        File f = SD.open("/boot_success.log", "w+");
        f.println("Boot successful");
        f.close();
    }

    if (SD.exists("/firmware.bin")) {
        Serial.println("-> Firmware file is found. Performing checks...");
        File newFirmware = SD.open("/firmware.bin", "r");
        if (!newFirmware.isDirectory()) {

            // check if firmware.bin can fit in ota partition
            const esp_partition_t *otaPartition = esp_partition_find_first(ESP_PARTITION_TYPE_APP, ESP_PARTITION_SUBTYPE_APP_OTA_0, nullptr);
            if (otaPartition->size < newFirmware.size()) {
                Serial.println("New firmware is larger than partiton size. Aborting");
                goto firmware_flash_abort;
            }
            
            SD.mkdir("/firmware");
            if (SD.exists("/firmware/firmware.bin")) {
                SD.remove("/firmware/firmware.bin");
            }

            size_t firmwareSize = newFirmware.size();

            Serial.println("-> Starting to update main firmware...");
            Update.begin(firmwareSize);
            Serial.println("-> Done installing. Validating...");
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
                Serial.println("-> Update completed! Restarting to updated application...");
                // handOff();
            }
            
            ESP.restart();
            
        }
        else {
            newFirmware.close();
            SD.remove("/firmware.bin");
        }
    }
    else if (SD.exists("/device/handoff")) {
        Serial.println("-> Found request in MicroSD card to boot to main firmware");

        File f =  SD.open("/device/handoff");
        
        uint32_t response;
        f.readBytes(reinterpret_cast<char *>(&response), 4);
        f.close();

        // file does not contain keep, delete the file
        if (response != (uint16_t)0x6b656570) {     // The word "keep" in hexidecimal ASCII
            SD.remove("/device/handoff");
        }

        handOff();
    }

    firmware_flash_abort:
    
    // handOff();
    Serial.println("End of factory app, restarting in 2 seconds");

    // check if firmware file exists in filesytem
  // put your setup code here, to run once:
}

void loop() {
    if (Serial.available()) {
        String message = Serial.readStringUntil('\n');

        if (message == "!boot-firmware") {
            const esp_partition_t *firmwarePartition = esp_partition_find_first(ESP_PARTITION_TYPE_APP, ESP_PARTITION_SUBTYPE_APP_OTA_0, nullptr);
            ESP_ERROR_CHECK(esp_ota_set_boot_partition(firmwarePartition));
            ESP.restart();
        }
    }
}

#endif
#endif