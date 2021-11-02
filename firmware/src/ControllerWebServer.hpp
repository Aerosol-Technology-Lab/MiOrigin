#pragma once

#include "wifisys/WiFiController.h"
#include <ESPAsyncWebServer.h>
#include <FS.h>
#include <SD.h>
#include <WiFi.h>
#include <Arduino.h>

class _ControllerWebServer
{
private:
    AsyncWebServer server;

public:
    _ControllerWebServer();

    void begin();

    void close();
};

extern _ControllerWebServer ControllerWebServer;
