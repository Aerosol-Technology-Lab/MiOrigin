#include "ControllerWebSocket.hpp"

#include <ArduinoJson.h>
#include <string>
#include "utils.h"

_ControllerWebSocket::_ControllerWebSocket()
{
}

bool _ControllerWebSocket::begin()
{
    if (ControllerWebSocket) return false;

    ControllerWebSocket = new (_ControllerWebSocketData) _ControllerWebSocket;

    return true;
}

void _ControllerWebSocket::socketTask(void *args)
{
    while (true) {

        if (WiFi.status() != WL_CONNECTED) {
            delay(1000);
            continue;
        }
        if (!ControllerWebSocket->socket) {

            ControllerWebSocket->socket.stop();
            ControllerWebSocket->socket.connect(SOCKET_URL, SOCKET_PORT);
            
            dev_println("-> There is a WiFi connection but cannot find the server. Trying...");
            delay(50);
            continue;
        }

        dev_println("-> I am connected to the server!");        
        if (ControllerWebSocket->socket.available()) {

            dev_println("-> I see data! Let me read it...");
            const size_t packetSize = 256;
            char *data = new char[packetSize]; 
            ControllerWebSocket->socket.readBytesUntil('\r', data, packetSize);

            DynamicJsonDocument doc(512);
            deserializeJson(doc, data);
            delete[] data;

            serializeJson(doc, Serial);
        }
        
        delay(100);
    }
}

void *_ControllerWebSocketData[sizeof(_ControllerWebSocket)];
_ControllerWebSocket *ControllerWebSocket = nullptr;