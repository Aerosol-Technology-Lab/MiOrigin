#include "WiFiOTAUpdater.h"
#include <stddef.h>
#include <string.h>

const WiFiOTAUpdater::branch_t WiFiOTAUpdater::BRANCHES[2] = {
    branch_t {
        .name = "release",
        .path = "main"
    },
    branch_t {
        .name = "developent",
        .path = "firmware/dev"
    }
};


int WiFiOTAUpdater::branchInList(const char *key)
{
    for (int i = 0; i < sizeof(BRANCHES) / sizeof(BRANCHES[0]); ++i) {
        if (!strcmp(BRANCHES[i].name, key)) return i;
    }

    return -1;
}

