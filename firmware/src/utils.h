#pragma once

#include <Arduino.h>
#include <string>
#ifdef DEV_DEBUG
#include <SD.h>
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef ESP32
// usage static const char[4096] IROM_VAR = "... contents ...";
// refer: https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/memory-types.html
#define IROM_VAR __attribute__((section(".irom.text")))     // does this actually work?

#else
#define IROM_VAR
#endif

#ifdef DEV_DEBUG


    #define dev_print(mess)         Serial.print(mess)
    #define dev_println(mess)       Serial.println(mess)
    #define dev_printf(mess, ...)   Serial.printf(mess, ##__VA_ARGS__)
    #define dev_file(mess)          {                                           \
                                        File f = SD.open("debug.log", "a+");    \
                                        f.seek(f.size());                       \
                                        const char separator[] = "[LOG]: ";     \
                                        f.write(separator, sizeof(separator));  \
                                        f.write(mess, strlen(mess));            \
                                        f.close();                              \
                                    }                                           
#elif
    #define dev_print(mess)
    #define dev_println(mess)
    #define dev_printf(mess, ...)
    #define dev_file(mess)
#endif

#define hexchar2byte(h) ((h >= '0') && (h <= '9') ? (h - '0') : ((h - 'a') + 10))

#define generateIV(buffer, length) esp_fill_random((uint8_t *) buffer, length)

/**
 * @brief substring from a c-string
 * @credit https://www.programmingsimplified.com/c/source-code/c-substring
 * 
 * @param s source
 * @param sub target
 * @param p offset index
 * @param l number of characters to copy
 */
static void substr(const char s[], char sub[], int p, int l) {
   int c = 0;
   
   while (c < l) {
      sub[c] = s[p+c-1];
      c++;
   }
   sub[c] = '\0';
}

static size_t nextSubString(const char *buffer, size_t offset, size_t buffer_length, char *command, size_t command_length)
{
    auto isEnd = [](char c) { return c == ' ' || c == '\r' || c == '\n' || c == '\0'; };

    while (isEnd(buffer[offset]) && offset < buffer_length) offset++;

    // find terminating char
    size_t endIdx = 0;
    for (size_t i = offset + 1; i < buffer_length && i - offset < command_length - 1; ++i) {
        if (isEnd(buffer[i])) {
            endIdx = i;
            break;
        }
    }
    
    if (!endIdx) return 0;

    substr(buffer, command, offset, endIdx - offset);

    return endIdx;
}

static void utilsPrint(const char *buffer, Stream &stream = Serial)
{
    stream.print(buffer);
    stream.print('\0');
}

/**
 * @brief Converts all characters (if possible) in a c_string to lowercase
 * 
 * @param buffer c_string
 * @param size size of c_string. If left empty, funciton will limit number of characters to
 *             strlen(buffer). If null terminator is reached before the end of the size,
 *             characters at and after the null terminator will not be lowercased
 */
static void lower(char *buffer, size_t size = std::numeric_limits<size_t>::max())
{
    for (size_t i = 0; i < min(size, strlen(buffer)); ++i) {
        buffer[i] = toLowerCase(buffer[i]);
    }
}

bool convert_MS2HMSF_format(char *buffer, size_t size, uint32_t time);

namespace utils
{
    int stoi(const std::string &str);

    void hexchar2bin(const char *str, uint8_t *buff, size_t length);
}

#ifdef __cplusplus
}       // extern "C"
#endif
