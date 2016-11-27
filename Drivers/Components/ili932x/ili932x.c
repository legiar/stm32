#include "stm32f1xx.h"
#include "hardware.h"
#include "ili932x.h"
#include "Font_Lib.h"	 //字库文件库
#include "hz16.h"

#include "ministm32_v3.h"

uint16_t POINT_COLOR = BLUE,BACK_COLOR = WHITE;  /* 分别设置点的颜色和底色	*/

static uint16_t DeviceCode;
static uint16_t ArrayRGB[320] = {0};

void ili9325_WriteReg(uint16_t Reg, uint16_t RegValue)
{
  LCD_IO_WriteReg(Reg);
  LCD_IO_WriteData(RegValue);
}

uint16_t ili9325_ReadReg(uint16_t Reg)
{
  LCD_IO_WriteReg(Reg);
  return (LCD_IO_ReadData(0x00));
}

void ili9325_Delay(uint16_t Count)
{
  LCD_IO_Delay(Count);
}

void ili9325_Init(void)
{
  LCD_IO_Init();
  
  ili9325_WriteReg(LCD_REG_0, 0x0001);
  ili9325_Delay(50);
  DeviceCode = ili9325_ReadReg(LCD_REG_0);
  
  if(DeviceCode==0x9325||DeviceCode==0x9328)//ILI9325
  {
    ili9325_WriteReg(0x00e5,0x78F0);
    ili9325_WriteReg(LCD_REG_0, 0x0001); // Start internal OSC
    ili9325_WriteReg(LCD_REG_1, 0x0100); // Set SS and SM bit
    ili9325_WriteReg(LCD_REG_2, 0x0700); // Set 1 line inversion
    //ili9325_WriteReg(LCD_REG_3, 0x1018); // Set GRAM write direction and BGR=1
    
    // set GRAM write direction and BGR = 1
    // I/D=00 (Horizontal : increment, Vertical : decrement)
    // AM=1 (address is updated in vertical writing direction)
    //ili9325_WriteReg(LCD_REG_3, 0x1010);

    // set GRAM write direction and BGR = 1
    // I/D=00 (Horizontal : increment, Vertical : decrement)
    // AM=1 (address is updated in vertical writing direction)
    //ili9325_WriteReg(LCD_REG_3, 0x1018);  

    ili9325_WriteReg(LCD_REG_3,  0x1030); // set GRAM write direction and BGR = 1
                                          // I/D=11 (Horizontal : increment, Vertical : increment)
                                          // AM=0 (address is updated in horizontal writing direction)
    
    ili9325_WriteReg(LCD_REG_4,  0x0000); // Resize register
    ili9325_WriteReg(LCD_REG_8,  0x0202); // Set the back porch and front porch
    ili9325_WriteReg(LCD_REG_9,  0x0000); // Set non-display area refresh cycle ISC[3:0]
    ili9325_WriteReg(LCD_REG_10, 0x0000); // FMARK function
    ili9325_WriteReg(LCD_REG_12, 0x0000); // RGB interface setting
    ili9325_WriteReg(LCD_REG_13, 0x0000); // Frame marker Position
    ili9325_WriteReg(LCD_REG_15, 0x0000); // RGB interface polarity
    
    //Power On sequence //
    ili9325_WriteReg(0x0010,0x0000);
    ili9325_WriteReg(0x0011,0x0007);
    ili9325_WriteReg(0x0012,0x0000);
    ili9325_WriteReg(0x0013,0x0000);
    ili9325_WriteReg(0x0007,0x0001);
    ili9325_Delay(5); 
    ili9325_WriteReg(0x0010,0x1690);
    ili9325_WriteReg(0x0011,0x0227);
    ili9325_Delay(5); 
    ili9325_WriteReg(0x0012,0x009d);
    ili9325_Delay(5); 
    ili9325_WriteReg(0x0013,0x1900);
    ili9325_WriteReg(0x0029,0x0025);
    ili9325_WriteReg(0x002b,0x000d);
    ili9325_Delay(5); 
    ili9325_WriteReg(0x0020,0x0000);                                                            
    ili9325_WriteReg(0x0021,0x0000);           
    ili9325_Delay(5); 

    // Adjust the Gamma Curve (ILI9325)
    ili9325_WriteReg(LCD_REG_48, 0x0007);
    ili9325_WriteReg(LCD_REG_49, 0x0302);
    ili9325_WriteReg(LCD_REG_50, 0x0105);
    ili9325_WriteReg(LCD_REG_53, 0x0206);
    ili9325_WriteReg(LCD_REG_54, 0x0808);
    ili9325_WriteReg(LCD_REG_55, 0x0206);
    ili9325_WriteReg(LCD_REG_56, 0x0504);
    ili9325_WriteReg(LCD_REG_57, 0x0007);
    ili9325_WriteReg(LCD_REG_60, 0x0105);
    ili9325_WriteReg(LCD_REG_61, 0x0808);
    ili9325_Delay(5); 
    ili9325_WriteReg(0x0050,0x0000);
    ili9325_WriteReg(0x0051,0x00ef);                   
    ili9325_WriteReg(0x0052,0x0000);                   
    ili9325_WriteReg(0x0053,0x013f); 

    ili9325_WriteReg(0x0060,0xa700);        
    ili9325_WriteReg(0x0061,0x0001); 
    ili9325_WriteReg(0x006a,0x0000);
    ili9325_WriteReg(0x0080,0x0000);
    ili9325_WriteReg(0x0081,0x0000);
    ili9325_WriteReg(0x0082,0x0000);
    ili9325_WriteReg(0x0083,0x0000);
    ili9325_WriteReg(0x0084,0x0000);
    ili9325_WriteReg(0x0085,0x0000);

    ili9325_WriteReg(0x0090,0x0010);     
    ili9325_WriteReg(0x0092,0x0600);  

    ili9325_WriteReg(0x0007,0x0133);
  } else if (DeviceCode == 0x9320 || DeviceCode == 0x9300) {
    ili9325_WriteReg(0x00,0x0000);
    ili9325_WriteReg(0x01,0x0100);	//Driver Output Contral.
    ili9325_WriteReg(0x02,0x0700);	//LCD Driver Waveform Contral.
    ili9325_WriteReg(0x03,0x1030);//Entry Mode Set.
    //ili9325_WriteReg(0x03,0x1018);	//Entry Mode Set.

    ili9325_WriteReg(0x04,0x0000);	//Scalling Contral.
    ili9325_WriteReg(0x08,0x0202);	//Display Contral 2.(0x0207)
    ili9325_WriteReg(0x09,0x0000);	//Display Contral 3.(0x0000)
    ili9325_WriteReg(0x0a,0x0000);	//Frame Cycle Contal.(0x0000)
    ili9325_WriteReg(0x0c,(1<<0));	//Extern Display Interface Contral 1.(0x0000)
    ili9325_WriteReg(0x0d,0x0000);	//Frame Maker Position.
    ili9325_WriteReg(0x0f,0x0000);	//Extern Display Interface Contral 2.	    
    ili9325_Delay(10); 
    ili9325_WriteReg(0x07,0x0101);	//Display Contral.
    ili9325_Delay(10); 								  
    ili9325_WriteReg(0x10,(1<<12)|(0<<8)|(1<<7)|(1<<6)|(0<<4));	//Power Control 1.(0x16b0)
    ili9325_WriteReg(0x11,0x0007);								//Power Control 2.(0x0001)
    ili9325_WriteReg(0x12,(1<<8)|(1<<4)|(0<<0));				//Power Control 3.(0x0138)
    ili9325_WriteReg(0x13,0x0b00);								//Power Control 4.
    ili9325_WriteReg(0x29,0x0000);								//Power Control 7.

    ili9325_WriteReg(0x2b,(1<<14)|(1<<4));	    
    ili9325_WriteReg(0x50,0);	//Set X Star
    //水平GRAM终止位置Set X End.
    ili9325_WriteReg(0x51,239);	//Set Y Star
    ili9325_WriteReg(0x52,0);	//Set Y End.t.
    ili9325_WriteReg(0x53,319);	//

    ili9325_WriteReg(0x60,0x2700);	//Driver Output Control.
    ili9325_WriteReg(0x61,0x0001);	//Driver Output Control.
    ili9325_WriteReg(0x6a,0x0000);	//Vertical Srcoll Control.

    ili9325_WriteReg(0x80,0x0000);	//Display Position? Partial Display 1.
    ili9325_WriteReg(0x81,0x0000);	//RAM Address Start? Partial Display 1.
    ili9325_WriteReg(0x82,0x0000);	//RAM Address End-Partial Display 1.
    ili9325_WriteReg(0x83,0x0000);	//Displsy Position? Partial Display 2.
    ili9325_WriteReg(0x84,0x0000);	//RAM Address Start? Partial Display 2.
    ili9325_WriteReg(0x85,0x0000);	//RAM Address End? Partial Display 2.

    ili9325_WriteReg(0x90,(0<<7)|(16<<0));	//Frame Cycle Contral.(0x0013)
    ili9325_WriteReg(0x92,0x0000);	//Panel Interface Contral 2.(0x0000)
    ili9325_WriteReg(0x93,0x0001);	//Panel Interface Contral 3.
    ili9325_WriteReg(0x95,0x0110);	//Frame Cycle Contral.(0x0110)
    ili9325_WriteReg(0x97,(0<<8));	//
    ili9325_WriteReg(0x98,0x0000);	//Frame Cycle Contral.	   
    ili9325_WriteReg(0x07,0x0173);	//(0x0173)
    ili9325_Delay(10);
  }
  //LCD_Clear(BACK_COLOR);
}

