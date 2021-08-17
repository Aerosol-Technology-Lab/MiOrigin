#include "cpp_wrapper.h"
#include <Arduino.h>

#ifdef __cplusplus
extern "C"
{
#endif

void cprintln(const char *str)
{
    Serial.println(str);
}


#ifdef __cplusplus
}
#endif

