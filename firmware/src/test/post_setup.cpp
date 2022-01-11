#include "post_setup.hpp"

#include "testing_framework.hpp"
#include "../config.h"
#include <SD.h>
#include <Arduino.h>
#include <assert.h>


#ifndef POST_SETUP_TEST

// nothing and this should not be called
void postSetupTest() 
{
    assert(false && "Post Setup tests should not be called in production or when POST_SETUP_TEST flag is disabled");
}        

// #error this should not compile

#else

TestResult_t postTestStart(char * testName, size_t buffSize)
{
    strncpy(testName, "Post Test Start", buffSize);
    return TEST_OK;
}

TestResult_t fileTest(char *testName, size_t buffSize)
{
    const size_t INITIAL_CONTENTS_SIZE = 256;
    strncpy(testName, "File Test", buffSize);

    char buffer[64];
    sprintf(buffer, "Reference [%d] File Test\n\0", random(9999));
    size_t buffLength = strlen(buffer);
    uint8_t *initialContents = new uint8_t[INITIAL_CONTENTS_SIZE];
    size_t initialBytesRead = 0;

    // write to file
    {
        File f = SD.open("/filetest.txt", "a+");
        initialBytesRead = f.read(initialContents, INITIAL_CONTENTS_SIZE);
        f.seek(f.size());
        f.write((const uint8_t *)buffer, buffLength);
        f.close();
    }

    // test check
    TestResult_t result = TEST_UNKNOWN;
    {
        File f = SD.open("/filetest.txt", "r");
        uint8_t *dataRetained = new uint8_t[initialBytesRead];
        size_t dataRetainedSize = f.read(dataRetained, initialBytesRead);
        
        // check if data retained before writing
        if (dataRetainedSize != initialBytesRead || !!memcmp(dataRetained, initialContents, initialBytesRead)) {
            result = TEST_FAIL;
        }
        
        delete[] dataRetained;

        // verify ending contents
        if (result == TEST_UNKNOWN) {

            int seek = f.size() - buffLength;
            if (seek >= 0) {

                f.seek(seek);
                uint8_t *newDataWritten = new uint8_t[buffLength];
                memset(newDataWritten, 0, buffLength);
                size_t newDataWrittenSize = f.read(newDataWritten, buffLength);

                result = newDataWrittenSize != buffLength || !!memcmp(newDataWritten, buffer, buffLength) ? TEST_FAIL : TEST_OK;
                delete[] newDataWritten;
            }
            else {
                result = TEST_FAIL;
            }

        }
        
        // if (result == TEST_UNKNOWN) result = TEST_OK;
        
        f.close();
    }

    delete[] initialContents;

    return result;
}

void postSetupTest()
{
    TestFramework test("Post Setup Tests");
    test.start();

    test.verify(postTestStart);
    test.verify(fileTest);
    test.verify(fileTest);
    test.verify(fileTest);
    
    test.end();
    test.results();
}

#endif
