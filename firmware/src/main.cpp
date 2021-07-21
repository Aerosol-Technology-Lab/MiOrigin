// if true, compile factory firmware instead
#ifdef FACTORY

// these are defined in factory.cpp
extern void setup();
extern void loop();

#else

#include <Arduino.h>
#include "common.h"
#include <FS.h>
#include <SPI.h>
#include <SPIFFS.h>
#include <SD.h>
#include <esp_ota_ops.h>
#include <esp_task_wdt.h>
#include <BLE2902.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <ArduinoJson.h>
#include "BLE_Callback_Coms.h"
#include "BLE_UUID.h"
#include "utils.h"

// extract arduino core props
#if CONFIG_FREERTOS_UNICORE
#define ARDUINO_RUNNING_CORE 0
#else
#define ARDUINO_RUNNING_CORE 1
#endif

TaskHandle_t usbcHandler = nullptr;

BLE_Callback_Coms callbackComs;

/**
 * @brief Struct containing device info. Contents
 *        will be populated during setup
 * 
 */
struct {
    char deviceName[17] = "NONE";
    uint16_t id = (uint16_t) 0xFFFF;
    char pcbRev[17] = "NULL";
    
} DevinceInfo;

struct {

    BLEServer *pServer;

    struct {

        BLEService *pService;
        BLECharacteristic *pDeviceName;
        BLECharacteristic *pComs;
        
    } device;
    
    /**
     * @brief Puts BLE modem to sleep
     * 
     */
    void sleep()
    {
        if (pServer) {
            pServer->getAdvertising()->stop();
            ESP_ERROR_CHECK(esp_bt_sleep_enable());
        }
    }

    /**
     * @brief Wakes up BLE modem
     * 
     */
    void wakeup()
    {
        if (pServer) {
            ESP_ERROR_CHECK(esp_bt_sleep_disable());
            pServer->getAdvertising()->start();
        }
    }

    
} BLE_Props;

class MyCallbacks: public BLECharacteristicCallbacks
{
  void onWrite(BLECharacteristic *pCharacteristic)
  {
    std::string value = pCharacteristic->getValue();
    pCharacteristic->setValue(value + "bah");

    if (value.length() > 0)
    {
      Serial.println("*********");
      Serial.print("New value: ");
      for (int i = 0; i < value.length(); i++)
      {
        Serial.print(value[i]);
      }

      Serial.println();
      Serial.println("*********");
    }
  }
};


/**
 * @brief Parses command from a given string that starts with an exclamation mark
 * 
 * @param buffer 
 * @param buffer_length 
 * @param command 
 * @param command_length 
 * @return size_t 
 */
size_t parseCommandFromString(char *buffer, size_t buffer_length, char *command, size_t command_length)
{
    if (buffer_length && buffer[0] == '!') {
        size_t i;
        for (i = 1; i < buffer_length && i < command_length && (buffer[i] != '\0' || buffer[i] != '\r' || buffer[i] != ' '); ++i) {
            command[i - 1] = buffer[i];
        }

        return i;
    }

    return 0;
}

/**
 * @brief Handles responses to UART from USB-C
 * 
 * @param parameters 
 */
