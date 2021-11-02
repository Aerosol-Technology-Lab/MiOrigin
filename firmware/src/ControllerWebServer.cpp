#include "ControllerWebServer.hpp"

#include <AsyncJson.h>
#include <ArduinoJson.h>

_ControllerWebServer::_ControllerWebServer()
    : server(80)
{

}

void _ControllerWebServer::begin()
{

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(SD, "/web/index.html", "text/html");
    });

    // API Requests
    server.on("/api/wifi/list-station", HTTP_GET, [](AsyncWebServerRequest *request) {
        DynamicJsonDocument doc(128);
        JsonArray lists = doc.createNestedArray("ssid");

        int networks = WiFi.scanNetworks();
        for (int i = 0; i < networks; ++i) {

            JsonObject ssidObj = doc.createNestedObject(WiFi.SSID(i));
            ssidObj["rssi"] = WiFi.RSSI(i);
            ssidObj["enc"] = WiFi.encryptionType(i) == WIFI_AUTH_OPEN;
        }       
        
        AsyncResponseStream *response = request->beginResponseStream("application/json");
        const JsonObject &root = doc.as<JsonObject>();
        // response.print(*response);
        
        request->send(response);
    });

    server.serveStatic("/", SD, "/web/");

    server.begin();
}

void _ControllerWebServer::close()
{
    server.end();
}
