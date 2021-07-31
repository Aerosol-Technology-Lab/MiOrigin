#include "WiFiController.h"
#include <FreeRTOS.h>

_WiFiController::_WiFiController()
{
    if (initialized) {
        throw WiFiControllerAlreadyInitializedException();
    }

    initialized = true;
}

bool _WiFiController::begin()
{
    static bool initialized = false;
    if (initialized) return false;
    
    initialized = true;

    mutexConnections = xSemaphoreCreateMutex();
    binSemaphoreWiFiAlive = xSemaphoreCreateBinary();
    
    xTaskCreatePinnedToCore(
        _WiFiController::keepWiFiAliveTask, 
        "wifi-wake", 
        1024,
        nullptr,
        1,
        &WiFiController.taskHandlerKeepWiFiAwake,
        !CONFIG_ARDUINO_RUNNING_CORE);

    enableWiFi(true);
    return true;
}

bool _WiFiController::addConnection(WiFiConnection *newConnection) {

    xSemaphoreTake(mutexConnections, portMAX_DELAY);

    for (WiFiConnection *&connection : WiFiController.connections) {

        if (!connection) {
            connection = newConnection;
            return true;
        }
    }

    xSemaphoreGive(mutexConnections);
    
    return false;
}

WiFiConnection *_WiFiController::removeConnection(WiFiConnection *toRemove)
{
    xSemaphoreTake(mutexConnections, portMAX_DELAY);

    for (WiFiConnection *&connection : WiFiController.connections) {

        if (connection && connection == toRemove) {
            connection = nullptr;
            xSemaphoreGive(mutexConnections);
            return connection;
        }
    }

    xSemaphoreGive(mutexConnections);
    
    return false;
}

WiFiConnection *_WiFiController::removeConnection(size_t index)
{
    if (index > MAX_AP) return false;
    
    xSemaphoreTake(mutexConnections, portMAX_DELAY);

    if (connections[index]) {
        WiFiConnection *removedConnection = connections[index];
        connections[index] = nullptr;
        xSemaphoreAltGive(mutexConnections);
        return removedConnection;
    }

    xSemaphoreGive(mutexConnections);
    
    return nullptr;
}

void _WiFiController::enableWiFi(bool state)
{
    if (state) {
        WiFi.disconnect(false);
        WiFi.mode(WIFI_STA);
        delay(100);
        xSemaphoreGive(binSemaphoreWiFiAlive);
    }
    else {
        xSemaphoreTake(binSemaphoreWiFiAlive, portMAX_DELAY);
        WiFi.disconnect(true);
    }
}

void _WiFiController::enableWiFiSleep(bool state)
{
    WiFi.setSleep(state);
}

void _WiFiController::keepWiFiAliveTask(void *)
{
    while (true) {

        xSemaphoreTake(WiFiController.binSemaphoreWiFiAlive, portMAX_DELAY);

        if (WiFi.status() == WL_CONNECTED) {
            const static int nextCheckTimeMS = 3 * 60 * 1000;
            delay(nextCheckTimeMS);
            continue;
        }
        if (WiFiController.currentConnection) {
            WiFiController.currentConnection->disconnect();
            WiFiController.currentConnection = nullptr;
        }
        
        // scan for matching ssids
        uint16_t numAailableNetworks = WiFi.scanNetworks();
        for (uint16_t i = 0; i < numAailableNetworks; ++i) {
            
            String ssid = WiFi.SSID(i);
            bool connectionEstablished = false;
            xSemaphoreTake(WiFiController.mutexConnections, portMAX_DELAY);
            for (WiFiConnection *&connection : WiFiController.connections) {

                if (!connection) continue;      // if null, then there is no wifi connection

                if (!strcmp(connection->ssid, ssid.c_str())) {
                    // found ssis matches in possible connections
                    
                    connection->connect();

                    const static size_t maxWaitTime = 5 * 60 * 1000;        // total time before it gives up and goes to next connection
                    const static size_t waitInterval = 500;                 // how often to check for WiFi connection

                    for (size_t j = 0; j < maxWaitTime; j += waitInterval) {

                        if (WiFi.status() == WL_CONNECTED) {
                            WiFiController.currentConnection = connection;
                            connectionEstablished = true;
                            break;
                        }

                        delay(waitInterval);
                    }

                    if (connectionEstablished) break;

                    connection->disconnect();
                }

            }

            xSemaphoreGive(WiFiController.mutexConnections);
            if (connectionEstablished) break;
        }
        
        xSemaphoreGive(WiFiController.binSemaphoreWiFiAlive);
        
        if (WiFi.status() == WL_CONNECTED) {
            vTaskDelay(1 * 60 * 1000 / portTICK_RATE_MS);
        }
        else{
            vTaskDelay(5 * 1000 / portTICK_RATE_MS);
        }
    }

    vTaskDelete(nullptr);
}
