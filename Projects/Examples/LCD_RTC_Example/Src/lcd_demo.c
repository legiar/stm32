#include "main.h"
#include "stm32f1xx_hal.h"
#include "ministm32_v3.h"
#include "ministm32_v3_lcd.h"

extern const unsigned char stlogo[];

#define LCD_FEATURES_NUM                3

static uint8_t LCD_Feature = 0;
static void LCD_SetHint(void);
static void LCD_Show_Feature(uint8_t feature);

uint8_t CheckForUserInput(void);

void LCD_Demo(void)
{ 
  LCD_SetHint();
  LCD_Feature = 0;
  LCD_Show_Feature(LCD_Feature); 
  
  while (1)
  {
    if(CheckForUserInput() > 0) {
      if(++LCD_Feature < LCD_FEATURES_NUM) {
        LCD_Show_Feature (LCD_Feature); 
      } else {
        return;
      }
    }
    HAL_Delay(100);
  }
}

static void LCD_SetHint(void)
{
  LCD_Clear(LCD_COLOR_WHITE);
  
  LCD_SetTextColor(LCD_COLOR_BLUE);
  LCD_FillRect(0, 0, LCD_GetXSize(), 80);
  LCD_SetTextColor(LCD_COLOR_WHITE);
  LCD_SetBackColor(LCD_COLOR_BLUE); 
  LCD_SetFont(&Font24);
  LCD_DisplayStringAt(0, 0, (uint8_t *)"LCD", CENTER_MODE);
  LCD_SetFont(&Font12);
  LCD_DisplayStringAt(0, 30, (uint8_t *)"This example shows the different", CENTER_MODE);
  LCD_DisplayStringAt(0, 45, (uint8_t *)"LCD Features, use Key push-button", CENTER_MODE); 
  LCD_DisplayStringAt(0, 60, (uint8_t *)"to display next page", CENTER_MODE); 

  LCD_SetTextColor(LCD_COLOR_BLUE);  
  LCD_DrawRect(10, 90, LCD_GetXSize() - 20, LCD_GetYSize()- 100);
  LCD_DrawRect(11, 91, LCD_GetXSize() - 22, LCD_GetYSize()- 102);
 }

static void LCD_Show_Feature(uint8_t feature)
{
  Point Points[]= {{20, 150}, {80, 150}, {80, 200}};
  Point Points2[]= {{LCD_GetXSize() - 80, 150}, {LCD_GetXSize() - 20, 150}, {LCD_GetXSize() - 20, 200}};
  
  LCD_SetBackColor(LCD_COLOR_WHITE);  
  LCD_SetTextColor(LCD_COLOR_WHITE);    
  LCD_FillRect(12, 92, LCD_GetXSize() - 24, LCD_GetYSize()- 104);
  LCD_SetTextColor(LCD_COLOR_BLACK);

  switch (feature)
  {
  case 0:
    // Text Feature
    LCD_DisplayStringAt(14, 100, (uint8_t *)"Left aligned Text", LEFT_MODE); 
    LCD_DisplayStringAt(0, 115, (uint8_t *)"Center aligned Text", CENTER_MODE); 
    LCD_DisplayStringAt(14, 130, (uint8_t*)"Right aligned Text", RIGHT_MODE);
    LCD_SetFont(&Font24);
    LCD_DisplayStringAt(14, 180, (uint8_t *)"Font24", LEFT_MODE); 
    LCD_SetFont(&Font20);
    LCD_DisplayStringAt(LCD_GetXSize()/2 -20, 180, (uint8_t *)"Font20", LEFT_MODE); 
    LCD_SetFont(&Font16);
    LCD_DisplayStringAt(LCD_GetXSize() - 80, 184, (uint8_t *)"Font16", LEFT_MODE); 
    break;
    
  case 1:
    // Draw misc. Shapes
    LCD_SetTextColor(LCD_COLOR_BLACK); 
    LCD_DrawRect(20, 100, 60 , 40);
    LCD_FillRect(100, 100, 60 , 40); 
    
    LCD_SetTextColor(LCD_COLOR_GRAY); 
    LCD_DrawCircle(LCD_GetXSize() - 120, 120, 20);
    LCD_FillCircle(LCD_GetXSize() - 40, 120, 20);
    
    LCD_SetTextColor(LCD_COLOR_GREEN); 
    LCD_DrawPolygon(Points, 3);
    
    LCD_SetTextColor(LCD_COLOR_RED); 
    LCD_DrawEllipse(130, 170, 30, 20);
    LCD_FillEllipse(200, 170, 30, 20);
    
    LCD_SetTextColor(LCD_COLOR_BLACK); 
    LCD_DrawHLine(20, LCD_GetYSize() - 30, LCD_GetXSize() / 5);
    LCD_DrawLine (100, LCD_GetYSize() - 20, 230, LCD_GetYSize()- 50);
    LCD_DrawLine (100, LCD_GetYSize()- 50, 230, LCD_GetYSize()- 20);
    
    LCD_SetTextColor(LCD_COLOR_GREEN); 
    //LCD_FillPolygon(Points2, 3);
    break;
    
  case 2:
    // Draw Bitmap
    LCD_DrawBitmap(20, 100, (uint8_t *)stlogo);
    HAL_Delay(500);
    
    LCD_DrawBitmap(LCD_GetXSize()/2 - 40, 100, (uint8_t *)stlogo);
    HAL_Delay(500);    
    
    LCD_DrawBitmap(LCD_GetXSize()-100, 100, (uint8_t *)stlogo);
    HAL_Delay(500);

    LCD_DrawBitmap(20, LCD_GetYSize()- 80, (uint8_t *)stlogo);
    HAL_Delay(500);
    
    LCD_DrawBitmap(LCD_GetXSize()/2 - 40, LCD_GetYSize()- 80, (uint8_t *)stlogo);
    HAL_Delay(500);     

    LCD_DrawBitmap(LCD_GetXSize()-100, LCD_GetYSize()- 80, (uint8_t *)stlogo);
    HAL_Delay(500);    
    break;
  }
}
