#include "Calibration.h"
#include <FS.h>
#include <ArduinoJson.h>
#include "driver/tftdisplay.h"
#include "driver/touchscreen.h"
#include "utils.h"

_Calibration::_Calibration()
{
    mx = 0;
    bx = 0;
    my = 0;
    by = 0;
    raw_x = nullptr;
    raw_y = nullptr;
    raw_z = nullptr;
    isCalibrated = true;
}

void _Calibration::begin(FS &fs)
{
    this->fs = &fs;
    float rawCalData[4] = { 0 };

    if (!fs.exists(CALIBRATION_CFG_FILENAME)) {
        File f = fs.open(CALIBRATION_CFG_FILENAME, "w");
        f.write(reinterpret_cast<uint8_t *>(rawCalData), sizeof(rawCalData));
        f.close();
    }
    else {
        File f = fs.open(CALIBRATION_CFG_FILENAME, "r+");
        size_t bytesRead = f.read(reinterpret_cast<uint8_t *>(rawCalData), sizeof(rawCalData));
        f.close();

        // checking errors. If bytesRead < sizeof(rawCalData), then config file is invalid and must be erased
        if (bytesRead < sizeof(rawCalData)) {
            fs.remove(CALIBRATION_CFG_FILENAME);
            begin(fs);          // call this function again, creating a calibration file with no contents
            return;
        }

        mx = rawCalData[0];
        bx = rawCalData[1];
        my = rawCalData[2];
        by = rawCalData[3];
    }
}

void _Calibration::translateFromRaw(uint16_t &x, uint16_t &y, uint16_t xRaw, uint16_t yRaw)
{
    x = uint16_t(mx * xRaw + bx + 0.5f);
    y = uint16_t(my * yRaw + by + 0.5f);
}

void _Calibration::calibrate(float mx, float bx, float my, float by)
{
    this->mx = mx;
    this->bx = bx;
    this->my = my;
    this->by = by;

    #if defined(DEV_DEBUG) || defined(SAFE_CODE)
    assert(fs && "File system is null! fs should not be null");
    #endif
    
    dev_println("-> Creating a file...");
    File f = fs->open(CALIBRATION_CFG_FILENAME, "w");
    dev_println("-> Opened filed successfully");
    float rawData[4] = {
        this->mx,
        this->bx,
        this->my,
        this->by
    };
    dev_println("-> Writing to file...");
    f.write(reinterpret_cast<uint8_t *>(rawData), sizeof(rawData));
    dev_println("-> Writing done, closing...");
    f.close();
    dev_println("-> Closed");
}

void _Calibration::onStart(void *pageArgs)
{
    Serial.println("-> Calibration page started");
    Calibration.pageArgs = pageArgs;
    Driver::touchscreen_get_raw_points(&Calibration.raw_x, &Calibration.raw_y, &Calibration.raw_z);
    Driver::touchscreen_register_on_press(ts_onPress);
    Driver::touchscreen_register_on_release(ts_onRelease);
}

void _Calibration::onLoad(void *, void *toCalibrate)
{
    Calibration.isCalibrated = !((size_t) toCalibrate);

    Serial.println("-> Calibration page loaded");
    Calibration.drawScreen();
}

void _Calibration::onExit()
{
    Serial.println("-> Calibration page exit");
    Driver::touchscreen_register_on_press(nullptr);
    Driver::touchscreen_register_on_press(nullptr);
}

void _Calibration::drawGrid()
{
    Driver::tft.fillScreen(TFT_BLACK);
    const uint16_t gapSize = 20;

    // draw columns
    for (int i = 1; i < TFT_WIDTH / gapSize + 1; ++i) {
        Driver::tft.drawLine(gapSize * i, 0, gapSize * i, TFT_HEIGHT, TFT_LIGHTGREY);
    }
    // draw rows
    for (int i = 1; i < TFT_HEIGHT / gapSize + 1; ++i) {
        Driver::tft.drawLine(0, gapSize * i, TFT_WIDTH, gapSize * i, TFT_LIGHTGREY);
    }
}

void _Calibration::drawTarget(uint16_t x, uint16_t y, uint32_t color, uint16_t gap)
{
    Driver::tft.drawLine(x, 0, x, TFT_HEIGHT, color);
    Driver::tft.drawLine(0, y, TFT_WIDTH, y, color);
}

void _Calibration::drawScreen(bool touched)
{
    Serial.println("-> I am in the draw screen");
    const static uint16_t tGap = 20;
    static Point *points[2] = { nullptr, nullptr };
    // static bool isCalibrated = false;
    const uint16_t &x = *Calibration.raw_x;
    const uint16_t &y = *Calibration.raw_y;
    const uint8_t  &z = *Calibration.raw_z;

    Serial.println("-> Stage 1");

    if (!isCalibrated && touched) {
        Serial.println("-> Stage 2");

        if (!points[0]) {
            Serial.println("-> Stage 3a");
            points[0] = new Point;
            points[0]->x = x;
            points[0]->y = y;
        }
        else if (!points[1]) {
            Serial.println("-> Stage 3b");
            points[1] = new Point;
            points[1]->x = x;
            points[1]->y = y;
        }
    }

    Serial.println("-> Stage 4");
    drawGrid();
    
    // draw first target    
    if (!isCalibrated) {

        if (!points[0]) {
            Serial.println("-> Stage 5a");
            drawTarget(tGap, tGap);
        }
        // draw second target
        else if (!points[1]) {
            Serial.println("-> Stage 5b");
            drawTarget(TFT_WIDTH - tGap, TFT_HEIGHT - tGap);
        }
        else {
            Serial.println("-> Stage 5c");
            // do calibration magic here
            // do x calibration
            float mx = 1.0f * (TFT_WIDTH - tGap - tGap) / (points[1]->x - points[0]->x);
            float bx = tGap - mx * points[0]->x;
            
            dev_println("-> calibrated x");
            
            // do y calibration
            float my = 1.0f * (TFT_HEIGHT - tGap - tGap) / (points[1]->x - points[0]->x);
            float by = tGap - mx * points[0]->x;
            
            dev_println("-> calibrated y");
            
            calibrate(mx, bx, my, by);
            isCalibrated = true;
            
            dev_println("-> Done calibrating");
            
            // cleanup
            delete points[0];
            delete points[1];
            points[0] = nullptr;
            points[1] = nullptr;

            dev_println("-> Cleanup");
        }
    }

    if (touched && isCalibrated) {
        dev_println("-> Drawing here...");
        uint16_t xT, yT;
        translateFromRaw(xT, yT, x, y);
        drawTarget(xT, yT, TFT_RED);
        dev_printf("-> x-equation: xn = %fx + %f --- y-equation yn = %fy + %f", mx, bx, my, by);
        dev_printf("-> Raw is: (%d, %d)", x, y);
        dev_printf("-> Target is: (%d, %d)", xT, yT);
        dev_println("-> Drawing done...");
    }
    Serial.println("-> Stage 6");

}

void _Calibration::generatePage(Page_t &page)
{
    strncpy(page.name, CALIBRATION_PAGE_NAME, PAGE_NAME_SIZE);
    page.params = NULL;
    page.onStart = Calibration.onStart;
    page.onLoad = Calibration.onLoad;
    page.onExit = Calibration.onExit;
}

Page_t _Calibration::generatePage()
{
    Page_t page;
    generatePage(page);
    return page;
}

void _Calibration::ts_onPress()
{ 
    dev_println("This is the touch screen on press handler");
}

void _Calibration::ts_onRelease()
{
    dev_println("This is the touch screen on release handler");
    Calibration.drawScreen(true);
}

_Calibration Calibration;
