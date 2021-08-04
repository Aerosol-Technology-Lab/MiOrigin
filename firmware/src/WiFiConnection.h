#pragma once

class _WiFiController;      // forward declaration to avoid circular reference

class WiFiConnection
{
protected:
    /**
     * @brief ssid of WiFi connection
    */
    char ssid[33] = { 0 };

    /**
     * @brief If true, WiFiController will use this connection
     */
    bool active = true;

public:

    virtual ~WiFiConnection();

    /**
     * @brief Initialize WiFi connection with the connection's parameters
     * 
     * @return true Initialized successfully
     * @return false Failed to initialize
     */
    virtual bool connect() = 0;

    /**
     * @brief Disconnect the WiFi connection if connected. Any cleanup for
     *          this connection is performed
     * 
     * @return true Connection successfully disconnected
     * @return false Connection failed to disconnect or there is nothing to
     *          disconnect
     */
    virtual bool disconnect() = 0;

    /**
     * @brief Return if this connection has been connected
     * 
     * @return true is currently in use
     * @return false not currently in use
     */
    virtual bool isInUse() = 0;

    friend _WiFiController;
};
