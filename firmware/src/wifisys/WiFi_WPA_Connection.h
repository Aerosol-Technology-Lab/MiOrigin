#pragma once

#include "WiFiConnection.h"
#include <SPIFFS.h>
#include <FS.h>

class WiFi_WPA_Connection : public WiFiConnection
{
private:
    char pswd[64];
    bool connected = false;

public:
    WiFi_WPA_Connection(const char *ssid, const char *pswd);

    virtual bool connect();

    virtual bool disconnect();

    virtual bool isInUse();
};
