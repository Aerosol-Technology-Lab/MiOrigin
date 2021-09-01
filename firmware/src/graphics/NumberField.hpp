// #pragma once

// #define GRAPHICS_NUMBERFIELD_PAGE_NAME
// #define GRAPHICS_NUMBERFIELD_POSTFIX_SIZE 10

// #include "BoundedArea.hpp"
// #include "DrawingWrapper.hpp"
// #include "GraphicsConfig.hpp"
// #include "../pagesystem/page.h"
// #include <stdint.h>

// class NumberField : public BoundedArea
// {
// private:

// protected:
//     Font_t font;
//     Color textColor;
//     int32_t *value;
//     char postfix[GRAPHICS_NUMBERFIELD_POSTFIX_SIZE];

// public:
//     typedef struct {
//         int32_t *value;
//         char returnPageName[PAGE_NAME_SIZE];
//     } NumberFieldPage_t;

//     static NumberFieldPage_t numberfieldPageOptions;

//     /**
//      * @brief Page returned by 
//      */
//     Page_t *returnPage;

//     DrawingWrapper &drw;

// public:
//     NumberField(DrawingWrapper &drw, uint16_t x=0, uint16_t y=0, uint16_t width=0, uint16_t height=0, Font_t fnt=2);

//     void setPostfix(const char *name);

//     void setReturnPage(Page_t *page);

//     void setValue(int32_t *value);

//     int32_t getValue();

//     void draw();

//     void performAction(uint16_t x, uint16_t y, uint8_t z, bool pressed);

//     void onPress(uint16_t x, uint16_t y, uint8_t z);
    
//     void onHoverEnter(uint16_t x, uint16_t y, uint8_t z);

//     void onHoverExit(uint16_t x, uint16_t y, uint8_t z);
    
//     void onRelease(uint16_t x, uint16_t y, uint8_t z);

//     static void onStart(void *);
//     static void onLoad(void *, void *);
//     static void onExit();

//     static void generatePage(Page_t &page);
//     static Page_t generatePage();

//     static void ts_onPress();
//     static void ts_onRelease();
// };
