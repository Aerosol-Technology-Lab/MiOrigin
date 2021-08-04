#include "WiFi_WPA2Enterprise_Connection_TAMU.h"

#include <ArduinoJson.h>
#include <assert.h>
#include <hwcrypto/aes.h>

WiFi_WPA2Enterprise_Connection_TAMU::WiFi_WPA2Enterprise_Connection_TAMU(
    FS &fs,
    const char *credentials,
    const char *pem
    ):
    fs(&fs)

{
    bool success = true;

    if (this->fs->exists(credentials)) {
        throw std::string("Error: File not found - credentials file not found");
    }
    if (this->fs->exists(pem)) {
        throw std::string("Error: File not found - certificate file not found");
    }
    
    File f = this->fs->open(pem, "r");
    char *pemRaw = new char[f.size() + 1];
    memset(pemRaw, 0, f.size() + 1);
    size_t bytesRead = f.readBytes(pemRaw, f.size());
    if (bytesRead != f.size()) {
        success = false;
    }
    
    delete[] pemRaw;
    f.close();
    
    StaticJsonDocument<256> doc;
    assert(false);
}

bool WiFi_WPA2Enterprise_Connection_TAMU::connect()
{
    assert(false);
    return false;
}

bool WiFi_WPA2Enterprise_Connection_TAMU::disconnect()
{
    assert(false);
    return false;
}

bool WiFi_WPA2Enterprise_Connection_TAMU::isInUse()
{
    assert(false);
    return false;
}

bool WiFi_WPA2Enterprise_Connection_TAMU::keysExist(JsonDocument &doc, const char **keys, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        if (!doc.containsKey(keys[i])) return false;
    }

    return true;
}
