#pragma once

#include <FreeRTOS.h>

class MutexRAII
{
private:
    SemaphoreHandle_t &semaphore;

public:
    MutexRAII(SemaphoreHandle_t &semaphore) : semaphore(semaphore)
    {
        xSemaphoreTake(this->semaphore, portMAX_DELAY);
    };

    ~MutexRAII()
    {
        xSemaphoreGive(this->semaphore);
    }
};
