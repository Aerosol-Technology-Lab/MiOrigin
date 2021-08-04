#pragma once

namespace WiFiOTAUpdater
{
    typedef struct
    {
        const char *name;
        const char *path;
    } branch_t;

    int branchInList(const char *key);

    extern const branch_t BRANCHES[2];
}

