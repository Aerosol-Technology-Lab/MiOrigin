#pragma once

#include "WiFiConnection.h"
#include <SPIFFS.h>
#include <FS.h>
#include <ArduinoJson.h>

class WiFi_WPA2Enterprise_Connection_TAMU : public WiFiConnection
{
private:
    FS *fs;
    uint8_t anonymous_identity[65];
    uint8_t identity[65];
    uint8_t pswd[65];
    uint8_t *certificate;
    
public:
    WiFi_WPA2Enterprise_Connection_TAMU(
        FS &fs = SPIFFS,
        const char *credentials = "/tamu_credentials.json",
        const char *pem         = "/tamu.pem"
        );
    
    // WiFi_WPA2Enterprise_Connection_TAMU(
    //     char *anonymous_identity,
    //     char *identity,
    //     char *pswd,
    //     char *certificate
    //     );

    virtual bool connect();

    virtual bool disconnect();

    virtual bool isInUse();

    bool static keysExist(JsonDocument &doc, const char **keys, size_t size);

// private:
//     void init(
//         uint8_t *anonymous_identity,
//         uint8_t *identity,
//         uint8_t *pswd,
//         uint8_t *certificate
//         );
};
