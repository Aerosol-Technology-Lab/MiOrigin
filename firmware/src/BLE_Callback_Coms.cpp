#include "BLE_Callback_Coms.h"
#include <BLEDevice.h>
#include <FreeRTOS.h>
#include <Arduino.h>

void BLE_Callback_Coms::onWrite(BLECharacteristic *pCharacteristic)
{
    #ifdef DEV_DEBUG
    Serial.println("On Write received from BLE_Callback_Coms");
    #endif
    
    uint8_t *buffer = pCharacteristic->getData();

    Props_t *props     = BLECC_getProps(buffer);
    Command_t *command = BLECC_getCommand(buffer);

    /* Packet to send (if needed) */
    BLE_Packet_t sendPacket = { 0 };
    Props_t *sendProps     = BLECC_getProps(sendPacket);
    Command_t *sendCommand = BLECC_getCommand(sendPacket);

    switch (*command) {
            
        // request to write to buffe
        case COMMAND_WRITE: {
            uint16_t *writeHeader = reinterpret_cast<uint16_t *>(buffer + 3);
            uint16_t address = *writeHeader & 0x07FF;
            uint8_t size = *writeHeader >> 11;
    
            #ifdef DEV_DEBUG
            char tmpbuff[64] = { 0 };
            sprintf(tmpbuff, "Addr: %04X - Size: %02X", address, size);
            Serial.print(tmpbuff);
            #endif
    
            if (size > (2 + 1 + 2) ||                                                   //  2 (props) + 1 (command) + 2 (address and size) 
                address + size > sizeof(receiveBuffer) / sizeof(receiveBuffer[0])) {
                *sendProps = PROPS_FAIL;
                *command = COMMAND_STRING;
    
                char *message = reinterpret_cast<char *>(sendPacket + 3);
                strlcpy(message, "ERR: Out of bounds", 24);
    
                pCharacteristic->setValue(sendPacket, 27);
                pCharacteristic->indicate();
                break;
            }
            
            memcpy(&receiveBuffer[address], buffer + 5, size);
            
            *sendProps = PROPS_SUCCESS;
            *sendCommand = COMMAND_WRITE;
            pCharacteristic->setValue(sendPacket, 27);
            pCharacteristic->indicate();
            
            break;
        }
    
        case COMMAND_REC_BUFFER_SIZE: {
    
            *sendProps = PROPS_SUCCESS;
            *sendCommand = COMMAND_REC_BUFFER_SIZE;
            uint16_t *data = reinterpret_cast<uint16_t *>(sendPacket + 3);
            *data = this->recSize;
            
            pCharacteristic->setValue(sendPacket, 27);
            pCharacteristic->indicate();
            break;
        }

        case COMMAND_PRINT_REC_BUFFER: {
            char tmp[64];
            strlcpy(tmp, receiveBuffer, sizeof(tmp) / sizeof(tmp[0]));
            Serial.print(tmp);
        }
    }
}

const char * BLE_Callback_Coms::getReadBuffer()
{
    return receiveBuffer;
}
