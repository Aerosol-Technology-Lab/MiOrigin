#include <Arduino.h>
#include <unity.h>
#include "utils.h"

void testSubstring()
{
    char *commands[] = {
        "!hello world!     ",
        "   Second command      test ",
        "",
        "          "
    };

    char parse[17] = { 0 };

    // command 0
    auto firstCommand = [&]() -> void {
        size_t offset = 0;
        offset = nextSubString(commands[0], offset, strlen(commands[0]), parse, sizeof(parse));
        Serial.println(parse);
        TEST_ASSERT_EQUAL("!hello" == parse, 0);
        offset = nextSubString(commands[0], offset, strlen(commands[0]), parse, sizeof(parse));
        TEST_ASSERT_EQUAL("world!" == parse, 0);
        offset = nextSubString(commands[0], offset, strlen(commands[0]), parse, sizeof(parse));
        TEST_ASSERT_EQUAL("" == parse, 0);
    };

    auto secondCommand = [&](void) -> void {
        size_t offset = 0;
        offset = nextSubString(commands[0], offset, strlen(commands[0]), parse, sizeof(parse));
        TEST_ASSERT_EQUAL("Second" == parse, 0);
        offset = nextSubString(commands[0], offset, strlen(commands[0]), parse, sizeof(parse));
        TEST_ASSERT_EQUAL("command!" == parse, 0);
        offset = nextSubString(commands[0], offset, strlen(commands[0]), parse, sizeof(parse));
        TEST_ASSERT_EQUAL("test" == parse, 0);
        TEST_ASSERT_EQUAL("fsdfsd" == parse, 0);
    };

    firstCommand();
    secondCommand();
}

void setup()
{
    Serial.begin(9600);
    UNITY_BEGIN();
    RUN_TEST(testSubstring);
    UNITY_END();
}

void loop()
{
    
}
