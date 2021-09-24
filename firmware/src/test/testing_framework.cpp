#include "testing_framework.hpp"

#include <HardwareSerial.h>
#include <string.h>

TestFramework::TestFramework(const char *name)
{
    strncpy(this->name, name, sizeof(this->name) / sizeof(this->name[0]));
}

void TestFramework::start()
{
    total = 0;
    success = 0;

    stream->printf("    -> Testing %s <-\n", name);
}

void TestFramework::verify(TestFunction_f func)
{
    if (func) {
        ++total;
        char testName[64];
        bool testSuccess = func(testName, sizeof(testName) / sizeof(testName[0])) == TEST_OK;

        ++success;

        // Serial.printf("Address of stream 0x%08x - Address of testName 0x%08x", (size_t) stream, (size_t) testName);
        // delay(1000);
        
        // Serial.print(*testName);
        delay(100);
        stream->printf("[%6s] : %s\n", (testSuccess ? "SUCCESS" : "FAIL"), testName);
    }
}

void TestFramework::end()
{
}

void TestFramework::results(size_t *_success, size_t *_total)
{
    if (_success) *_success = this->success;
    if (_total) *_total = this->total;

    stream->printf("=> Results: %.1f%% tests passed [%d / %d]\n", 100.0f * (float)(success) / (float)(total), success, total);
}

Stream *TestFramework::stream = &Serial;