void ili9325_DisplayOn(void)
{
  // Power On sequence
  ili9325_WriteReg(LCD_REG_16, 0x0000); // SAP, BT[3:0], AP, DSTB, SLP, STB
  ili9325_WriteReg(LCD_REG_17, 0x0000); // DC1[2:0], DC0[2:0], VC[2:0]
  ili9325_WriteReg(LCD_REG_18, 0x0000); // VREG1OUT voltage
  ili9325_WriteReg(LCD_REG_19, 0x0000); // VDV[4:0] for VCOM amplitude

  ili9325_WriteReg(LCD_REG_16, 0x17B0); // SAP, BT[3:0], AP, DSTB, SLP, STB
  ili9325_WriteReg(LCD_REG_17, 0x0137); // DC1[2:0], DC0[2:0], VC[2:0]

  ili9325_WriteReg(LCD_REG_18, 0x0139); // VREG1OUT voltage

  ili9325_WriteReg(LCD_REG_19, 0x1d00); // VDV[4:0] for VCOM amplitude
  ili9325_WriteReg(LCD_REG_41, 0x0013); // VCM[4:0] for VCOMH
 
  // Display On
  ili9325_WriteReg(LCD_REG_7, 0x0173); // 262K color and display ON
}

void ili9325_DisplayOff(void)
{
  // Power Off sequence
  ili9325_WriteReg(LCD_REG_16, 0x0000); // SAP, BT[3:0], AP, DSTB, SLP, STB
  ili9325_WriteReg(LCD_REG_17, 0x0000); // DC1[2:0], DC0[2:0], VC[2:0]
  ili9325_WriteReg(LCD_REG_18, 0x0000); // VREG1OUT voltage
  ili9325_WriteReg(LCD_REG_19, 0x0000); // VDV[4:0] for VCOM amplitude
  
  ili9325_WriteReg(LCD_REG_41, 0x0000); // VCM[4:0] for VCOMH
  
  // Display Off
  ili9325_WriteReg(LCD_REG_7, 0x0); 
}

