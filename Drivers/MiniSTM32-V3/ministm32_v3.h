#ifndef __MINISTM32_V3_H
#define __MINISTM32_V3_H

#include "stm32f1xx_hal.h"

#define LED1_GPIO_Port 					GPIOA
#define LED1_Pin 								GPIO_PIN_2

#define LED2_GPIO_Port 					GPIOA
#define LED2_Pin 								GPIO_PIN_3

#define KEY1_GPIO_Port 					GPIOA
#define KEY1_Pin 								GPIO_PIN_0

#define KEY2_GPIO_Port 					GPIOA
#define KEY2_Pin 								GPIO_PIN_1

#define LCD_DB00_GPIO_Port      GPIOC
#define LCD_DB00_Pin            GPIO_PIN_0
#define LCD_DB01_GPIO_Port      GPIOC
#define LCD_DB01_Pin            GPIO_PIN_1
#define LCD_DB02_GPIO_Port      GPIOC
#define LCD_DB02_Pin            GPIO_PIN_2
#define LCD_DB03_GPIO_Port      GPIOC
#define LCD_DB03_Pin            GPIO_PIN_3
#define LCD_DB04_GPIO_Port      GPIOC
#define LCD_DB04_Pin            GPIO_PIN_4
#define LCD_DB05_GPIO_Port      GPIOC
#define LCD_DB05_Pin            GPIO_PIN_5
#define LCD_DB06_GPIO_Port      GPIOC
#define LCD_DB06_Pin            GPIO_PIN_6
#define LCD_DB07_GPIO_Port      GPIOC
#define LCD_DB07_Pin            GPIO_PIN_7
#define LCD_DB08_GPIO_Port      GPIOB
#define LCD_DB08_Pin            GPIO_PIN_8
#define LCD_DB09_GPIO_Port      GPIOB
#define LCD_DB09_Pin            GPIO_PIN_9
#define LCD_DB10_GPIO_Port      GPIOB
#define LCD_DB10_Pin            GPIO_PIN_10
#define LCD_DB11_GPIO_Port      GPIOB
#define LCD_DB11_Pin            GPIO_PIN_11
#define LCD_DB12_GPIO_Port      GPIOB
#define LCD_DB12_Pin            GPIO_PIN_12
#define LCD_DB13_GPIO_Port      GPIOB
#define LCD_DB13_Pin            GPIO_PIN_13
#define LCD_DB14_GPIO_Port      GPIOB
#define LCD_DB14_Pin            GPIO_PIN_14
#define LCD_DB15_GPIO_Port      GPIOB
#define LCD_DB15_Pin            GPIO_PIN_15

#define LCD_CS_GPIO_Port        GPIOC
#define LCD_CS_Pin              GPIO_PIN_8
#define LCD_RS_GPIO_Port        GPIOC
#define LCD_RS_Pin              GPIO_PIN_9
#define LCD_WR_GPIO_Port        GPIOC
#define LCD_WR_Pin              GPIO_PIN_10
#define LCD_RD_GPIO_Port        GPIOC
#define LCD_RD_Pin              GPIO_PIN_11

#define F_CS_GPIO_Port 					GPIOB
#define F_CS_Pin 								GPIO_PIN_6
#define SD_CS_GPIO_Port 				GPIOB
#define SD_CS_Pin 							GPIO_PIN_7
#define TP_CS_GPIO_Port 				GPIOA
#define TP_CS_Pin 							GPIO_PIN_4
  
#endif

