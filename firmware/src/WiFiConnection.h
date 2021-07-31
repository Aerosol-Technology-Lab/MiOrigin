#pragma once

class _WiFiController;      // forward declaration to avoid circular reference

class WiFiConnection
{
private:
    char ssid[33] = { 0 };

public:

    ~WiFiConnection();

    virtual bool connect() = 0;

    virtual bool disconnect() = 0;

    virtual bool isConnected();

    friend _WiFiController;
};
