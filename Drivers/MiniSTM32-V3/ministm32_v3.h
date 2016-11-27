#ifndef __MINISTM32_V3_H
#define __MINISTM32_V3_H

#include "stm32f1xx_hal.h"

#define USE_BITBANG

// BitBang
#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2)) 
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr)) 
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum)) 

#define GPIOA_ODR_ADDR    (GPIOA_BASE + 12) //0x4001080C 
#define GPIOB_ODR_ADDR    (GPIOB_BASE + 12) //0x40010C0C 
#define GPIOC_ODR_ADDR    (GPIOC_BASE + 12) //0x4001100C 
#define GPIOD_ODR_ADDR    (GPIOD_BASE + 12) //0x4001140C 
#define GPIOE_ODR_ADDR    (GPIOE_BASE + 12) //0x4001180C 
#define GPIOF_ODR_ADDR    (GPIOF_BASE + 12) //0x40011A0C    
#define GPIOG_ODR_ADDR    (GPIOG_BASE + 12) //0x40011E0C    

#define GPIOA_IDR_ADDR    (GPIOA_BASE + 8) //0x40010808 
#define GPIOB_IDR_ADDR    (GPIOB_BASE + 8) //0x40010C08 
#define GPIOC_IDR_ADDR    (GPIOC_BASE + 8) //0x40011008 
#define GPIOD_IDR_ADDR    (GPIOD_BASE + 8) //0x40011408 
#define GPIOE_IDR_ADDR    (GPIOE_BASE + 8) //0x40011808 
#define GPIOF_IDR_ADDR    (GPIOF_BASE + 8) //0x40011A08 
#define GPIOG_IDR_ADDR    (GPIOG_BASE + 8) //0x40011E08 
 
#define PA_OUT(n)   BIT_ADDR(GPIOA_ODR_ADDR,n)
#define PA_IN(n)    BIT_ADDR(GPIOA_IDR_ADDR,n)
#define PB_OUT(n)   BIT_ADDR(GPIOB_ODR_ADDR,n)
#define PB_IN(n)    BIT_ADDR(GPIOB_IDR_ADDR,n)
#define PC_OUT(n)   BIT_ADDR(GPIOC_ODR_ADDR,n)
#define PC_IN(n)    BIT_ADDR(GPIOC_IDR_ADDR,n)
#define PD_OUT(n)   BIT_ADDR(GPIOD_ODR_ADDR,n)
#define PD_IN(n)    BIT_ADDR(GPIOD_IDR_ADDR,n)
#define PE_OUT(n)   BIT_ADDR(GPIOE_ODR_ADDR,n)
#define PE_IN(n)    BIT_ADDR(GPIOE_IDR_ADDR,n)
#define PF_OUT(n)   BIT_ADDR(GPIOF_ODR_ADDR,n)
#define PF_IN(n)    BIT_ADDR(GPIOF_IDR_ADDR,n)
#define PG_OUT(n)   BIT_ADDR(GPIOG_ODR_ADDR,n)
#define PG_IN(n)    BIT_ADDR(GPIOG_IDR_ADDR,n)

#define LED1_GPIO_PORT 					GPIOA
#define LED1_PIN 								GPIO_PIN_2

#define LED2_GPIO_PORT 					GPIOA
#define LED2_PIN 								GPIO_PIN_3

#define KEY1_GPIO_PORT 					GPIOA
#define KEY1_PIN 								GPIO_PIN_0

#define KEY2_GPIO_PORT 					GPIOA
#define KEY2_PIN 								GPIO_PIN_1

