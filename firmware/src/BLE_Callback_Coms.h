#pragma once

#include <BLEDevice.h>
#include <FreeRTOS.h>

#define MAX_PACKET_SIZE 512

#define BLECC_CHARACTERISTIC_UUID "f5db5ef9-c1d0-4d1b-8907-d3f2075872c5"

#define BLECC_getProps(packet) reinterpret_cast<Props_t *>(packet)
#define BLECC_getCommand(packet) packet + 2


class BLE_Callback_Coms : public BLECharacteristicCallbacks
{
public:
    // using BLE_Packet_t = uint8_t[27];
    using Props_t = uint16_t;
    using Command_t = uint8_t;

    const static Props_t   PROPS_NONE                                   = (Props_t) 0x0000;
    const static Props_t   PROPS_SUCCESS                                = (Props_t) 0x0001;
    const static Props_t   PROPS_FAIL                                   = (Props_t) 0x0002;
    const static Props_t   PROPS_SERVER_RESPONSE                        = (Props_t) 0x0004;
    const static Props_t   PROPS_CLIENT_RESPONSE                        = (Props_t) 0x0008;
    const static Props_t   PROPS_REQUEST_FOR_SERVER_RESPONSE            = (Props_t) 0x0010;
    const static Props_t   PROPS_REQUEST_FOR_NO_SERVER_RESPONSE         = (Props_t) 0x0020;
    const static Props_t   PROPS_REQUEST_FOR_NO_PREFERENCE_RESPONSE     = (Props_t) 0x0000;
    const static Props_t   PROPS_REQUEST_FOR_NOTIFY                     = (Props_t) 0x0040;
    const static Props_t   PROPS_REQUEST_FOR_NO_NOTIFY                  = (Props_t) 0x0080;

    const static Command_t COMMAND_FLUSH                  = (Command_t) 0x00;
    const static Command_t COMMAND_WRITE                  = (Command_t) 0x01;
    const static Command_t COMMAND_SUBMIT                 = (Command_t) 0x02;
    const static Command_t COMMAND_CLEAR_WRITE            = (Command_t) 0x03;
    const static Command_t COMMAND_READ                   = (Command_t) 0x04;
    const static Command_t COMMAND_REC_BUFFER_SIZE        = (Command_t) 0x05;
    const static Command_t COMMAND_BYTES_LEFT             = (Command_t) 0x06;
    const static Command_t COMMAND_STRING                 = (Command_t) 0x07;
    const static Command_t COMMAND_PRINT_REC_BUFFER       = (Command_t) 0x08;
    const static Command_t COMMAND_STAGE_SMALL_BUFFER     = (Command_t) 0x09;
    const static Command_t COMMAND_PULL_SMALL_BUFFER      = (Command_t) 0x0A;
    const static Command_t COMMAND_SIZE_SMALL_BUFFER      = (Command_t) 0x0B;
    const static Command_t COMMAND_CLEAR_SMALL_BUFFER     = (Command_t) 0x0C;
    const static Command_t COMMAND_MTU_SETTING            = (Command_t) 0x0D;
    const static Command_t COMMAND_FILE_CREATE            = (Command_t) 0x0E;
    const static Command_t COMMAND_FILE_DELETE            = (Command_t) 0x0F;
    const static Command_t COMMAND_FILE_INFO              = (Command_t) 0x10;
    const static Command_t COMMAND_FILE_APPEND            = (Command_t) 0x11;
    
    const static Command_t SUBCOMMAND_MTU_FULL_SEND       = (Command_t) 0x01;
    const static Command_t SUBCOMMAND_MTU_GET             = (Command_t) 0x02;
    const static Command_t SUBCOMMAND_MTU_SET             = (Command_t) 0x03;
    
    
private:
    uint16_t mtu = 128;      // usable MTU (actual MTU - 3 bytes). If MTU is 23 bytes, usable is 20

    char mainBuffer[256] = { 0 };
    uint16_t recSize = 0;

    bool readReady = false;
    bool writeable = true;

    // filename set to process
    const static uint16_t smallBufferSize = 45;
    char smallBuffer[smallBufferSize + 1] = { 0 };

    uint8_t *responsePacket;

    TaskHandle_t *task = nullptr;

public:

    BLE_Callback_Coms();

    ~BLE_Callback_Coms();

    void onWrite(BLECharacteristic *pCharacteristic);

    void registerTask(TaskHandle_t *task);

    const char * getReadBuffer();

private:

    bool resizeMTU(uint16_t size);
    
};
