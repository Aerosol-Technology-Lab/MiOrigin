#include "Remote.hpp"

#include "wifisys/WiFiController.h"
#include "driver/miclone.hpp"
#include <ArduinoJson.h>
#include <WiFi.h>
#include <FreeRTOS.h>

_Remote::_Remote(const char *host, uint16_t port)
{
    constexpr size_t maxHostLength = sizeof(this->host) / sizeof(this->host[0]) -1;

    if (host) {

        if (strlen(host) > maxHostLength) {
            
            Serial.println("@WARNING: The url specified is longer than expected");
            Serial.println("          Truncating the url, which prevents connection...");
        }
        
        strncpy(this->host, host, sizeof(host) / sizeof(host[0] - 1));
    }
    else {
        strcpy(this->host, REMOTE_DEFAULT_HOST);
    }

    this-> port = port;
}

void _Remote::begin()
{
    #define remote_add_action(command) actionableCommands[c_i++] = command;

    // size_t c_i = 0;
    // remote_add_action(r_ping);

    // Command_f test = [](const char *command, JsonObject obj) -> bool {

    // };

    actionableCommands[0] = r_ping;

    #undef remote_add_action
}

void _Remote::remote_thread()
{
    while (true) {

        WiFiClient client;
        _client = &client;

        if (client.connect(host, port)) {

            println("Request for MiOrigin connection");

            // request for confirmation;
            {
                bool accepted = false;
                
                for (int i = 0; i < 1000; i += 100) {

                    if (client.available()) {
                        String message = client.readStringUntil('\r');

                        if (message == "MiOrigin connection accepted") {
                            accepted = true;
                        }
                        break;
                    }

                    vTaskDelay(100 / portTICK_PERIOD_MS);
                }

                if (!accepted) goto connection_early_exit;
            }

            {
                println("Encryption: false");
                String message = "";
                for (int i = 0; i < 1000; i += 100) {

                    if (client.available()) {
                        String message = client.readStringUntil('\r');
                    }
                    vTaskDelay(100 / portTICK_PERIOD_MS);
                }

                if (message != "Request: accepted") goto connection_early_exit;
        
            }

            while (client.connected()) {

                if (client.available()) {
                    
                    DynamicJsonDocument jsonDoc(1024);
                    {
                        String message = client.readStringUntil('\r');
                        deserializeJson(jsonDoc, message.c_str());
                    }

                    if (!jsonDoc.isNull() && jsonDoc.containsKey("command")) {

                        JsonArray jsonArray = jsonDoc["command"].as<JsonArray>();
                        if (jsonArray.isNull()) continue;

                        for (JsonObject obj : jsonArray) {

                            if (obj.isNull() || !obj.containsKey("com")) continue;

                            const char *command = obj["com"];
                            const size_t maxBufferSize = 4096;
                            char *buffer = new char[maxBufferSize]{ 0 };
                            for (size_t i = 0; i < sizeof(actionableCommands) / sizeof(actionableCommands[0]); ++i) {
                                
                                if (actionableCommands[i])  {

                                    bool requestSendResponse = actionableCommands[0](buffer, command, obj); 
                                    if (requestSendResponse) {
                                        println(buffer);
                                        memset(buffer, 0, maxBufferSize);
                                    }
                                }
                            }
                            delete[] buffer;
                        }
                    }
                }
                else {
                    vTaskDelay(250 / portTICK_PERIOD_MS);
                }
            }

        }
        else {
            vTaskDelay(1000 / portTICK_PERIOD_MS);
        }

        // end connection early
        connection_early_exit:
        client.stop();
        _client = nullptr;
    }
}

bool r_ping(const char *response, const char *command, JsonObject jsonObj)
{
    if (!remote_command_match(command, "ping")) return false;

    StaticJsonDocument<32> doc;
    doc["resp"] = "pong";

    serializeJson(doc, response);

    return true;
}

_Remote Remote;

// create a function called r_cyclone with the same signature as the other remote commands
bool r_cyclone(const char *response, const char *command, JsonObject jsonObj)
{
    if (!remote_command_match(command, "cyclone")) return false;

    // check if jsobobj contains the keys "timed", "rate", "sample", and "duration"
    if (!jsonObj.containsKey("timed") || !jsonObj.containsKey("rate") || !jsonObj.containsKey("sample") || !jsonObj.containsKey("duration")) return false;

    // check if the values of the keys are of the correct type
    if (!jsonObj["timed"].is<bool>() || !jsonObj["rate"].is<int>() || !jsonObj["sample"].is<bool>() || !jsonObj["duration"].is<int>()) return false;

    // extract the values from the json object
    bool timed = jsonObj["timed"];
    int rate = jsonObj["rate"];
    bool sample = jsonObj["sample"];
    int duration = jsonObj["duration"];

    // run the cyclone command with the extracted values
    Driver::miclone_start(timed, rate, sample, duration);
    
    return true;
}