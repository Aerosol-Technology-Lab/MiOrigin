#pragma once

#include <Arduino.h>
#include <WiFi.h>
#include "WiFiConnection.h"
#include <FreeRTOS.h>
#include <exception>

#ifndef MAX_AP
#define MAX_AP 4
#endif

/**
 * @brief Throws when a WiFiController has already been initialized.
 *          there can only be one WiFiController in the whole life
 *          of the program.
 */
class WiFiControllerAlreadyInitializedException : public std::exception
{
public:
    virtual char const *what() const
    {
        return "WiFiController can only be initialized once for the entire life of the program";
    }
};

/**
 * @brief Manages multiple WiFi connections and sleep states for
 *          power management.
 */
class _WiFiController
{
    
private:
    bool initialized = false;

    /**
     * @brief protects access to connections
     */
    SemaphoreHandle_t mutexConnections;
    /**
     * @brief Known WiFi networks to scan for and connect
     */
    WiFiConnection *connections[MAX_AP] = { nullptr };

    /**
     * @brief Current WiFi connection. Null if none connected
     */
    WiFiConnection *currentConnection = nullptr;

    /**
     * @brief State of WiFi if enabled
     */
    bool stateWiFiEnabled = false;

    // once initialized, this should never be null
    SemaphoreHandle_t binSemaphoreWiFiAlive = nullptr;
    TaskHandle_t taskHandlerKeepWiFiAwake = nullptr;

public:
    /**
     * @brief Construct a new wificontroller object.
     */
    _WiFiController();
    ~_WiFiController() {} 

    /**
     * @brief Starts WiFi station and attempts connection
     * 
     * @return true first initialization and succeeded
     * @return false cannot initialize because this function has
     *          been called previously in the past
     */
    bool begin();

    /**
     * @brief Add a WiFi connection
     * 
     * @param newConnection Connection to add
     * @return true Connection was addess to list
     * @return false Failed to add connection because the list is full
     */
    bool addConnection(WiFiConnection *newConnection);

    /**
     * @brief Removes connection from the list
     * 
     * @param toRemove the connection to remove
     * @return WiFiConnection* if found and removed, it returns the connection. If not,
     *          null is returned
     */
    WiFiConnection * removeConnection(WiFiConnection *toRemove);
    /**
     * @brief Removes connection from the list
     * 
     * @param index the index in the list to remove
     * @return WiFiConnection* if found and removed, it returns the connection. If not,
     *          null is returned
     */
    WiFiConnection * removeConnection(size_t index);
    
    /**
     * @brief Enable or disable WiFi. Should be used to reduce power consumption.
     * 
     * @param state true to enable or false to disable
     */
    void enableWiFi(bool state);

    /**
     * @brief Enable WiFi modem sleep
     * @warning You should not use this. Call WiFi.sleep(state) instead. Refer
     *          to this function's definition.
     * 
     * @param state true to enable or false to disable
     */
    void enableWiFiSleep(bool state);

private:
    /**
     * @brief Task that keeps WiFi connection alive. This will suspend if WiFi is
     *          disabled by calling enableWiFi(). Task will resume after WiFi is
     *          resumed
     */
    void static keepWiFiAliveTask(void *);
};

extern _WiFiController WiFiController;