uint16_t ili9325_GetLcdPixelWidth(void)
{
 return (uint16_t)240;
}

uint16_t ili9325_GetLcdPixelHeight(void)
{
 return (uint16_t)320;
}

uint16_t ili9325_ReadID(void)
{
  LCD_IO_Init(); 
  return (ili9325_ReadReg(0x00));
}

void ili9325_SetCursor(uint16_t Xpos, uint16_t Ypos)
{
  //ili9325_WriteReg(LCD_REG_32, Ypos);
  //ili9325_WriteReg(LCD_REG_33, (ILI9325_LCD_PIXEL_WIDTH - 1 - Xpos));
  ili9325_WriteReg(LCD_REG_32, Xpos);
  ili9325_WriteReg(LCD_REG_33, Ypos);
}

void ili9325_WritePixel(uint16_t Xpos, uint16_t Ypos, uint16_t RGBCode)
{
  // Set Cursor
  ili9325_SetCursor(Xpos, Ypos);
  // Prepare to write GRAM
  LCD_IO_WriteReg(LCD_REG_34);
  // Write 16-bit GRAM Reg
  LCD_IO_WriteData(RGBCode);
}

uint16_t ili9325_ReadPixel(uint16_t Xpos, uint16_t Ypos)
{
  // Set Cursor
  ili9325_SetCursor(Xpos, Ypos);
  // Prepare to write GRAM
  LCD_IO_WriteReg(LCD_REG_34);
  // Dummy read
  LCD_IO_ReadData(0x00);
  // Read 16-bit Reg
  return (LCD_IO_ReadData(0x00));
}