void handleUSBC(void *parameters = nullptr)
{
    const TickType_t waitDelay = 1000 / portTICK_PERIOD_MS;

    delay(200);
    Serial.flush();
    delay(200);
    
    String tmpStringClass;
    tmpStringClass.reserve(256);
    
    while (true) {
        Serial.println("Loop");
        
        if (Serial.available()) {
            Serial.println("@ Init stage");
            char messageBuffer[256] = {0};
            {
                tmpStringClass = Serial.readStringUntil('\n');
                strcpy(messageBuffer, tmpStringClass.c_str());
            }
            
            #ifdef DEV_DEBUG
            {
                Serial.print("\nDebug hex raw: ");
                Serial.println(messageBuffer);
                for(char c : messageBuffer) {
                    char tmp[12];
                    sprintf(tmp, "%02X ", c);
                    Serial.print(tmp);
                }
            }
            #endif
            
            Serial.println("Reached");
            size_t messageLen = strlen(messageBuffer);

            if (messageLen && messageLen < 256) {
                // can perform string checks

                Serial.println("@Stage 1");
                
                if (messageBuffer[0] == '/') {
                    // this is a command from MiClone. Parse this
                    // todo

                    // save command to file
                }
                else if (messageBuffer[0] == '!') {
                    // command from my helper program
                    // todo
                    Serial.println("@Stage2");
                    char command[17] = { 0 };
                    size_t offset = 0;
                    offset = parseCommandFromString(messageBuffer, sizeof(messageBuffer), command, sizeof(command));

                    Serial.print("  Result of command: ");
                    Serial.println(command);
                    Serial.print("  Result of strcmp(command, \"ping\"): ");
                    Serial.println(!strcmp(command, "ping"), DEC);

                    if (!strcmp(command, "sd") || !strcmp(command, "spiffs")) {

                        // FS &fs = !strcmp(command, "!sd") ? *(dynamic_cast<fs::FS *>)(&SD) : *(dynamic_cast<fs::FS *>)(&SPIFFS);
                        
                        offset = nextSubString(messageBuffer, offset, sizeof(messageBuffer), command, sizeof(command));
                        bool commandError = false;      // true when there is an invalid input to the command
                        
                        if (offset) {
                            if (!strcmp(command, "read")) {
                                // File f = SD.open()
                                
                            }
                            else if (!strcmp(command, "write")) {

                            }
                            else {
                                commandError = true;
                            }
                        }
                        else {
                            commandError = true;
                        }

                        utilsPrint("~Invalid '!file' command. Options are: ~file [write | read] [filename] ");
                    }
                    else if (!strcmp(command, "ping")) {
                        Serial.println("pong!");
                    }
                    else if (!strcmp(command, "boot-factory")) {
                        const esp_partition_t *currentParition = esp_ota_get_running_partition();
                        const esp_partition_t *factoryPartition = esp_partition_find_first(ESP_PARTITION_TYPE_APP, ESP_PARTITION_SUBTYPE_APP_FACTORY, nullptr);
                        ESP_ERROR_CHECK(esp_ota_set_boot_partition(factoryPartition));

                        const esp_partition_t *newBootParition = esp_ota_get_boot_partition();

                        if (newBootParition == factoryPartition) {
                            Serial.print("Booting to factory partition in");
                            for (int i = 3; i > 0; --i) {
                                Serial.print(i);
                                Serial.print(" ...");
                                Serial.println("This does not work. Maybe that to trigget ESP.restart() correctly, we have to restart immediately after partition select or use CPU1 to perform the reset");
                                assert(false);
                                delay(1000);
                            }

                            ESP.restart();
                        }
                        else if (newBootParition == currentParition) {
                            Serial.println("Error: Failed to select factory partition. Next boot will be current partition");
                        }
                        else {
                            Serial.println("Error: Partition is booting to something else! It is neither factory or firmware (ota0)");
                        }
                    }
                    else if (!strcmp(command, "device-name")) {
                        Serial.print("-> Device Name: ");
                        Serial.println(DevinceInfo.deviceName);
                    }
                    else if (!strcmp(command, "device-raw")) {
                        if (SPIFFS.exists("/device_info")) {
                            File f = SPIFFS.open("/device_info", "r");

                            char sendBuffer[256] = { 0 };
                            sprintf(sendBuffer, "name %s size %08X", f.name(), f.size());
                            Serial.print(sendBuffer);
                            Serial.write(f);
                        }
                        else {
                            Serial.println("Error: Cannot find device info file. Flash new filesystem image");
                        }
                    }
                }
            }
            else {
                // should I do something here?
            }
        }
        else
        {
            vTaskDelay(waitDelay);
        }
    }
}

