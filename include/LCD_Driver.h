/*****************************************************************************
* | File        :   LCD_Driver.h
* | Author      :   Nik Cher
* | Function    :   LCD Driver Functions Decleration             
*----------------
* | This version:   V1.0
* | Date        :   2023-06-09
******************************************************************************/
#include <stdint.h>
#include <stdio.h>
#include <SPI.h>
#include <avr/pgmspace.h>
#include "pin_configs.h"

#define UBYTE   uint8_t
#define UWORD   uint16_t
#define UDOUBLE uint32_t

#define LCD_WIDTH   240   //Temp Width
#define LCD_HEIGHT  240   //Temp Height

#define LCD_Set_BL(_Value)  analogWrite(LCD_BL, _Value)

void LCD_Init(void);
void LCD_WriteData_Byte(UBYTE data); 
void LCD_WriteData_Word(UWORD data);
void LCD_WriteReg(UBYTE data);
void LCD_SetCursor(UWORD Xstart, UWORD Ystart, UWORD Xend, UWORD  Yend);
void LCD_Clear(UWORD Color);

