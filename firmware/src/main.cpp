// if true, compile factory firmware instead

#ifdef FACTORY

// these are defined in factory.cpp
extern void setup();
extern void loop();

#else

#include "config.h"
#include <Arduino.h>
#include "credentials.h"
#include "common.h"
#include <memory>
#include <FS.h>
#include <SPI.h>
#include <SPIFFS.h>
#include <SD.h>
#include <esp_ota_ops.h>
#include <esp_task_wdt.h>
#include <BLE2902.h>
#ifdef WIFI_CONNECTIVITY_ENABLE
    #include <WiFi.h>
    #include <HTTPClient.h>
    #include "wifisys/WiFiController.h"
    #include "wifisys/WiFi_WPA_Connection.h"
    #include "WiFiOTAUpdater.h"
#endif
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <ArduinoJson.h>
#include <TFT_eSPI.h>
#include "driver/tftdisplay.h"
#include "driver/touchscreen.h"
#include "driver/lipo.h"
#include "driver/miclone.hpp"
#include "BLE_Callback_Coms.h"
#include "BLE_UUID.h"
#include "utils.h"
#include "DisplaySetup.h"       // this line must be after including TFT_eSPI.h
#include "rom/md5_hash.h"
#include <hwcrypto/aes.h>
#include <mbedtls/rsa.h>
#include <string>

// pages
#include "graphics/Graphics.hpp"
#include "pages/AppPageConfig.hpp"
#include "pagesystem/pagesystem.h"
#include "pagesystem/pageoptions.h"
#include "pages/Calibration.h"
#include "pages/Debug.hpp"

// extract arduino core props
#if CONFIG_FREERTOS_UNICORE
#define ARDUINO_RUNNING_CORE 0
#else
#define ARDUINO_RUNNING_CORE 1
#endif

#define MAJOR_FIRMWARE_VERSION 0
#define MINOR_FIRMWAR_VERSION  6

QueueHandle_t tsQueue;

TaskHandle_t usbcHandler = nullptr;

BLE_Callback_Coms callbackComs;

PageSystem_t devicePageManager;

using Driver::tft;

using Driver::ts;

/**
 * @brief Struct containing device info. Contents
 *        will be populated during setup
 * 
 */
struct {
    char deviceName[17] = "NONE";
    uint16_t id = (uint16_t) 0xFFFF;
    char pcbRev[17] = "NULL";
    char uuid[40] = "";
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

/**
 * @brief Parses command from a given string that starts with an exclamation mark
 * 
 * @param buffer 
 * @param buffer_length 
 * @param command 
 * @param command_length 
 * @return size_t 
 */
size_t parseCommandFromString(const char *buffer, size_t buffer_length, char *command, size_t command_length)
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
    
