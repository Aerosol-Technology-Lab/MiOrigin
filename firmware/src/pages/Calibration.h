#pragma once

#include <Arduino.h>
#include "pagesystem/page.h"
#include <stdint.h>
#include <FS.h>
#include <SPIFFS.h>
#include <TFT_eSPI.h>

#define CALIBRATION_CFG_FILENAME "/ts_calib.cfg"

class _Calibration
{
private:
    bool isCalibrated;
    float mx;
    float bx;
    float my;
    float by;
    
    const uint16_t *raw_x;
    const uint16_t *raw_y;
    const uint8_t  *raw_z;
    
    FS *fs;

    void *pageArgs;
    
public:

    struct Point {
        uint16_t x;
        uint16_t y;
    };

    _Calibration();

    void begin(FS &fs = SPIFFS);

    void translateFromRaw(uint16_t &x, uint16_t &y, uint16_t xRaw, uint16_t yRaw);

    void calibrate(float mx, float bx, float my, float by);
    
    void drawGrid();
    void drawTarget(uint16_t x, uint16_t y, uint32_t color = TFT_BLUE, uint16_t gap = 10);
    void drawScreen(bool touched=false);

    void calibrationScreen();
    
    static void onStart(void *);
    static void onLoad(void *, void *);
    static void onExit();

    static void generatePage(Page_t &page);
    static Page_t generatePage();

    static void ts_onPress();
    static void ts_onRelease();

};

extern _Calibration Calibration;
