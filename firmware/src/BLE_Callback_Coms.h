#pragma once

#include <BLEDevice.h>
#include <FreeRTOS.h>

#define BLECC_CHARACTERISTIC_UUID "f5db5ef9-c1d0-4d1b-8907-d3f2075872c5"

#define BLECC_getProps(packet) reinterpret_cast<Props_t *>(packet)
#define BLECC_getCommand(packet) packet + 2


class BLE_Callback_Coms : public BLECharacteristicCallbacks
{
public:
    using BLE_Packet_t = uint8_t[27];
    using Props_t = uint16_t;
    using Command_t = uint8_t;

    const static Props_t PROPS_NONE    = (Props_t) 0x0000;
    const static Props_t PROPS_SUCCESS = (Props_t) 0x0001;
    const static Props_t PROPS_FAIL    = (Props_t) 0x0002;

    const static Command_t COMMAND_FLUSH              = (Command_t) 0x00;
    const static Command_t COMMAND_WRITE              = (Command_t) 0x01;
    const static Command_t COMMAND_SUBMIT             = (Command_t) 0x02;
    const static Command_t COMMAND_CLEAR_WRITE        = (Command_t) 0x03;
    const static Command_t COMMAND_READ               = (Command_t) 0x04;
    const static Command_t COMMAND_REC_BUFFER_SIZE    = (Command_t) 0x05;
    const static Command_t COMMAND_BYTES_LEFT         = (Command_t) 0x06;
    const static Command_t COMMAND_STRING             = (Command_t) 0x07;
    const static Command_t COMMAND_PRINT_REC_BUFFER   = (Command_t) 0x08;
    
    char sendBuffer[256] = { 0 };

private:
    char receiveBuffer[256] = { 0 };
    uint16_t recSize = 0;

    bool readReady = false;
    bool writeable = true;

    TaskHandle_t *task = nullptr;

public:

    void onWrite(BLECharacteristic *pCharacteristic);

    void registerTask(TaskHandle_t *task);

    const char * getReadBuffer();
};