    while (true) {
        
        if (Serial.available()) {
            Serial.println("@ Init stage");
            String message = Serial.readString();
            
            #ifdef DEV_DEBUG
            {
                Serial.print("\nDebug hex raw: ");
                Serial.printf("\nDebug hex raw: %s\n", message.c_str());
                for(const char c : message) {
                    Serial.printf("%02X ", c);
                }
            }
            #endif
            
            Serial.println("Reached");
            size_t messageLen = message.length();

            if (messageLen && messageLen < 256) {
                // can perform string checks

                Serial.println("@Stage 1");
                
                if (message[0] == '/') {
                    // this is a command from MiClone
                    
                    // bypass mode
                    Serial2.write(reinterpret_cast<const uint8_t *>(message.c_str()), message.length());
                    
                    File miCloneEmulationLog = SD.open(MICLONE_LOG_FILENAME, "w+");
                    if (miCloneEmulationLog) {
                        
                        Serial.printf("File is valid, printing \"%s\"", message.c_str());
                        const char printBuffer[] = "-> ";
                        miCloneEmulationLog.seek(miCloneEmulationLog.size());
                        miCloneEmulationLog.write(reinterpret_cast<const uint8_t *>(printBuffer), strlen(printBuffer));
                        miCloneEmulationLog.write(reinterpret_cast<const uint8_t *>(message.c_str()), message.length());
                    }

                    miCloneEmulationLog.close();
                    delay(10);
                }
                else if (message[0] == '!') {
                    // command from my helper program
                    // todo
                    Serial.println("@Stage2");
                    char command[17] = { 0 };
                    size_t offset = 0;
                    offset = parseCommandFromString(message.c_str(), message.length(), command, sizeof(command));

                    Serial.print("  Result of command: ");
                    Serial.println(command);
                    Serial.print("  Result of strcmp(command, \"ping\"): ");
                    Serial.println(!strcmp(command, "ping"), DEC);

                    if (!strcmp(command, "sd") || !strcmp(command, "spiffs")) {

                        // FS &fs = !strcmp(command, "!sd") ? *(dynamic_cast<fs::FS *>)(&SD) : *(dynamic_cast<fs::FS *>)(&SPIFFS);
                        
                        offset = nextSubString(message.c_str(), offset, message.length(), command, sizeof(command));
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
                    else if (!strcmp(command, "touchscreen")) {
                        assert(false && "This command is not working.");    // possible causes is a bug in the nextSubstring function
                        dev_println("=> Processing touchscreen command...");
                        offset = nextSubString(message.c_str(), offset, message.length(), command, sizeof(command));
                        if (!offset) continue;
                        if (strcmp(command, "rotate")) continue;        // this is in a separate if statement for future reference

                        dev_println("=> Processing rotation sub command...");
                        offset = nextSubString(message.c_str(), offset, message.length(), command, sizeof(command));
                        if (!offset) continue;

                        if (command[0] >= '0' && command[0] < '9') {
                            int rotation = atoi(command);
                            Driver::ts.setRotation(rotation);
                            Serial.printf("-> Rotation set to %d\n", rotation % 4);
                        }
                        else {
                            Serial.println("-> Cannot process request because the arguments passed is invalid");
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
                            f.close();
                        }
                        else {
                            Serial.println("Error: Cannot find device info file. Flash new filesystem image");
                        }
                    }
                    else if (!strcmp(command, "help")) {
                        
                        if (!SPIFFS.exists("/help.txt")) {
                            Serial.println("Error: Cannot find \"help.txt\" in SPIFFS");
                            continue;
                        }

                        File f = SPIFFS.open("/help.txt");
                        if (f.isDirectory()) {
                            Serial.println("Error: \"help.txt\" is a directory and not a file");
                            f.close();
                            continue;
                        }

                        Serial.println(f);
                        f.close();
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
}

#ifdef CHECK_FOR_FIRMWARE_UPDATE
/**
 * @brief Checks Github for updates. If found, an attempt will be made to download the file.
 *          WiFi must be enabled and connected for an OTA update over WiFi to work.
 * 
 * @param params Unused, pass nullptr
 */
void firmwareUpdateCheckerTask(void *params)
{
    while (true) {

        if (WiFi.status() != WL_CONNECTED) {
            delay(30 * 1000);
            continue;
        }

        // get url download information
        char downloadURL[128];
        int branchIndex = WiFiOTAUpdater::branchInList("development");
        if (branchIndex < 0) {

            Serial.println("-> ERROR: Trying to access a branch that does not exist!");
            vTaskDelete(nullptr);
            return;
        }


        StaticJsonDocument<256> metadata;

        HTTPClient request;
        sprintf(downloadURL, BINARY_URL, WiFiOTAUpdater::BRANCHES[branchIndex].path, "meta.json");
        Serial.printf("-> Filepath request: %s", downloadURL);
        request.begin(downloadURL);
        Serial.println("-> Starting request");
        int metaRequestCode = request.GET();
        Serial.println("-> Request GET initiated");
        if (metaRequestCode <= 0) {

            request.end();
            Serial.println("-> Invalid request");
            continue;
        }
        String s = request.getString();
        Serial.printf("The message is: %s", s);
        delay(1000000);
        deserializeJson(metadata, request.getStream());
        serializeJson(metadata, Serial);
        request.end();
        
        if (!metadata.containsKey("firmware") || !metadata["firmware"].containsKey("version")) {
            delay(5 * 60 * 1000);
            continue;
        }
        
        const char *metaversion = metadata["firmware"]["version"];
        char *next;
        int majorVersion = strtol(metaversion, &next, 10);
        int minorVersion = *next == '.' ? strtol(++next, nullptr, 10) : 0;
        
        if (majorVersion > MAJOR_FIRMWARE_VERSION ||
           (majorVersion == MAJOR_FIRMWARE_VERSION && minorVersion > MINOR_FIRMWAR_VERSION))
        {
            sprintf(downloadURL, BINARY_URL, WiFiOTAUpdater::BRANCHES[branchIndex].path, "firmware.bin");
            request.begin(downloadURL);
            if (request.GET()) {

                unsigned long stopwatch = millis();
                
                // init MD5 hasher
                struct MD5Context md5ctx;
                uint8_t md5buff[16] = { 0 };
                MD5Init(&md5ctx);

                // get request stream info
                Stream &stream = request.getStream();
                File f = SD.open("/preload/firmware.bin", "w+");
                uint8_t *buf = new uint8_t[512];
                int bytesRemaining = request.getSize();

                while (bytesRemaining) {
                    // save data to file and add to MD5
                    size_t bytesToSave = std::min(bytesRemaining, 512);
                    stream.readBytes(buf, bytesToSave);
                    f.write(buf, bytesToSave);
                    MD5Update(&md5ctx, buf, bytesToSave);
                    bytesRemaining -= bytesToSave;
                }
                
                MD5Final(md5buff, &md5ctx);
                Serial.printf("Done! Download took %0.3fs. MD5 Hash: ", (millis() - stopwatch) / 1000.0f);
                for (uint8_t i : md5buff) {
                    Serial.printf("%016X ", i);
                }
                Serial.println();

                f.close();
                delete[] buf;
                request.end();
                vTaskDelete(nullptr);

                return;
            }
            request.end();
        }
        // No updates found
        else {
            delay(10 * 60 * 1000);
        }
    }
    
    vTaskDelete(nullptr);
}
#endif


void setup()
{
    Serial.begin(9600);
    Serial.println("\n                  ====== MiOrigin - Bioaersol Collector Controller ======                   ");
    Serial.println(" --- Aersol Technology Lab at the Department of Biological and Agricultural Engineering --- \n");
    Serial.println("\t-> Software and PCB Designed By:     Charlemagne Wong - CECN 21'");
    Serial.println("\t                                     Texas A&M University");
    Serial.println("\t-> Website:                          https://cmasterx.github.io/MiOrigin/");
    Serial.println("\t-> Source Code and Documentation:    https://github.com/cmasterx/MiOrigin");
    Serial.printf("\t-> Firmware Version:                  %d.%d\n", MAJOR_FIRMWARE_VERSION, MINOR_FIRMWAR_VERSION);
    Serial.println("\nType and enter !help to see list of commands");
    Serial.println();
    
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
    
    // initialize common properties between firmware and factory
    // loads spi and i2c drivers
    Common_Init();

    
    Driver::tft_begin(1);

    tft.fillScreen(TFT_BLACK);

    Driver::touchscreen_init();
    Driver::touchscreen_begin(*hspi, 3);
    if (!Driver::touchscreen_busy_check_interrupt(true)) {
        Serial.println("FAIL TO ENABLE TS!");
        for(;;);
    }
    // ts.begin(*hspi);
    // ts.setRotation()
    Driver::Touchscreen_cfg.onPress = []() -> void {
        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
        int response = Driver::Touchscreen_cfg.state;
        xQueueSendFromISR(tsQueue, &response, &xHigherPriorityTaskWoken);

        if (xHigherPriorityTaskWoken) portYIELD_FROM_ISR();
    };
    Driver::Touchscreen_cfg.onRelease = Driver::Touchscreen_cfg.onPress;
    
    tsQueue = xQueueCreate(10, sizeof(int));
    
    TaskFunction_t touchScreenStateChange = [](void *) -> void {
        Serial.println("Starting touch screen");
        while (true) {
            Serial.print("Touch screen touch loop");
            int response;
            if (xQueueReceive(tsQueue, (void *)&response, portMAX_DELAY) == pdTRUE) {

                Serial.printf("Got message from ISR: %d", response);
            }

        }
    };
    
    xTaskCreate(touchScreenStateChange,
                "ts-state",
                1024,
                nullptr,
                1,
                nullptr
                );
    
    tft.setCursor(30, 0, 2);
    tft.setTextColor(TFT_YELLOW);
    tft.setTextSize(2);
    tft.print("Bioaerosol Collector");

    tft.setCursor(10, 50, 2);
    tft.setTextColor(TFT_ORANGE);
    tft.setTextSize(1);
    tft.println("SOFTWARE NOT FINAL");

    tft.setTextColor(TFT_GREEN);
    tft.setTextWrap(true);


    Serial.println("Initializing SD card...");
    tft.println("Initializing SD Card");
    if(!SD.begin(SD_CS, *hspi, 4000000U))
    {
        Serial.println("Error: Cannot open MicroSD card. Check if inserted and mounted correctly");

        tft.setTextColor(TFT_RED);
        tft.println("ERROR: Cannot open MicroSD card. This sometimes happens, rebooting in 3 seconds...");

        for (int i = 3; i > 0; --i) {
            Serial.print("\r");
            Serial.print("                                \r");
            Serial.print("Rebooting in ");
            Serial.print(i);

            for (int j = 3; j > 0; --j) {
                Serial.print('.');
                vTaskDelay(1000 / 3 / portTICK_PERIOD_MS);
            }
        }

        Serial.println("Ending MicroSD card");
        hardReset();
    }
    else {
        Serial.println("SD card mounted!");
        tft.println("SD card mounted!");
        File verify = SD.open("/test.txt", "a+");
        verify.println("Print");
        verify.println("Penguin");
        verify.close();
    }
    digitalWrite(TCH_CS, HIGH);


    /* ----- Initialize Battery Fuel Gauge ----- */

    tft.println("-> Initializing battery fuel gauge... ");
    if (Driver::lipo.begin(Wire)) {

        Driver::lipo.setThreshold(20);
        tft.println("SUCCESS!");
    }
    else {
        tft.setTextColor(TFT_RED);
        tft.println("FAIL");
        tft.setTextColor(TFT_GREEN);
    }


    /* Acquire device information */
    tft.println("Acquiring device information...");
    if (SPIFFS.exists("/device_info")) {
        StaticJsonDocument<512> deviceJSON;
        File f = SPIFFS.open("/device_info", "r");
        deserializeJson(deviceJSON, f);

        // parse and acquire values
        auto acquireValueFromDoc = [&deviceJSON] (const char *key, char *deviceProperty, size_t devicePropertySize) {

            if (deviceJSON.containsKey(key)) {
                std::string data = deviceJSON[key].as<std::string>();
                strlcpy(deviceProperty, data.c_str(), devicePropertySize);
            }
        };

        acquireValueFromDoc("name",   DevinceInfo.deviceName, sizeof(DevinceInfo.deviceName) / sizeof(DevinceInfo.deviceName[0]));
        acquireValueFromDoc("pcbRev", DevinceInfo.pcbRev,     sizeof(DevinceInfo.pcbRev)     / sizeof(DevinceInfo.pcbRev[0])    );
        acquireValueFromDoc("uuid",   DevinceInfo.uuid,       sizeof(DevinceInfo.uuid)       / sizeof(DevinceInfo.uuid[0])      );

        if (deviceJSON.containsKey("id")) {
            uint16_t data = deviceJSON["id"].as<uint16_t>();
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

    // check if new ota firmware exists
    if (SD.exists("/firmware.bin")) {
        tft.println("New firmware exists! Beginning update...");
        SPIFFS.remove("/handoff");
        rebootToFactory();
    }

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

#ifdef CHECK_FOR_FIRMWARE_UPDATE
    xTaskCreate(firmwareUpdateCheckerTask,
                "firm-upd",
                4096 * 3,
                nullptr,
                1,
                nullptr
                );
#endif
        
    // setup RS-232
    tft.print("-> Initializing collector port... ");
    Serial2.begin(9600, SERIAL_8N1, RS232_RX2, RS232_TX2);
    Driver::miclone_begin();
    tft.println("SUCCESS");

    
#ifdef WIFI_CONNECTIVITY_ENABLE
    /* Start WiFi */
    if (!WiFiController.begin()) {
        Serial.println("Error: Failed to start WiFi Controller");
        tft.setTextColor(TFT_RED);
        tft.println("Error: Failed to start WiFi Controller");
        tft.setTextColor(TFT_WHITE);
    }
    else {
        WiFiController.addConnection(new WiFi_WPA_Connection("I Got a Gold Fish 2.4GHz", "Charlemagne13"));
    }
#endif
    
    /* Start Bluetooth */
    // Initialize and Server Info
    tft.println("-> Initializing Bluetooth (BLE)...");
    BLEDevice::init(DevinceInfo.deviceName);
    BLE_Props.pServer = BLEDevice::createServer();
    
    // Service creation
    BLE_Props.device.pService = BLE_Props.pServer->createService(SERVICE_DEVICE_INFO_UUID);
    
    // Characteristic creation 
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

    tft.println("=== DONE! Everything initialized ===");

    File f = SD.open(MICLONE_LOG_FILENAME, "w");
    f.println("\n ------ Session Started -----");
    f.close();

    // encryption
    const char testString[] = "Hello World! This is the message";
    uint8_t key[32];
    uint8_t iv[16] = { 0 };
    uint8_t _iv[16] = { 0 };
    utils::hexchar2bin(AES_KEY, key, sizeof(key) / sizeof(key[0]));
    generateIV(iv, sizeof(iv));
    memcpy(_iv, iv, 16);

    size_t aesBuffSize = (sizeof(testString) + 15) / 16;
    aesBuffSize *= 16;

    unsigned char * encrypted = new unsigned char[aesBuffSize];
    unsigned char * decrypted = new unsigned char[aesBuffSize];

    esp_aes_context ctx;
    esp_aes_init( &ctx );
    esp_aes_setkey(&ctx, key, 256);
    esp_aes_crypt_cbc(&ctx, ESP_AES_ENCRYPT, aesBuffSize, iv, (const unsigned char *)testString, encrypted);
    // memset(iv, 0, 16);
    esp_aes_crypt_cbc(&ctx, ESP_AES_DECRYPT, aesBuffSize, _iv, encrypted, decrypted);
    esp_aes_free(&ctx);

    Serial.print("Encrypted string: ");
    Serial.println((char *)encrypted);
    Serial.print("Decrypted string: ");
    Serial.print((const char *)decrypted);

    #ifndef DISABLE_PAGE_SYSTEM

    /* Initialize Graphics Wrapper for Page System */
    drawingWrapper.drawPixel = [](uint16_t x, uint16_t y, Color color) {
        tft.drawPixel(x, y, color);
    };
    drawingWrapper.drawRect = [](uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t radius, Color color) {
        tft.fillRect(x, y, width, height, color);
    };
    drawingWrapper.print = [](const char *str) {
        tft.print(str);
    };
    drawingWrapper.println = [](const char *str) {
        tft.println(str);
    };
    drawingWrapper.setCursor = [](uint16_t x, uint16_t y, uint8_t font) {
        tft.setCursor(x, y, font);
    };
    drawingWrapper.setTextDatum = [](uint8_t d) {
        tft.setTextDatum(d);
    };
    drawingWrapper.setTextColor = [](Color foreground, Color background) {
        tft.setTextColor(foreground, background);
    };
    drawingWrapper.fillScreen = [](Color color) {
        tft.fillScreen(color);
    };
    drawingWrapper.setTextSize = [](uint8_t size) {
        tft.setTextSize(size);
    };
    drawingWrapper.drawString = [](const char *str, uint32_t x, uint32_t y) {
        tft.drawString(str, x, y);
    };

    Page_t tmpPage;
    
    PageSystem_init(&devicePageManager);
    
    #ifndef DISABLE_CALIBRATION
    Calibration.begin(SPIFFS);
    Calibration.generatePage(tmpPage);
    PageSystem_add_page(&devicePageManager, &tmpPage);
    #endif
    
    DebugPage.generatePage(tmpPage);
    PageSystem_add_page(&devicePageManager, &tmpPage);
    
    PageSystem_start(&devicePageManager);
    // PageSystem_findSwitch(&devicePageManager, CALIBRATION_PAGE_NAME, (void *)0);
    Serial.println("Done!");

    
    PageSystem_findSwitch(&devicePageManager, DEBUG_PAGE_NAME, (void *)0);


    #endif
}

void loop()
{
    #ifdef ENABLE_REPORTING_SYSTEM_STATS_IN_DISPLAY
    #ifdef DEV_DEBUG
    // tft.setCursor(20, 240);
    // tft.setTextColor(TFT_GREEN, TFT_BLACK);
    // tft.println("-- Battery --");
    // tft.printf("  Voltage: %5.3f V  -  Charge Level: %5.0f%%\n", Driver::lipo.getVoltage(), Driver::lipo.getSOC() + 0.5f);
    // tft.print("  Battery State: ");
    // if (!Driver::lipo.getAlert()) {
    //     tft.println("GOOD");
    // }
    // else {
    //     tft.setTextColor(TFT_RED, TFT_BLACK);
    //     tft.println("LOW!");
    // }
    // tft.setTextColor(TFT_GREEN);
    
    // uint16_t x, y;
    // uint8_t z;
    // char buffer[80] = { 0 };

    // ts.readData(&x, &y, &z);
    // tft.setTextColor(TFT_WHITE, TFT_BLACK);
    // sprintf(buffer, "\nTouch Sensor: X: %4d, Y: %4d, Z: %4d\nTouched: %s\n", x, y, z, ts.touched() ? "TRUE" : "FALSE");
    // tft.print(buffer);

    // tft.printf("\n RAM: %.1f%% (%.0f kB, %0.0f kB)", ESP.getFreeHeap() * 100.0f / ESP.getHeapSize(), ESP.getFreeHeap() / 1024.0f, ESP.getHeapSize() / 1024.0f);

    delay(50);

    #endif
    #endif

    #ifdef DEV_DEBUG

    multi_heap_info_t info;
    
    heap_caps_get_info(&info, MALLOC_CAP_INTERNAL);
    float totalRam = (info.total_allocated_bytes + info.total_free_bytes) / 1024.0f;
    float usedRam = info.total_allocated_bytes / 1024.0f;
    dev_printf("Percent RAM: %.0f (%.3fKB / %.3fKB)\n", usedRam / totalRam * 100.0f, usedRam, totalRam);
    vTaskDelay(3000 / portTICK_PERIOD_MS);
    
    #endif
}

#endif