#define LCD_DB00_GPIO_PORT      GPIOC
#define LCD_DB00_PIN            GPIO_PIN_0
#define LCD_DB01_GPIO_PORT      GPIOC
#define LCD_DB01_PIN            GPIO_PIN_1
#define LCD_DB02_GPIO_PORT      GPIOC
#define LCD_DB02_PIN            GPIO_PIN_2
#define LCD_DB03_GPIO_PORT      GPIOC
#define LCD_DB03_PIN            GPIO_PIN_3
#define LCD_DB04_GPIO_PORT      GPIOC
#define LCD_DB04_PIN            GPIO_PIN_4
#define LCD_DB05_GPIO_PORT      GPIOC
#define LCD_DB05_PIN            GPIO_PIN_5
#define LCD_DB06_GPIO_PORT      GPIOC
#define LCD_DB06_PIN            GPIO_PIN_6
#define LCD_DB07_GPIO_PORT      GPIOC
#define LCD_DB07_PIN            GPIO_PIN_7
#define LCD_DB08_GPIO_PORT      GPIOB
#define LCD_DB08_PIN            GPIO_PIN_8
#define LCD_DB09_GPIO_PORT      GPIOB
#define LCD_DB09_PIN            GPIO_PIN_9
#define LCD_DB10_GPIO_PORT      GPIOB
#define LCD_DB10_PIN            GPIO_PIN_10
#define LCD_DB11_GPIO_PORT      GPIOB
#define LCD_DB11_PIN            GPIO_PIN_11
#define LCD_DB12_GPIO_PORT      GPIOB
#define LCD_DB12_PIN            GPIO_PIN_12
#define LCD_DB13_GPIO_PORT      GPIOB
#define LCD_DB13_PIN            GPIO_PIN_13
#define LCD_DB14_GPIO_PORT      GPIOB
#define LCD_DB14_PIN            GPIO_PIN_14
#define LCD_DB15_GPIO_PORT      GPIOB
#define LCD_DB15_PIN            GPIO_PIN_15

#define LCD_CS_PIN              			GPIO_PIN_8
#define LCD_CS_GPIO_PORT        			GPIOC
#define LCD_CS_GPIO_CLK_ENABLE()    	__HAL_RCC_GPIOC_CLK_ENABLE()
#define LCD_CS_GPIO_CLK_DISABLE()   	__HAL_RCC_GPIOC_CLK_DISABLE()

#define LCD_RS_PIN              			GPIO_PIN_9
#define LCD_RS_GPIO_PORT        			GPIOC
#define LCD_WR_PIN              			GPIO_PIN_10
#define LCD_WR_GPIO_PORT        			GPIOC
#define LCD_RD_PIN              			GPIO_PIN_11
#define LCD_RD_GPIO_PORT        			GPIOC

#ifdef USE_BITBANG
	#define LCD_CS_LOW()                PC_OUT(8) = 0
	#define LCD_CS_HIGH()               PC_OUT(8) = 1
	#define LCD_RS_LOW()                PC_OUT(9) = 0
	#define LCD_RS_HIGH()               PC_OUT(9) = 1
	#define LCD_WR_LOW()                PC_OUT(10) = 0
	#define LCD_WR_HIGH()               PC_OUT(10) = 1
	#define LCD_RD_LOW()                PC_OUT(11) = 0
	#define LCD_RD_HIGH()               PC_OUT(11) = 1
#else
	#define LCD_CS_LOW()       						HAL_GPIO_WritePin(LCD_CS_GPIO_PORT, LCD_CS_PIN, GPIO_PIN_RESET)
	#define LCD_CS_HIGH()      						HAL_GPIO_WritePin(LCD_CS_GPIO_PORT, LCD_CS_PIN, GPIO_PIN_SET)
	#define LCD_RS_LOW()       						HAL_GPIO_WritePin(LCD_RS_GPIO_PORT, LCD_RS_PIN, GPIO_PIN_RESET)
	#define LCD_RS_HIGH()      						HAL_GPIO_WritePin(LCD_RS_GPIO_PORT, LCD_RS_PIN, GPIO_PIN_SET)
	#define LCD_WR_LOW()       						HAL_GPIO_WritePin(LCD_WR_GPIO_PORT, LCD_WR_PIN, GPIO_PIN_RESET)
	#define LCD_WR_HIGH()      						HAL_GPIO_WritePin(LCD_WR_GPIO_PORT, LCD_WR_PIN, GPIO_PIN_SET)
	#define LCD_RD_LOW()       						HAL_GPIO_WritePin(LCD_RD_GPIO_PORT, LCD_RD_PIN, GPIO_PIN_RESET)
	#define LCD_RD_HIGH()      						HAL_GPIO_WritePin(LCD_RD_GPIO_PORT, LCD_RD_PIN, GPIO_PIN_SET)
#endif

#define F_CS_GPIO_PORT 					GPIOB
#define F_CS_PIN 								GPIO_PIN_6
#define SD_CS_GPIO_PORT 				GPIOB
#define SD_CS_PIN 							GPIO_PIN_7
#define TP_CS_GPIO_PORT 				GPIOA
#define TP_CS_PIN 							GPIO_PIN_4

#endif

