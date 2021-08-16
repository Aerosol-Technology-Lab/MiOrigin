#pragma once

#ifdef CMXG_USE_BASE
#error Untested!

using Color = uint32_t;
using Font_t = uint8_t;

#else

#include <stdint.h>
using Color = uint32_t;
using Font_t = uint8_t;

// Color definitions compatible with eTFTSPI library
#define CMXG_BLACK       0x0000      /*   0,   0,   0 */
#define CMXG_NAVY        0x000F      /*   0,   0, 128 */
#define CMXG_DARKGREEN   0x03E0      /*   0, 128,   0 */
#define CMXG_DARKCYAN    0x03EF      /*   0, 128, 128 */
#define CMXG_MAROON      0x7800      /* 128,   0,   0 */
#define CMXG_PURPLE      0x780F      /* 128,   0, 128 */
#define CMXG_OLIVE       0x7BE0      /* 128, 128,   0 */
#define CMXG_LIGHTGREY   0xD69A      /* 211, 211, 211 */
#define CMXG_DARKGREY    0x7BEF      /* 128, 128, 128 */
#define CMXG_BLUE        0x001F      /*   0,   0, 255 */
#define CMXG_GREEN       0x07E0      /*   0, 255,   0 */
#define CMXG_CYAN        0x07FF      /*   0, 255, 255 */
#define CMXG_RED         0xF800      /* 255,   0,   0 */
#define CMXG_MAGENTA     0xF81F      /* 255,   0, 255 */
#define CMXG_YELLOW      0xFFE0      /* 255, 255,   0 */
#define CMXG_WHITE       0xFFFF      /* 255, 255, 255 */
#define CMXG_ORANGE      0xFDA0      /* 255, 180,   0 */
#define CMXG_GREENYELLOW 0xB7E0      /* 180, 255,   0 */
#define CMXG_PINK        0xFE19      /* 255, 192, 203 */ //Lighter pink, was 0xFC9F      
#define CMXG_BROWN       0x9A60      /* 150,  75,   0 */
#define CMXG_GOLD        0xFEA0      /* 255, 215,   0 */
#define CMXG_SILVER      0xC618      /* 192, 192, 192 */
#define CMXG_SKYBLUE     0x867D      /* 135, 206, 235 */
#define CMXG_VIOLET      0x915C      /* 180,  46, 226 */

#define CMXG_TRANSPARENT 0x0120

#define CMXG_TL_DATUM 0 // Top left (default)
#define CMXG_TC_DATUM 1 // Top centre
#define CMXG_TR_DATUM 2 // Top right
#define CMXG_ML_DATUM 3 // Middle left
#define CMXG_CL_DATUM 3 // Centre left, same as above
#define CMXG_MC_DATUM 4 // Middle centre
#define CMXG_CC_DATUM 4 // Centre centre, same as above
#define CMXG_MR_DATUM 5 // Middle right
#define CMXG_CR_DATUM 5 // Centre right, same as above
#define CMXG_BL_DATUM 6 // Bottom left
#define CMXG_BC_DATUM 7 // Bottom centre
#define CMXG_BR_DATUM 8 // Bottom right
#define CMXG_L_BASELINE  9 // Left character baseline (Line the 'A' character would sit on)
#define CMXG_C_BASELINE 10 // Centre character baseline
#define CMX_GR_BASELINE 11 // Right character baseline

#endif
