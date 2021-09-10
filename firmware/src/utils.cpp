#include "utils.h"

bool convert_MS2HMSF_format(char *buffer, size_t size, uint32_t time)
{
    if (size < 9) return false;

    uint8_t sec = time % 60;
    time /= 60;
    uint8_t min = time % 60;
    time /= 60;
    uint8_t hr  = time % 60;
    sprintf(buffer, "%d:%d:%d", hr, min, sec);
    
    return true;
}

void utils::hexchar2bin(const char *str, uint8_t *buff, size_t length)
{
    size_t numToProcess = std::min(strlen(str), length * 2);
    const char *strPtr = str;
    uint8_t *buffPtr = buff;
    if (numToProcess && numToProcess % 2) {
        *buffPtr = hexchar2byte(*str);
        ++strPtr;
        ++buffPtr;
        --numToProcess;
    }

    while (numToProcess) {

        // processes two at a time

        *buffPtr = (hexchar2byte(strPtr[0]) << 4) | (hexchar2byte(strPtr[1]));
        strPtr += 2;
        ++buffPtr;
        numToProcess -= 2;
    }
}
