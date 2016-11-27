#ifndef __MINISTM32_V3_LCD_H
#define __MINISTM32_V3_LCD_H

#include <stdint.h>
#include "ministm32_v3.h"
//#include "../Components/ili9320/ili9320.h"
//#include "../../../Utilities/Fonts/fonts.h"

#define LCD_OK         0x00
#define LCD_ERROR      0x01
#define LCD_TIMEOUT    0x02
    
#define LCD_COLOR_BLUE          (uint16_t)0x001F
#define LCD_COLOR_GREEN         (uint16_t)0x07E0
#define LCD_COLOR_RED           (uint16_t)0xF800
#define LCD_COLOR_CYAN          (uint16_t)0x07FF
#define LCD_COLOR_MAGENTA       (uint16_t)0xF81F
#define LCD_COLOR_YELLOW        (uint16_t)0xFFE0
#define LCD_COLOR_LIGHTBLUE     (uint16_t)0x841F
#define LCD_COLOR_LIGHTGREEN    (uint16_t)0x87F0
#define LCD_COLOR_LIGHTRED      (uint16_t)0xFC10
#define LCD_COLOR_LIGHTCYAN     (uint16_t)0x87FF
#define LCD_COLOR_LIGHTMAGENTA  (uint16_t)0xFC1F
#define LCD_COLOR_LIGHTYELLOW   (uint16_t)0xFFF0
#define LCD_COLOR_DARKBLUE      (uint16_t)0x0010
#define LCD_COLOR_DARKGREEN     (uint16_t)0x0400
#define LCD_COLOR_DARKRED       (uint16_t)0x8000
#define LCD_COLOR_DARKCYAN      (uint16_t)0x0410
#define LCD_COLOR_DARKMAGENTA   (uint16_t)0x8010
#define LCD_COLOR_DARKYELLOW    (uint16_t)0x8400
#define LCD_COLOR_WHITE         (uint16_t)0xFFFF
#define LCD_COLOR_LIGHTGRAY     (uint16_t)0xD69A
#define LCD_COLOR_GRAY          (uint16_t)0x8410
#define LCD_COLOR_DARKGRAY      (uint16_t)0x4208
#define LCD_COLOR_BLACK         (uint16_t)0x0000
#define LCD_COLOR_BROWN         (uint16_t)0xA145
#define LCD_COLOR_ORANGE        (uint16_t)0xFD20

#endif 
