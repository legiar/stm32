#include "ministm32_v3_lcd.h"
#include "../../../Utilities/Fonts/fonts.h"
#include "../../../Utilities/Fonts/font24.c"
#include "../../../Utilities/Fonts/font20.c"
#include "../../../Utilities/Fonts/font16.c"
#include "../../../Utilities/Fonts/font12.c"
#include "../../../Utilities/Fonts/font8.c"

LCD_DrawPropTypeDef DrawProp;

#define ABS(X)  ((X) > 0 ? (X) : -(X)) 

static void LCD_DrawPixel(uint16_t Xpos, uint16_t Ypos, uint16_t RGBCode);

uint8_t LCD_Init(void)
{
  uint8_t ret = LCD_ERROR;
  
  // Default value for draw propriety
  DrawProp.BackColor = 0xFFFF;
  DrawProp.pFont     = &Font24;
  DrawProp.TextColor = 0x0000;
  ili9325_Init();
  
  // Initialize the font
  LCD_SetFont(&LCD_DEFAULT_FONT);

  ret = LCD_OK;

  return ret;
}

uint32_t LCD_GetXSize(void)
{
  return ili9325_GetLcdPixelWidth();
}

uint32_t LCD_GetYSize(void)
{
  return ili9325_GetLcdPixelHeight();
}

uint16_t LCD_GetTextColor(void)
{
  return DrawProp.TextColor;
}

uint16_t LCD_GetBackColor(void)
{
  return DrawProp.BackColor;
}

void LCD_SetTextColor(uint16_t Color)
{
  DrawProp.TextColor = Color;
}

void LCD_SetBackColor(uint16_t Color)
{
  DrawProp.BackColor = Color;
}

void LCD_SetFont(sFONT *pFonts)
{
  DrawProp.pFont = pFonts;
}

sFONT *LCD_GetFont(void)
{
  return DrawProp.pFont;
}

void LCD_Clear(uint16_t Color)
{ 
  uint32_t i = 0;
  uint32_t color_backup = DrawProp.TextColor; 
  DrawProp.TextColor = Color;
  
  for (i = 0; i < LCD_GetYSize(); i++) {
    LCD_DrawHLine(0, i, LCD_GetXSize());
  }

  DrawProp.TextColor = color_backup; 
  LCD_SetTextColor(DrawProp.TextColor);
}

void LCD_DrawHLine(uint16_t Xpos, uint16_t Ypos, uint16_t Length)
{
  ili9325_DrawHLine(DrawProp.TextColor, Xpos, Ypos, Length);
}

void LCD_DrawVLine(uint16_t Xpos, uint16_t Ypos, uint16_t Length)
{
  ili9325_DrawVLine(DrawProp.TextColor, Xpos, Ypos, Length);
}

void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
  int16_t deltax = 0, deltay = 0, x = 0, y = 0, xinc1 = 0, xinc2 = 0, 
  yinc1 = 0, yinc2 = 0, den = 0, num = 0, numadd = 0, numpixels = 0, 
  curpixel = 0;
  
  deltax = ABS(x2 - x1);        /* The difference between the x's */
  deltay = ABS(y2 - y1);        /* The difference between the y's */
  x = x1;                       /* Start x off at the first pixel */
  y = y1;                       /* Start y off at the first pixel */
  
  if (x2 >= x1)                 /* The x-values are increasing */
  {
    xinc1 = 1;
    xinc2 = 1;
  }
  else                          /* The x-values are decreasing */
  {
    xinc1 = -1;
    xinc2 = -1;
  }
  
  if (y2 >= y1)                 /* The y-values are increasing */
  {
    yinc1 = 1;
    yinc2 = 1;
  }
  else                          /* The y-values are decreasing */
  {
    yinc1 = -1;
    yinc2 = -1;
  }
  
  if (deltax >= deltay)         /* There is at least one x-value for every y-value */
  {
    xinc1 = 0;                  /* Don't change the x when numerator >= denominator */
    yinc2 = 0;                  /* Don't change the y for every iteration */
    den = deltax;
    num = deltax / 2;
    numadd = deltay;
    numpixels = deltax;         /* There are more x-values than y-values */
  }
  else                          /* There is at least one y-value for every x-value */
  {
    xinc2 = 0;                  /* Don't change the x for every iteration */
    yinc1 = 0;                  /* Don't change the y when numerator >= denominator */
    den = deltay;
    num = deltay / 2;
    numadd = deltax;
    numpixels = deltay;         /* There are more y-values than x-values */
  }
  
  for (curpixel = 0; curpixel <= numpixels; curpixel++)
  {
    LCD_DrawPixel(x, y, DrawProp.TextColor);  /* Draw the current pixel */
    num += numadd;                            /* Increase the numerator by the top of the fraction */
    if (num >= den)                           /* Check if numerator >= denominator */
    {
      num -= den;                             /* Calculate the new numerator value */
      x += xinc1;                             /* Change the x as appropriate */
      y += yinc1;                             /* Change the y as appropriate */
    }
    x += xinc2;                               /* Change the x as appropriate */
    y += yinc2;                               /* Change the y as appropriate */
  }
}

void LCD_DrawBitmap(uint16_t Xpos, uint16_t Ypos, uint8_t *pbmp)
{
  uint32_t height = 0;
  uint32_t width  = 0;
  
  // Read bitmap width
  width = *(uint16_t *) (pbmp + 18);
  width |= (*(uint16_t *) (pbmp + 20)) << 16;
  
  // Read bitmap height
  height = *(uint16_t *) (pbmp + 22);
  height |= (*(uint16_t *) (pbmp + 24)) << 16; 
  
  ili9325_SetDisplayWindow(Xpos, Ypos, width, height);
  ili9325_DrawBitmap(Xpos, Ypos, pbmp);
  ili9325_SetDisplayWindow(0, 0, LCD_GetXSize(), LCD_GetYSize());
}

void LCD_DrawRGBImage(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height, uint8_t *Bitmap)
{
  //LCD_SetDisplayWindow(Xpos, Ypos, Xsize, Ysize);
  ili9325_DrawRGBImage(Xpos, Ypos, Width, Height, Bitmap);
  //LCD_SetDisplayWindow(0, 0, BSP_LCD_GetXSize(), BSP_LCD_GetYSize());
}

static void LCD_DrawPixel(uint16_t Xpos, uint16_t Ypos, uint16_t RGBCode)
{
  ili9325_WritePixel(Xpos, Ypos, RGBCode);
}