void installFactoryFirmware(void *params) {

    File f = SD.open("/factory.bin", "r");
    size_t factorySize = f.size();
    const esp_partition_t *partition = esp_partition_find_first(ESP_PARTITION_TYPE_APP, ESP_PARTITION_SUBTYPE_APP_FACTORY, nullptr);

    if (partition->size < factorySize) {
        Serial.println("Factory firmware is larger than partion size. Aborting flash");
        vTaskDelete(NULL);
        return;
    }
    
    // todo backup factory firmware before flashing
    ESP_ERROR_CHECK(esp_partition_erase_range(partition, 0, partition->size));
    
    size_t bytesRead = 0;
    while (f.available()) {
        char buffer[256];
        size_t currentTransaction = f.readBytes(buffer, sizeof(buffer));
        ESP_ERROR_CHECK(esp_partition_write(partition, bytesRead, buffer, currentTransaction));
        bytesRead += currentTransaction;
    }
    
    if (bytesRead != factorySize) {
        Serial.println("Uh oh... Data flashed to factory partition does not match the filesize of the factory.bin");
        Serial.println("This is not supposed to happen");
        assert(false);
    }
    
    f.close();
    SD.mkdir("/firmware");
    SD.remove("/firmware/factory.bin");
    SD.rename("/factory.bin", "/firmware/factory.bin");
    
    Serial.println("Successfully flashed factory firmware!");
    
    vTaskDelete(NULL);
};

