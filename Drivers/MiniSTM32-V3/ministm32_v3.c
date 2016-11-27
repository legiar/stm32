#include "ministm32_v3.h"

void LCD_IO_Init(void);
void LCD_IO_WriteReg(uint16_t Reg);
void LCD_IO_WriteData(uint16_t Data);
void LCD_IO_WriteDataBuffer(uint16_t *pData, uint32_t Size);
uint16_t LCD_IO_ReadData(uint16_t Reg);

void LCD_IO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;

  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  
  HAL_GPIO_WritePin(GPIOC, LCD_DB00_Pin | LCD_DB01_Pin | LCD_DB02_Pin | LCD_DB03_Pin 
                           | LCD_DB04_Pin | LCD_DB05_Pin | LCD_DB06_Pin | LCD_DB07_Pin 
                           | LCD_CS_Pin | LCD_RS_Pin | LCD_WR_Pin | LCD_RD_Pin, GPIO_PIN_RESET);
  
  HAL_GPIO_WritePin(GPIOB, LCD_DB08_Pin | LCD_DB09_Pin | LCD_DB10_Pin | LCD_DB11_Pin 
                           | LCD_DB12_Pin | LCD_DB13_Pin | LCD_DB14_Pin | LCD_DB15_Pin, GPIO_PIN_RESET);

  GPIO_InitStruct.Pin = LCD_DB00_Pin | LCD_DB01_Pin | LCD_DB02_Pin | LCD_DB03_Pin 
                        | LCD_DB04_Pin | LCD_DB05_Pin | LCD_DB06_Pin | LCD_DB07_Pin 
                        | LCD_CS_Pin | LCD_RS_Pin | LCD_WR_Pin | LCD_RD_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = LCD_DB08_Pin | LCD_DB09_Pin | LCD_DB10_Pin | LCD_DB11_Pin
                        | LCD_DB12_Pin | LCD_DB13_Pin | LCD_DB14_Pin | LCD_DB15_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    
  // Set or Reset the control line
  LCD_CS_LOW();
  LCD_CS_HIGH();
}

void LCD_IO_WriteReg(uint16_t Reg) 
{
  LCD_CS_LOW();
  
  LCD_RS_LOW();  // Enable Register Selection Signal
  GPIOC->ODR = (GPIOC->ODR & 0xff00) | (Reg & 0x00ff);
  GPIOB->ODR = (GPIOB->ODR & 0x00ff) | (Reg & 0xff00); 
  LCD_WR_LOW();  // Enable Write
  LCD_WR_HIGH(); // Disable Write
  
  LCD_CS_HIGH();
}

void LCD_IO_WriteData(uint16_t Data)
{
  LCD_CS_LOW();
  
  LCD_RS_HIGH(); // Disable Register Selection Signal
  GPIOC->ODR = (GPIOC->ODR & 0xff00) | (Data & 0x00ff);
  GPIOB->ODR = (GPIOB->ODR & 0x00ff) | (Data & 0xff00); 
  LCD_WR_LOW();  // Enable Write
  LCD_WR_HIGH(); // Disable Write
  
  LCD_CS_HIGH();
}

void LCD_IO_WriteDataBuffer(uint16_t *pData, uint32_t Size)
{
  uint32_t i = 0;

  LCD_CS_LOW();
  
  LCD_RS_HIGH();
  
  for (i = 0; i < Size; i++) {
    GPIOC->ODR = (GPIOC->ODR & 0xff00) | (pData[i] & 0x00ff);
    GPIOB->ODR = (GPIOB->ODR & 0x00ff) | (pData[i] & 0xff00);
    
    LCD_WR_LOW();
    LCD_WR_HIGH();
  }
  LCD_CS_HIGH();
}

uint16_t LCD_IO_ReadData(uint16_t Reg) 
{
  uint32_t readValue = 0;

  LCD_IO_WriteReg(Reg);

  GPIOB->CRH = (GPIOB->CRH & 0x00000000) | 0x44444444;
  GPIOC->CRL = (GPIOC->CRL & 0x00000000) | 0x44444444;

  LCD_CS_LOW();
  LCD_RS_HIGH(); // Disable Register Selection Signal
  LCD_RD_LOW();  // Enable Read Mode
  readValue = ((GPIOB->IDR & 0xff00)|(GPIOC->IDR & 0x00ff));
  LCD_RD_HIGH(); // Disable Read Mode

  LCD_CS_HIGH(); 
  
  GPIOB->CRH = (GPIOB->CRH & 0x00000000) | 0x33333333;
  GPIOC->CRL = (GPIOC->CRL & 0x00000000) | 0x33333333;
  
  return readValue;   
}

void LCD_IO_Delay(uint32_t nCount)
{
  HAL_Delay(nCount);
}
