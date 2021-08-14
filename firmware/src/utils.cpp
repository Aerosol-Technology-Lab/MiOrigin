#include "utils.h"

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