void setup()
{
    Serial.begin(9600);
    Serial.println("Starting ota firmware v2");
    
    Serial.println("\n=== Device Info ===");
    {
        const esp_partition_t *currentPartition = esp_ota_get_boot_partition();
        char buff[128];
        sprintf(buff, "  Boot Address: 0x%08X\n  %s\n\n", currentPartition->address, currentPartition->label);
        Serial.print(buff);
    }
    
    Serial.println("-> Mounting SPIFFS...");
    if (!SPIFFS.begin(true)) {
        Serial.println("Error - SPIFFS failed!");
        for(;;);
    }
    else {
        Serial.println("-> SPIFFS mounted.");
    }
    
    
    // pinMode(SD_CS, OUTPUT);
    
    // digitalWrite(SD_CS, HIGH);
    
    delay(1000);
    
    Common_Init();

    // digitalWrite(TCH_CS, LOW);
    
    // hspi->beginTransaction(SPISettings(4000000, MSBFIRST, SPI_MODE0));

    // {
    //     char message[] = "Hello world! This is my sentence!";
    //     hspi->transferBytes((uint8_t *) &message, nullptr, sizeof(message));
    // }
    
    // hspi->endTransaction();
    
    Serial.println("Initializing SD card...");
    if(!SD.begin(SD_CS, *hspi, 4000000U))
    {
        Serial.println("Error: Cannot open MicroSD card. Check if inserted and mounted correctly");

        for (int i = 3; i > 0; --i) {
            Serial.print("\r");
            Serial.print("                                \r");
            Serial.print("Rebooting in ");
            Serial.print(i);

            for (int j = 3; j > 0; --j) {
                Serial.print('.');
                vTaskDelay(1000 / 3 / portTICK_RATE_MS);
            }
        }

        Serial.println("Ending MicroSD card");
        hardReset();
    }
    else {
        Serial.println("SD card mounted!");
        File verify = SD.open("/test.txt", "a+");
        verify.println("Print");
        verify.close();
    }
    digitalWrite(TCH_CS, HIGH);

    /* Acquire device information */
    if (SPIFFS.exists("/device_info")) {
        StaticJsonDocument<512> deviceJSON;
        File f = SPIFFS.open("/device_info", "r");
        deserializeJson(deviceJSON, f);

        // checks for values
        if (deviceJSON.containsKey("name")) {
            std::string data = deviceJSON["name"].as<std::string>();
            if (data.size() > sizeof(DevinceInfo.deviceName) / sizeof(DevinceInfo.deviceName[0])) {
                // deletes extra characters
                data.erase(data.begin() + (sizeof(DevinceInfo.deviceName) / sizeof(DevinceInfo.deviceName[0])),
                           data.end());
            }
            
            strcpy(DevinceInfo.deviceName, data.c_str());
        }
        if (deviceJSON.containsKey("pcbRev")) {
            std::string data = deviceJSON["pcbRev"].as<std::string>();
            if (data.size() > sizeof(DevinceInfo.pcbRev) / sizeof(DevinceInfo.pcbRev[0])) {
                // deletes extra characters
                data.erase(data.begin() + (sizeof(DevinceInfo.pcbRev) / sizeof(DevinceInfo.pcbRev[0])),
                           data.end());
            }
            
            strcpy(DevinceInfo.pcbRev, data.c_str());
        }
        if (deviceJSON.containsKey("id")) {
            uint16_t data = deviceJSON["pcbRev"].as<uint16_t>();
            DevinceInfo.id = data;
        }

    }
    else {
        Serial.println("Error: File \"/device_info\" does not exist in SPIFFS");
        while (true);
    }


    auto rebootToFactory = []() {
        const esp_partition_t *factoryParition = esp_partition_find_first(ESP_PARTITION_TYPE_APP, ESP_PARTITION_SUBTYPE_APP_FACTORY, nullptr);
        // todo what happens if factoryPartition is nullptr?
        ESP_ERROR_CHECK(esp_ota_set_boot_partition(factoryParition));
        ESP.restart();
    };

    // // check if required to boot to factory
    // if (!SPIFFS.exists("/handoff")) {
    //     // handoff file does not exist, boot to factory
    //     Serial.println("-> Handoff file in SPIFFS found. Rebooting to factory firmware...");
    //     rebootToFactory();
    // }
    
    // check if new ota firmware exists
    if (SD.exists("/firmware.bin")) {
        File firmwareFile = SD.open("/firmware.bin", "r");
        SPIFFS.remove("/handoff");
        rebootToFactory();
        firmwareFile.close();
    }

    /* Loads vars from SPIFFS */


    // enables watchdog timer
    // esp_task_wdt_init();

    // check if new factory firmware exists
    if (SD.exists("/factory.bin")) {
        xTaskCreatePinnedToCore(installFactoryFirmware,
                                "factory_install",
                                800,
                                nullptr,
                                1,
                                nullptr,
                                !ARDUINO_RUNNING_CORE);
    }
    
    // setup usb c handler
    xTaskCreatePinnedToCore(handleUSBC,
                            "usbc_handler",
                            4096,
                            nullptr,
                            1,
                            &usbcHandler,
                            ARDUINO_RUNNING_CORE);
        
    // setup RS-232
    Serial2.begin(9600);

    /* Start Bluetooth */
    // Initialize and Server Info
    BLEDevice::init(DevinceInfo.deviceName);
    BLE_Props.pServer = BLEDevice::createServer();
    
    // Service creation
    BLE_Props.device.pService = BLE_Props.pServer->createService(SERVICE_DEVICE_INFO_UUID);
    
    // Characteristic creation
    BLE_Props.device.pDeviceName = BLE_Props.device.pService->createCharacteristic(CHARACTERISTIC_DEVICE_NAME_UUID,
                                                                                   BLECharacteristic::PROPERTY_READ   |
                                                                                   BLECharacteristic::PROPERTY_WRITE  |
                                                                                   BLECharacteristic::PROPERTY_NOTIFY |
                                                                                   BLECharacteristic::PROPERTY_INDICATE);
    BLE_Props.device.pDeviceName->setValue("Test");
    BLE_Props.device.pDeviceName->setCallbacks(new MyCallbacks());

    BLE_Props.device.pComs = BLE_Props.device.pService->createCharacteristic(BLECC_CHARACTERISTIC_UUID,
                                                                             BLECharacteristic::PROPERTY_WRITE  |
                                                                             BLECharacteristic::PROPERTY_READ   |
                                                                             BLECharacteristic::PROPERTY_NOTIFY |
                                                                             BLECharacteristic::PROPERTY_INDICATE);
    BLE_Props.device.pComs->setValue("Initialized");          
    BLE_Props.device.pComs->addDescriptor(new BLE2902);          
    BLE_Props.device.pComs->setCallbacks(&callbackComs);
    
    
    BLE_Props.device.pService->start();
    
    // Start advertising
    BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
    pAdvertising->addServiceUUID(SERVICE_DEVICE_INFO_UUID);
    pAdvertising->addServiceUUID(BLECC_CHARACTERISTIC_UUID);
    pAdvertising->setScanResponse(true);
    pAdvertising->setMinPreferred(0x06);
    pAdvertising->setMinPreferred(0x12);
    BLEDevice::startAdvertising();
}

void loop()
{
    vTaskDelay(10000 / portTICK_RATE_MS);
    // do nothing
}

#endif