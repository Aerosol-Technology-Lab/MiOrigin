#pragma once

#include <WiFi.h>
// delete these libraries below
// #include <AsyncTCP.h>
// #include <ESPAsyncWebServer.h>

#define SOCKET_URL "192.168.1.116"
#define SOCKET_PORT 2000

class _ControllerWebSocket
{
private:
    WiFiClient socket;

public:
    _ControllerWebSocket();

    static bool begin();

    static void socketTask(void *args);
};

extern void *_ControllerWebSocketData[sizeof(_ControllerWebSocket)];
extern _ControllerWebSocket *ControllerWebSocket;