void ili9325_SetDisplayWindow(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height)
{
  // Horizontal GRAM Start Address
  //ili9325_WriteReg(LCD_REG_80, (Ypos));
  // Horizontal GRAM End Address
  //ili9325_WriteReg(LCD_REG_81, (Ypos + Height - 1));
  
  // Vertical GRAM Start Address
  //ili9325_WriteReg(LCD_REG_82, ILI9325_LCD_PIXEL_WIDTH - Xpos - Width);
  // Vertical GRAM End Address
  //ili9325_WriteReg(LCD_REG_83, ILI9325_LCD_PIXEL_WIDTH - Xpos - 1);  
  
  ili9325_WriteReg(LCD_REG_80, Xpos);
  ili9325_WriteReg(LCD_REG_81, Xpos + Width);
  ili9325_WriteReg(LCD_REG_82, Ypos);
  ili9325_WriteReg(LCD_REG_83, Ypos + Height);

  ili9325_SetCursor(Xpos, Ypos);
}

void ili9325_DrawHLine(uint16_t Color, uint16_t Xpos, uint16_t Ypos, uint16_t Length)
{
  uint16_t i = 0;
  // Fill a complete horizontal line
  for(i = 0; i < Length; i++) {
    ArrayRGB[i] = Color;
  }
  // Set Cursor
  ili9325_SetCursor(Xpos, Ypos); 
  // Prepare to write GRAM
  LCD_IO_WriteReg(LCD_REG_34);
  // Sent a complete line
  LCD_IO_WriteDataBuffer(ArrayRGB, Length);
}

void ili9325_DrawVLine(uint16_t Color, uint16_t Xpos, uint16_t Ypos, uint16_t Length)
{
  uint16_t i = 0;
  // Fill a complete vertical line
  for(i = 0; i < Length; i++) {
    ArrayRGB[i] = Color;
  }

  ili9325_WriteReg(LCD_REG_3,  0x1038); // set GRAM write direction and BGR = 1
                                        // I/D=11 (Horizontal : increment, Vertical : increment)
                                        // AM=1 (address is updated in vertical writing direction)
  //ili9325_WriteReg(LCD_REG_3, 0x1010);  // set GRAM write direction and BGR = 1
                                        // I/D=00 (Horizontal : increment, Vertical : decrement)
                                        // AM=1 (address is updated in vertical writing direction)
  // Set Cursor
  ili9325_SetCursor(Xpos, Ypos);
  // Prepare to write GRAM
  LCD_IO_WriteReg(LCD_REG_34);
  // Write 16-bit GRAM Reg
  LCD_IO_WriteDataBuffer(ArrayRGB, Length);
 
  ili9325_WriteReg(LCD_REG_3,  0x1030); // set GRAM write direction and BGR = 1
                                        // I/D=11 (Horizontal : increment, Vertical : increment)
                                        // AM=0 (address is updated in horizontal writing direction)
  //ili9325_WriteReg(LCD_REG_3, 0x1018);  // set GRAM write direction and BGR = 1
                                        // I/D=00 (Horizontal : increment, Vertical : decrement)
                                        // AM=1 (address is updated in vertical writing direction)
}

void ili9325_DrawBitmap(uint16_t Xpos, uint16_t Ypos, uint8_t *pbmp)
{
  uint32_t index = 0, size = 0;
  // Read bitmap size
  size = *(volatile uint16_t *) (pbmp + 2);
  size |= (*(volatile uint16_t *) (pbmp + 4)) << 16;
  // Get bitmap data address offset
  index = *(volatile uint16_t *) (pbmp + 10);
  index |= (*(volatile uint16_t *) (pbmp + 12)) << 16;
  size = (size - index)/2;
  pbmp += index;
  // Set GRAM write direction and BGR = 1
  // I/D=00 (Horizontal : decrement, Vertical : decrement)
  // AM=1 (address is updated in vertical writing direction)
  //ili9325_WriteReg(LCD_REG_3, 0x1008);

  // Set Cursor
  //ili9325_SetCursor(Xpos, Ypos);  
  
  // Prepare to write GRAM
  LCD_IO_WriteReg(LCD_REG_34);
  LCD_IO_WriteDataBuffer((uint16_t*)pbmp, size / 2);
 
  // Set GRAM write direction and BGR = 1 */
  // I/D = 01 (Horizontal : increment, Vertical : decrement) */
  // AM = 1 (address is updated in vertical writing direction) */
  //ili9325_WriteReg(LCD_REG_3, 0x1018);
}

