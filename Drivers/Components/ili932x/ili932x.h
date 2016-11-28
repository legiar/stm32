#ifndef  __ILI932X_H
#define  __ILI932X_H

#include <stdint.h>

#define  LCD_WIDTH              320
#define  LCD_HEIGHT             240

//#define LCD_ORIENTATION         0
#define LCD_ORIENTATION         90
//#define LCD_ORIENTATION         180
//#define LCD_ORIENTATION         270

// ILI9325 ID  
#define  ILI9325_ID             0x9325
   
// ILI9325 Size  
#define  ILI9325_LCD_PIXEL_WIDTH    ((uint16_t)320)
#define  ILI9325_LCD_PIXEL_HEIGHT   ((uint16_t)240)
   
// ILI9325 Registers  
#define LCD_REG_0             0x00
#define LCD_REG_1             0x01
#define LCD_REG_2             0x02
#define LCD_REG_3             0x03
#define LCD_REG_4             0x04
#define LCD_REG_5             0x05
#define LCD_REG_6             0x06
#define LCD_REG_7             0x07
#define LCD_REG_8             0x08
#define LCD_REG_9             0x09
#define LCD_REG_10            0x0A
#define LCD_REG_12            0x0C
#define LCD_REG_13            0x0D
#define LCD_REG_14            0x0E
#define LCD_REG_15            0x0F
#define LCD_REG_16            0x10
#define LCD_REG_17            0x11
#define LCD_REG_18            0x12
#define LCD_REG_19            0x13
#define LCD_REG_20            0x14
#define LCD_REG_21            0x15
#define LCD_REG_22            0x16
#define LCD_REG_23            0x17
#define LCD_REG_24            0x18
#define LCD_REG_25            0x19
#define LCD_REG_26            0x1A
#define LCD_REG_27            0x1B
#define LCD_REG_28            0x1C
#define LCD_REG_29            0x1D
#define LCD_REG_30            0x1E
#define LCD_REG_31            0x1F
#define LCD_REG_32            0x20
#define LCD_REG_33            0x21
#define LCD_REG_34            0x22
#define LCD_REG_36            0x24
#define LCD_REG_37            0x25
#define LCD_REG_40            0x28
#define LCD_REG_41            0x29
#define LCD_REG_43            0x2B
#define LCD_REG_45            0x2D
#define LCD_REG_48            0x30
#define LCD_REG_49            0x31
#define LCD_REG_50            0x32
#define LCD_REG_51            0x33
#define LCD_REG_52            0x34
#define LCD_REG_53            0x35
#define LCD_REG_54            0x36
#define LCD_REG_55            0x37
#define LCD_REG_56            0x38
#define LCD_REG_57            0x39
#define LCD_REG_58            0x3A
#define LCD_REG_59            0x3B
#define LCD_REG_60            0x3C
#define LCD_REG_61            0x3D
#define LCD_REG_62            0x3E
#define LCD_REG_63            0x3F
#define LCD_REG_64            0x40
#define LCD_REG_65            0x41
#define LCD_REG_66            0x42
#define LCD_REG_67            0x43
#define LCD_REG_68            0x44
#define LCD_REG_69            0x45
#define LCD_REG_70            0x46
#define LCD_REG_71            0x47
#define LCD_REG_72            0x48
#define LCD_REG_73            0x49
#define LCD_REG_74            0x4A
#define LCD_REG_75            0x4B
#define LCD_REG_76            0x4C
#define LCD_REG_77            0x4D
#define LCD_REG_78            0x4E
#define LCD_REG_79            0x4F
#define LCD_REG_80            0x50
#define LCD_REG_81            0x51
#define LCD_REG_82            0x52
#define LCD_REG_83            0x53
#define LCD_REG_96            0x60
#define LCD_REG_97            0x61
#define LCD_REG_106           0x6A
#define LCD_REG_118           0x76
#define LCD_REG_128           0x80
#define LCD_REG_129           0x81
#define LCD_REG_130           0x82
#define LCD_REG_131           0x83
#define LCD_REG_132           0x84
#define LCD_REG_133           0x85
#define LCD_REG_134           0x86
#define LCD_REG_135           0x87
#define LCD_REG_136           0x88
#define LCD_REG_137           0x89
#define LCD_REG_139           0x8B
#define LCD_REG_140           0x8C
#define LCD_REG_141           0x8D
#define LCD_REG_143           0x8F
#define LCD_REG_144           0x90
#define LCD_REG_145           0x91
#define LCD_REG_146           0x92
#define LCD_REG_147           0x93
#define LCD_REG_148           0x94
#define LCD_REG_149           0x95
#define LCD_REG_150           0x96
#define LCD_REG_151           0x97
#define LCD_REG_152           0x98
#define LCD_REG_153           0x99
#define LCD_REG_154           0x9A
#define LCD_REG_157           0x9D
#define LCD_REG_192           0xC0
#define LCD_REG_193           0xC1
#define LCD_REG_229           0xE5


