#include "main.h"
#include "stm32f1xx_hal.h"
#include "ministm32_v3.h"
#include "ministm32_v3_lcd.h"
#include "../../../../Utilities/Log/lcd_log.h"

uint8_t CheckForUserInput(void);

void Log_Demo(void)
{ 
  //JOYState_TypeDef JoyState = JOY_NONE;
  uint8_t i = 0;

  // Wait For User inputs
  while(CheckForUserInput() == 0);
  
  // Initialize LCD Log module
  LCD_LOG_Init();
  
  // Show Header and Footer texts
  LCD_LOG_SetHeader((uint8_t *)"Log Example");
  LCD_LOG_SetFooter((uint8_t *)"Use Joystick to scroll up/down");
  
  // Output User logs
  for (i = 0; i < 10; i++)
  {
    LCD_UsrLog ("This is Line %d \n", i);
  }
  
  HAL_Delay(2000);
  
  // Clear Old logs
  LCD_LOG_ClearTextZone();
  
  // Output new user logs
  for (i = 0; i < 30; i++)
  {
    LCD_UsrLog ("This is Line %d \n", i);
  }
  
  // Check for user input for scroll (back and forward)
  while (1)
  {
    if(HAL_GPIO_ReadPin(KEY1_GPIO_PORT, KEY1_PIN) == GPIO_PIN_RESET)
    {
      while (HAL_GPIO_ReadPin(KEY1_GPIO_PORT, KEY1_PIN) == GPIO_PIN_RESET);
      LCD_LOG_ScrollBack();
    }

    if(HAL_GPIO_ReadPin(KEY2_GPIO_PORT, KEY2_PIN) == GPIO_PIN_RESET)
    {
      while (HAL_GPIO_ReadPin(KEY2_GPIO_PORT, KEY2_PIN) == GPIO_PIN_RESET);
      LCD_LOG_ScrollForward();
    }

    //if(CheckForUserInput() > 0)
    //{
    //  return;
    //}    
    HAL_Delay(10);
  }
}
