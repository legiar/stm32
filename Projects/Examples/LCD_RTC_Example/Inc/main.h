/**
  ******************************************************************************
  * File Name          : main.h
  * Description        : This file contains the common defines of the application
  ******************************************************************************
  *
  * COPYRIGHT(c) 2016 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H
  /* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */
#include "stm32f1xx_hal.h"

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define LCD_DB00_Pin GPIO_PIN_0
#define LCD_DB00_GPIO_Port GPIOC
#define LCD_DB01_Pin GPIO_PIN_1
#define LCD_DB01_GPIO_Port GPIOC
#define LCD_DB02_Pin GPIO_PIN_2
#define LCD_DB02_GPIO_Port GPIOC
#define LCD_DB03_Pin GPIO_PIN_3
#define LCD_DB03_GPIO_Port GPIOC
#define KEY1_Pin GPIO_PIN_0
#define KEY1_GPIO_Port GPIOA
#define KEY2_Pin GPIO_PIN_1
#define KEY2_GPIO_Port GPIOA
#define LED1_Pin GPIO_PIN_2
#define LED1_GPIO_Port GPIOA
#define LED2_Pin GPIO_PIN_3
#define LED2_GPIO_Port GPIOA
#define TP_CS_Pin GPIO_PIN_4
#define TP_CS_GPIO_Port GPIOA
#define LCD_DB04_Pin GPIO_PIN_4
#define LCD_DB04_GPIO_Port GPIOC
#define LCD_DB05_Pin GPIO_PIN_5
#define LCD_DB05_GPIO_Port GPIOC
#define LCD_DB10_Pin GPIO_PIN_10
#define LCD_DB10_GPIO_Port GPIOB
#define LCD_DB11_Pin GPIO_PIN_11
#define LCD_DB11_GPIO_Port GPIOB
#define LCD_DB12_Pin GPIO_PIN_12
#define LCD_DB12_GPIO_Port GPIOB
#define LCD_DB13_Pin GPIO_PIN_13
#define LCD_DB13_GPIO_Port GPIOB
#define LCD_DB14_Pin GPIO_PIN_14
#define LCD_DB14_GPIO_Port GPIOB
#define LCD_DB15_Pin GPIO_PIN_15
#define LCD_DB15_GPIO_Port GPIOB
#define LCD_DB06_Pin GPIO_PIN_6
#define LCD_DB06_GPIO_Port GPIOC
#define LCD_DB07_Pin GPIO_PIN_7
#define LCD_DB07_GPIO_Port GPIOC
#define LCD_CS_Pin GPIO_PIN_8
#define LCD_CS_GPIO_Port GPIOC
#define LCD_RS_Pin GPIO_PIN_9
#define LCD_RS_GPIO_Port GPIOC
#define LCD_WR_Pin GPIO_PIN_10
#define LCD_WR_GPIO_Port GPIOC
#define LCD_RD_Pin GPIO_PIN_11
#define LCD_RD_GPIO_Port GPIOC
#define F_CS_Pin GPIO_PIN_6
#define F_CS_GPIO_Port GPIOB
#define SD_CS_Pin GPIO_PIN_7
#define SD_CS_GPIO_Port GPIOB
#define LCD_DB08_Pin GPIO_PIN_8
#define LCD_DB08_GPIO_Port GPIOB
#define LCD_DB09_Pin GPIO_PIN_9
#define LCD_DB09_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

/**
  * @}
  */ 

/**
  * @}
*/ 

#endif /* __MAIN_H */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
