#include "WiFiOTAUpdater.h"
#include <Arduino.h>
#include <stddef.h>
#include <string.h>

const WiFiOTAUpdater::branch_t WiFiOTAUpdater::BRANCHES[2] = {
    branch_t {
        .name = "release",
        .path = "main"
    },
    branch_t {
        .name = "development",
        .path = "firmware/dev"
    }
};


int WiFiOTAUpdater::branchInList(const char *key)
{
    Serial.println("Here in this");
    for (int i = 0; i < sizeof(BRANCHES) / sizeof(BRANCHES[0]); ++i) {
        Serial.println("Over here");
        if (!strcmp(BRANCHES[i].name, key)) {
            Serial.println("Found");
            return i;
        }
        Serial.println("not found");
    }

    return -1;
}

