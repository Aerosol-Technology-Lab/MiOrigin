#pragma once

#include <ArduinoJson.h>
#include <WiFiClient.h>

#define REMOTE_DEFAULT_HOST "192.168.0.122"
#define REMOTE_DEFAULT_PORT 8013

#define remote_command_match(command, reference) strcmp(command, reference) == 0

typedef bool (*Command_f)(const char *response, const char *command, JsonObject);

class _Remote
{
public:
/* MEMBERS */
private:
    
    char host[32];
    uint16_t port;

    WiFiClient *_client;

    Command_f actionableCommands[1];

/* FUNCTIONS */
public:
    _Remote(const char *host=nullptr, uint16_t port=REMOTE_DEFAULT_PORT);

    void begin();

private:
    void remote_thread();
    
    template <class T>
    void print(const T str)
    {
        _client->print(str);
    }

    template <class T>
    void println(const T str)
    {
        _client->print(str);
        _client->print('\r');
    }
};

/*** COMMANDS ***/
static bool r_ping(const char *response, const char *command, JsonObject obj);
        

extern _Remote Remote;