void ili9325_DrawRGBImage(uint8_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height, uint8_t *Bitmap)
{
  uint32_t Size = Height * Width;

  ili9325_SetDisplayWindow(Xpos, Ypos, Width - 1, Height - 1);

  LCD_IO_WriteReg(LCD_REG_34);
  LCD_IO_WriteDataBuffer((uint16_t *)Bitmap, Size);

  ili9325_SetDisplayWindow(0, 0, ili9325_GetLcdPixelWidth() - 1, ili9325_GetLcdPixelHeight() - 1);
}

/*
void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
	uint16_t t; 
	int xerr=0,yerr=0,delta_x,delta_y,distance; 
	int incx,incy,uRow,uCol; 

	delta_x=x2-x1; 				//计算坐标增量 
	delta_y=y2-y1; 
	uRow=x1; 
	uCol=y1; 
	if(delta_x>0)incx=1; 		//设置单步方向 
	else if(delta_x==0)incx=0;	//垂直线 
	else {incx=-1;delta_x=-delta_x;} 
	if(delta_y>0)incy=1; 
	else if(delta_y==0)incy=0;	//水平线 
	else{incy=-1;delta_y=-delta_y;} 
	if( delta_x>delta_y)distance=delta_x; //选取基本增量坐标轴 
	else distance=delta_y; 
	for(t=0;t<=distance+1;t++ )	//画线输出 
	{  
		LCD_DrawPoint(uRow,uCol);//画点 
		xerr+=delta_x ; 
		yerr+=delta_y ; 
		if(xerr>distance) 
		{ 
			xerr-=distance; 
			uRow+=incx; 
		} 
		if(yerr>distance) 
		{ 
			yerr-=distance; 
			uCol+=incy; 
		} 
	}  
}

void Draw_Circle(uint8_t x0,uint16_t y0,uint8_t r)
{
	int a,b;
	int di;
	a=0;b=r;	  
	di=3-(r<<1);             //判断下个点位置的标志
	while(a<=b)
	{
		LCD_DrawPoint(x0-b,y0-a);             //3           
		LCD_DrawPoint(x0+b,y0-a);             //0           
		LCD_DrawPoint(x0-a,y0+b);             //1       
		LCD_DrawPoint(x0-b,y0-a);             //7           
		LCD_DrawPoint(x0-a,y0-b);             //2             
		LCD_DrawPoint(x0+b,y0+a);             //4               
		LCD_DrawPoint(x0+a,y0-b);             //5
		LCD_DrawPoint(x0+a,y0+b);             //6 
		LCD_DrawPoint(x0-b,y0+a);             
		a++;
		//使用Bresenham算法画圆     
		if(di<0)di +=4*a+6;	  
		else
		{
			di+=10+4*(a-b);   
			b--;
		} 
		LCD_DrawPoint(x0+a,y0+b);
	}
} 

void LCD_Fill(uint8_t xsta,uint16_t ysta,uint8_t xend,uint16_t yend,uint16_t color)
{                    
    uint32_t n;
	//设置窗口										
	ili9325_WriteReg(R80, xsta); //水平方向GRAM起始地址
	ili9325_WriteReg(R81, xend); //水平方向GRAM结束地址
	ili9325_WriteReg(R82, ysta); //垂直方向GRAM起始地址
	ili9325_WriteReg(R83, yend); //垂直方向GRAM结束地址	
	LCD_SetCursor(xsta,ysta);//设置光标位置  
	LCD_WriteRAM_Prepare();  //开始写入GRAM	 	   	   
	n=(uint32_t)(yend-ysta+1)*(xend-xsta+1);    
	while(n--){Write_Dat(color);}//显示所填充的颜色. 
	//恢复设置
	ili9325_WriteReg(R80, 0x0000); //水平方向GRAM起始地址
	ili9325_WriteReg(R81, 0x00EF); //水平方向GRAM结束地址
	ili9325_WriteReg(R82, 0x0000); //垂直方向GRAM起始地址
	ili9325_WriteReg(R83, 0x013F); //垂直方向GRAM结束地址	    
}
*/
