#pragma once

#include <Stream.h>
#include <stddef.h>
#include <stdint.h>


enum TestResult_t : int8_t
{
    TEST_FAIL = -1,
    TEST_UNKNOWN = 0,
    TEST_OK = 1,
};

typedef TestResult_t (*TestFunction_f)(char *name, size_t buffSize);

class TestFramework
{
private:
    char name[32];

    size_t total;
    size_t success;

public:
    
    static Stream *stream; 

    TestFramework(const char *name);

    void start();

    void verify(TestFunction_f func);
    
    void end();

    void results(size_t *success=nullptr, size_t *total=nullptr);
};
