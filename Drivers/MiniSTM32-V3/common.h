#ifndef __COMMON_H
#define __COMMON_H

#include <stdio.h>

//TFTLCD部分外要调用的函数		   
extern uint16_t  POINT_COLOR;//默认红色    
extern uint16_t  BACK_COLOR; //背景颜色.默认为白色

/* LED 定义 */
#define LED1 PAout(2)	   //板子上对应于LED1
#define LED2 PAout(3)	   //板子上对应于LED2

/* 按键 定义 */
#define KEY1   PAin(0)	   //板子上的KEY1键
#define KEY2   PAin(1)	   //板子上的KEY2键

/* LCD 控制引脚配置*/
#define LCD_CS  PCout(8)
#define LCD_RS	PCout(9)
#define LCD_WR  PCout(10)
#define LCD_RD	PCout(11)

//定义LCD的尺寸
#define LCD_W 240
#define LCD_H 320

/***********************************************************************************
设置颜色宏定义
***********************************************************************************/
#define   BLACK        0x0000                    /* 黑色： 0, 0, 0               */
#define   NAVY         0x000F                    /* 深蓝色： 0, 0, 128           */
#define   DGREEN       0x03E0                    /* 深绿色： 0, 128, 0           */
#define   DCYAN        0x03EF                    /* 深青色： 0, 128, 128         */
#define   MAROON       0x7800                    /* 深红色：128, 0, 0            */
#define   PURPLE       0x780F                    /* 紫色： 128, 0, 128           */
#define   OLIVE        0x7BE0                    /* 橄榄绿：128, 128, 0          */
#define   LGRAY        0xC618                    /* 灰白色：192, 192, 192        */
#define   DGRAY        0x7BEF                    /* 深灰色：128, 128, 128        */
#define   BLUE         0x001F                    /* 蓝色： 0, 0, 255             */
#define   GREEN        0x07E0                 	 /* 绿色： 0, 255, 0             */
#define   CYAN         0x07FF                    /* 青色： 0, 255, 255           */
#define   RED          0xF800                    /* 红色： 255, 0, 0             */
#define   MAGENTA      0xF81F                    /* 品红： 255, 0, 255           */
#define   YELLOW       0xFFE0                    /* 黄色： 255, 255, 0           */
#define   WHITE        0xFFFF                    /* 白色： 255, 255, 255         */
#define   IDMCOLOR(color) (((color & 0x001F) << 11) | ((color & 0xF800) >> 11) | (color & 0x07E0))

#endif	    
		