#define R0             0x00
#define R1             0x01
#define R2             0x02
#define R3             0x03
#define R4             0x04
#define R5             0x05
#define R6             0x06
#define R7             0x07
#define R8             0x08
#define R9             0x09
#define R10            0x0A
#define R12            0x0C
#define R13            0x0D
#define R14            0x0E
#define R15            0x0F
#define R16            0x10
#define R17            0x11
#define R18            0x12
#define R19            0x13
#define R20            0x14
#define R21            0x15
#define R22            0x16
#define R23            0x17
#define R24            0x18
#define R25            0x19
#define R26            0x1A
#define R27            0x1B
#define R28            0x1C
#define R29            0x1D
#define R30            0x1E
#define R31            0x1F
#define R32            0x20
#define R33            0x21
#define R34            0x22
#define R36            0x24
#define R37            0x25
#define R40            0x28
#define R41            0x29
#define R43            0x2B
#define R45            0x2D
#define R48            0x30
#define R49            0x31
#define R50            0x32
#define R51            0x33
#define R52            0x34
#define R53            0x35
#define R54            0x36
#define R55            0x37
#define R56            0x38
#define R57            0x39
#define R59            0x3B
#define R60            0x3C
#define R61            0x3D
#define R62            0x3E
#define R63            0x3F
#define R64            0x40
#define R65            0x41
#define R66            0x42
#define R67            0x43
#define R68            0x44
#define R69            0x45
#define R70            0x46
#define R71            0x47
#define R72            0x48
#define R73            0x49
#define R74            0x4A
#define R75            0x4B
#define R76            0x4C
#define R77            0x4D
#define R78            0x4E
#define R79            0x4F
#define R80            0x50
#define R81            0x51
#define R82            0x52
#define R83            0x53
#define R96            0x60
#define R97            0x61
#define R106           0x6A
#define R118           0x76
#define R128           0x80
#define R129           0x81
#define R130           0x82
#define R131           0x83
#define R132           0x84
#define R133           0x85
#define R134           0x86
#define R135           0x87
#define R136           0x88
#define R137           0x89
#define R139           0x8B
#define R140           0x8C
#define R141           0x8D
#define R143           0x8F
#define R144           0x90
#define R145           0x91
#define R146           0x92
#define R147           0x93
#define R148           0x94
#define R149           0x95
#define R150           0x96
#define R151           0x97
#define R152           0x98
#define R153           0x99
#define R154           0x9A
#define R157           0x9D
#define R192           0xC0
#define R193           0xC1
#define R229           0xE5	

uint16_t LCD_DeviceCode(void);

//void LCD_WriteRAM_Prepare(void);
//void LCD_DrawPoint(uint16_t x,uint16_t y);
//void LCD_SetCursor(uint8_t Xpos,uint16_t Ypos);
//void LCD_WriteReg(uint16_t LCD_Reg,uint16_t LCD_Dat);
//uint16_t LCD_ReadDat(void);
//void Write_Cmd(uint16_t LCD_Reg);
//void Write_Dat(uint16_t LCD_Dat);
//uint16_t LCD_ReadReg(uint16_t LCD_Reg);

uint16_t ili9325_ReadID(void);

void ili9325_Init(void);
void ili9325_DisplayOn(void);
void ili9325_DisplayOff(void);

uint16_t ili9325_GetLcdPixelWidth(void);
uint16_t ili9325_GetLcdPixelHeight(void);

void     ili9325_SetCursor(uint16_t Xpos, uint16_t Ypos);
void     ili9325_WritePixel(uint16_t Xpos, uint16_t Ypos, uint16_t RGBCode);
uint16_t ili9325_ReadPixel(uint16_t Xpos, uint16_t Ypos);
void     ili9325_SetDisplayWindow(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height);

void     ili9325_DrawHLine(uint16_t Color, uint16_t Xpos, uint16_t Ypos, uint16_t Length);
void     ili9325_DrawVLine(uint16_t Color, uint16_t Xpos, uint16_t Ypos, uint16_t Length);
void     ili9325_DrawBitmap(uint16_t Xpos, uint16_t Ypos, uint8_t *Bitmap);
void     ili9325_DrawRGBImage(uint8_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height, uint8_t *Bitmap);

//void LCD_Delay(uint32_t nCount);
//uint32_t Num_power(uint8_t m,uint8_t n);
//void LCD_SetDisplayWindow(uint8_t Xpos, uint16_t Ypos, uint8_t Height, uint16_t Width);
//void LCD_ShowString(uint8_t x,uint16_t y,__I uint8_t *p);
//void LCD_ShowNum(uint8_t x,uint16_t y,uint32_t num,uint8_t len,uint8_t size);
//void LCD_ShowChar(uint8_t x,uint16_t y,uint8_t chars,uint8_t size,uint8_t mode);
void LCD_WriteBMP(uint8_t Xpos, uint16_t Ypos, uint8_t Height, uint16_t Width, uint8_t *bitmap);
//void LCD_Clear(uint16_t Color);
uint16_t WriteOneASCII(uint8_t *pucMsk,
                              uint16_t x0,
                              uint16_t y0,
                              uint16_t color);
uint16_t WriteOneHzChar(uint8_t *pucMsk,
                               uint16_t x0,
                               uint16_t y0,
                               uint16_t color);
void WriteString(uint16_t x0, uint16_t y0,uint8_t *pcStr, uint16_t color);
//void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
//void Draw_Circle(uint8_t x0,uint16_t y0,uint8_t r);
//void LCD_Fill(uint8_t xsta,uint16_t ysta,uint8_t xend,uint16_t yend,uint16_t color);

// LCD IO functions
void      LCD_IO_Init(void);
void      LCD_IO_WriteReg(uint16_t Reg);
void      LCD_IO_WriteData(uint16_t Data);
void      LCD_IO_WriteDataBuffer(uint16_t *pData, uint32_t Size);
uint16_t  LCD_IO_ReadData(uint16_t Reg);
void      LCD_IO_Delay(uint32_t nCount);
#endif
