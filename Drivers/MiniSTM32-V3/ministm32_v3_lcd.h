#ifndef __MINISTM32_V3_LCD_H
#define __MINISTM32_V3_LCD_H

#include "stdio.h"
#include "ministm32_v3.h"
#include "../Components/ili932x/ili932x.h"
#include "../../../Utilities/Fonts/fonts.h"

typedef struct 
{ 
  uint32_t TextColor;
  uint32_t BackColor;
  sFONT    *pFont; 

} LCD_DrawPropTypeDef;

typedef enum
{
  CENTER_MODE             = 0x01,    // Center mode
  RIGHT_MODE              = 0x02,    // Right mode
  LEFT_MODE               = 0x03     // Left mode
} Line_ModeTypdef;

typedef struct 
{
  int16_t X;
  int16_t Y;
} Point, *pPoint; 

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

#define LCD_DEFAULT_FONT        Font24

uint8_t  LCD_Init(void);
uint32_t LCD_GetXSize(void);
uint32_t LCD_GetYSize(void);

void     LCD_DisplayOff(void);
void     LCD_DisplayOn(void);

uint16_t LCD_GetTextColor(void);
uint16_t LCD_GetBackColor(void);
void     LCD_SetTextColor(__IO uint16_t Color);
void     LCD_SetBackColor(__IO uint16_t Color);
void     LCD_SetFont(sFONT *fonts);
sFONT    *LCD_GetFont(void);

void     LCD_Clear(uint16_t Color);
void     LCD_ClearStringLine(uint16_t Line);
void     LCD_DisplayChar(uint16_t Xpos, uint16_t Ypos, uint8_t Char);
void     LCD_DisplayStringAt(uint16_t Xpos, uint16_t Ypos, uint8_t *pText, Line_ModeTypdef Mode);
void     LCD_DisplayStringAtLine(uint16_t Line, uint8_t *pText);

//uint16_t LCD_ReadPixel(uint16_t Xpos, uint16_t Ypos);
void     LCD_DrawHLine(uint16_t Xpos, uint16_t Ypos, uint16_t Length);
void     LCD_DrawVLine(uint16_t Xpos, uint16_t Ypos, uint16_t Length);
void     LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void     LCD_DrawRect(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height);
void     LCD_DrawCircle(uint16_t Xpos, uint16_t Ypos, uint16_t Radius);
void     LCD_DrawPolygon(pPoint Points, uint16_t PointCount);
void     LCD_DrawEllipse(int Xpos, int Ypos, int XRadius, int YRadius);
void     LCD_FillRect(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height);
void     LCD_FillCircle(uint16_t Xpos, uint16_t Ypos, uint16_t Radius);
void     LCD_FillEllipse(int Xpos, int Ypos, int XRadius, int YRadius);
void     LCD_DrawBitmap(uint16_t Xpos, uint16_t Ypos, uint8_t *pbmp);
void     LCD_DrawRGBImage(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height, uint8_t *Bitmap);

#endif
