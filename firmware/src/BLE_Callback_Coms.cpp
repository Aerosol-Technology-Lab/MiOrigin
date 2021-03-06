#include "BLE_Callback_Coms.h"
#include <BLEDevice.h>
#include <FreeRTOS.h>
#include <Arduino.h>
#include <SD.h>

/**
 * @brief macro for when client requests to server to respond to confirm command
 *        is processed.
 */
#define DEFAULT_RESPONSE_FOR_SERVER_REQUEST_TO_RESPOND(props) if (props & PROPS_REQUEST_FOR_SERVER_RESPONSE) {  \
                                                                    *responseProps |= PROPS_SUCCESS;                \
                                                                    *responseCommand = *receivedCommand;            \
                                                                    pCharacteristic->setValue(responsePacket, mtu); \
                                                                    }                                           \

#define NOTIFY_IF_REQUESTED(receivedProps) if (receivedProps & PROPS_REQUEST_FOR_NO_NOTIFY) pCharacteristic->notify();


BLE_Callback_Coms::BLE_Callback_Coms()
{
    responsePacket = new uint8_t[mtu];
}

BLE_Callback_Coms::~BLE_Callback_Coms()
{
    delete[] responsePacket;
}

void BLE_Callback_Coms::onWrite(BLECharacteristic *pCharacteristic)
{
    #ifdef DEV_DEBUG
    Serial.println("On Write received from BLE_Callback_Coms");
    #endif
    
    uint8_t *receivedPacket = pCharacteristic->getData();

    Props_t *receivedProps     = BLECC_getProps(receivedPacket);
    Command_t *receivedCommand = BLECC_getCommand(receivedPacket);

    /* Packet to send (if needed) */
    memset(responsePacket, 0, mtu);                                     // * Benchmark this if this should be deleted
    Props_t *responseProps     = BLECC_getProps(responsePacket);
    *responseProps |= PROPS_SERVER_RESPONSE;
    Command_t *responseCommand = BLECC_getCommand(responsePacket);

    switch (*receivedCommand) {
            
        // request to write to buffe
        case COMMAND_WRITE: {
            uint16_t *writeHeader = reinterpret_cast<uint16_t *>(receivedPacket + 3);
            uint16_t address = *writeHeader & 0x07FF;
            uint8_t size = *writeHeader >> 11;
    
            #ifdef DEV_DEBUG
            char tmpbuff[64] = { 0 };
            sprintf(tmpbuff, "Addr: %04X - Size: %02X", address, size);
            Serial.print(tmpbuff);
            #endif
    
            if (size > (2 + 1 + 2) ||                                                   //  2 (props) + 1 (command) + 2 (address and size) 
                address + size > sizeof(mainBuffer) / sizeof(mainBuffer[0])) {
                
                *responseProps |= PROPS_FAIL;
                *responseCommand = COMMAND_STRING;
    
                char *message = reinterpret_cast<char *>(responsePacket + 3);
                strlcpy(message, "ERR: Out of bounds", mtu - 3);
    
                pCharacteristic->setValue(responsePacket, mtu);
                pCharacteristic->notify();
                break;
            }
            
            memcpy(&mainBuffer[address], receivedPacket + 5, size);
            
            DEFAULT_RESPONSE_FOR_SERVER_REQUEST_TO_RESPOND(*responsePacket);
            NOTIFY_IF_REQUESTED(*receivedProps);
            
            break;
        }
    
        case COMMAND_REC_BUFFER_SIZE: {
    
            *responseProps |= PROPS_SUCCESS;
            *responseCommand = COMMAND_REC_BUFFER_SIZE;
            uint16_t *data = reinterpret_cast<uint16_t *>(responsePacket + 3);
            *data = this->recSize;
            
            pCharacteristic->setValue(responsePacket, mtu);
            NOTIFY_IF_REQUESTED(*receivedProps);
            break;
        }

        case COMMAND_PRINT_REC_BUFFER: {
            char tmp[64];
            strlcpy(tmp, mainBuffer, sizeof(tmp) / sizeof(tmp[0]));
            Serial.println(tmp);
            NOTIFY_IF_REQUESTED(*receivedProps);
            break;
        }

        case COMMAND_STAGE_SMALL_BUFFER: {
            memcpy(smallBuffer, mainBuffer, smallBufferSize);

            DEFAULT_RESPONSE_FOR_SERVER_REQUEST_TO_RESPOND(*responsePacket);
            NOTIFY_IF_REQUESTED(*receivedProps);
            
            break;
        }

        case COMMAND_PULL_SMALL_BUFFER: {
            memcpy(mainBuffer, smallBuffer, smallBufferSize + 1);
            
            DEFAULT_RESPONSE_FOR_SERVER_REQUEST_TO_RESPOND(*responseProps);
            if (*receivedProps & PROPS_REQUEST_FOR_NO_NOTIFY) pCharacteristic->notify();
            
            break;
        }

        case COMMAND_SIZE_SMALL_BUFFER: {
            *responseProps |= PROPS_SERVER_RESPONSE;
            uint16_t *packetSmallBufferSize = reinterpret_cast<uint16_t *>(responsePacket + 3);
            *packetSmallBufferSize = smallBufferSize;
            
            pCharacteristic->setValue(responsePacket, mtu);
            if (*receivedProps & PROPS_REQUEST_FOR_NO_NOTIFY) pCharacteristic->notify();
            
            break;
        }

        case COMMAND_CLEAR_SMALL_BUFFER: {
            memset(smallBuffer, 0, smallBufferSize);

            DEFAULT_RESPONSE_FOR_SERVER_REQUEST_TO_RESPOND(*responseProps);
            if (*receivedProps & PROPS_REQUEST_FOR_NO_NOTIFY) pCharacteristic->notify();
            
            break;
        }

        case COMMAND_MTU_SETTING: {
            Command_t *subCommand = receivedPacket + 3;

            switch (*subCommand) {
                case SUBCOMMAND_MTU_FULL_SEND: {
                    const size_t tmpBufferSize = 512;
                    uint8_t *tmpBuffer = new uint8_t[tmpBufferSize];
                    memset(tmpBuffer, 0xFF, tmpBufferSize);

                    Props_t *tmpProps = BLECC_getProps(tmpBuffer);
                    Command_t *tmpCommand = BLECC_getCommand(tmpBuffer);

                    *tmpProps = PROPS_SUCCESS | PROPS_SERVER_RESPONSE;
                    *tmpCommand = COMMAND_MTU_SETTING;

                    pCharacteristic->setValue(tmpBuffer, tmpBufferSize);
                    pCharacteristic->indicate();
                    
                    delete[] tmpBuffer;
                }
            }

            break;
        }

        case COMMAND_FILE_CREATE: {
            char filename[smallBufferSize + 1] = { 0 };
            strncpy(filename, smallBuffer, smallBufferSize);
            
            File f = SD.open(filename, "w+");
            f.close();

            DEFAULT_RESPONSE_FOR_SERVER_REQUEST_TO_RESPOND(*responseProps);
            if (*receivedProps & PROPS_REQUEST_FOR_NO_NOTIFY) pCharacteristic->notify();

            break;
        }

        case COMMAND_FILE_DELETE: {
            char filename[smallBufferSize + 1] = { 0 };
            strncpy(filename, smallBuffer, smallBufferSize);
            bool success = SD.remove(filename);
            
            if (*responseProps & PROPS_REQUEST_FOR_SERVER_RESPONSE) { 
                *responseProps |= success ? PROPS_SUCCESS : PROPS_FAIL;
                pCharacteristic->setValue(responsePacket, mtu);
            }
            if (*receivedProps & PROPS_REQUEST_FOR_NO_NOTIFY) pCharacteristic->notify();

            break;
        }

        case COMMAND_FILE_INFO: {
            assert(false /* Implement this */);
        }

        /* Packet Pattern: [2 Props, 1 Command, 2 size in bytes to write to file from main buffer] */
        case COMMAND_FILE_APPEND: {
            // check if file exists
            char filename[smallBufferSize + 1] = { 0 };
            strncpy(filename, smallBuffer, smallBufferSize);
            
            if (!SD.exists(filename)) {
                *responseProps |= PROPS_FAIL;
                strncpy(reinterpret_cast<char *>(responsePacket + 3), "Err: File not exists", mtu - 3);
                pCharacteristic->setValue(responsePacket, mtu);
                if (*receivedProps & PROPS_REQUEST_FOR_NO_NOTIFY) pCharacteristic->notify();

                break;
            }

            // check buffer size
            size_t bufferSizeRequestToWrite = *reinterpret_cast<uint16_t *>(receivedPacket + 3);
            if (bufferSizeRequestToWrite > sizeof(mainBuffer) / sizeof(mainBuffer[0])) {
                *responseProps |= PROPS_FAIL;
                strncpy(reinterpret_cast<char *>(responsePacket + 3), "Err: Buffer overflow", mtu - 3);
                pCharacteristic->setValue(responsePacket, mtu);
                if (*receivedProps & PROPS_REQUEST_FOR_NO_NOTIFY) pCharacteristic->notify();

                break;
            }

            // create file and append
            File f = SD.open(filename);
            uint16_t bytesToWrite = bufferSizeRequestToWrite == 0 ? sizeof(mainBuffer) / sizeof(mainBuffer[0]) : bufferSizeRequestToWrite;
            f.write(reinterpret_cast<uint8_t *>(mainBuffer), bytesToWrite);
            
            DEFAULT_RESPONSE_FOR_SERVER_REQUEST_TO_RESPOND(*responseProps);
            if (*receivedProps & PROPS_REQUEST_FOR_NO_NOTIFY) pCharacteristic->notify();

            break;
        }
    }
}



const char * BLE_Callback_Coms::getReadBuffer()
{
    return mainBuffer;
}

bool BLE_Callback_Coms::resizeMTU(uint16_t size)
{
    delete[] responsePacket;
    responsePacket = new uint8_t[size];
    mtu = size;
    return true;
}
