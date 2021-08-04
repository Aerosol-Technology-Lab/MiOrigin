#include "WiFi_WPA_Connection.h"

#include <WiFi.h>

WiFi_WPA_Connection::WiFi_WPA_Connection(const char *ssid, const char *pswd)
{
    strncpy(this->ssid, ssid, sizeof(this->ssid));
    memset(this->pswd, 0, sizeof(this->pswd));
    strncpy(this->pswd, pswd, sizeof(this->pswd));
}

bool WiFi_WPA_Connection::connect()
{
    WiFi.begin(ssid, pswd);
    connected = true;
    return true;
}

bool WiFi_WPA_Connection::disconnect()
{
    connected = false;
    return WiFi.disconnect();
}

bool WiFi_WPA_Connection::isInUse()
{
    return connected;
}
