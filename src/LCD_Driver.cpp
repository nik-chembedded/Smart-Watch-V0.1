/*****************************************************************************
* | File        :   LCD_Driver.cpp
* | Author      :   Nik Cher
* | Function    :   LCD Driver Functions Implementation           
*----------------
* | This version:   V1.0
* | Date        :   2023-06-09
******************************************************************************/
#include "LCD_Driver.h"

/*******************************************************************************
function:
  LCD hardware eset
*******************************************************************************/

static void LCD_Reset(void)
{
    digitalWrite(LCD_CS, LOW);
    delay(100);
    digitalWrite(LCD_RST, LOW);
    delay(100);
    digitalWrite(LCD_RST, HIGH);
    delay(100);
}

/*******************************************************************************
function:
    Write to command register and data register
*******************************************************************************/

void LCD_WriteData_Byte(UBYTE data)
{
    digitalWrite(LCD_CS, LOW);
    digitalWrite(LCD_DC, HIGH);
    SPI.transfer(data);
    digitalWrite(LCD_CS, HIGH);
}

void LCD_WriteData_Word(UWORD data)
{
    digitalWrite(LCD_CS, LOW);
    digitalWrite(LCD_DC, HIGH);
    SPI.transfer(data >> 8);
    SPI.transfer(data);
    digitalWrite(LCD_CS, HIGH);
}

void LCD_WriteReg(UBYTE data)
{
    digitalWrite(LCD_CS, LOW);
    digitalWrite(LCD_DC, LOW);
    SPI.transfer(data);
}

/******************************************************************************
function: Set the cursor position
parameter :
    Xstart:   Start UWORD x coordinate
    Ystart:   Start UWORD y coordinate
    Xend  :   End UWORD coordinates
    Yend  :   End UWORD coordinatesen
******************************************************************************/
void LCD_SetCursor(UWORD Xstart, UWORD Ystart, UWORD Xend, UWORD  Yend)
{ 
  LCD_WriteReg(0x2a);
  LCD_WriteData_Byte(0x00);
  LCD_WriteData_Byte(Xstart);
  LCD_WriteData_Byte(0x00);  
  LCD_WriteData_Byte(Xend);     /*********Xend-1********/
  
  LCD_WriteReg(0x2b);
  LCD_WriteData_Byte(0x00);
  LCD_WriteData_Byte(Ystart);
  LCD_WriteData_Byte(0x00);
  LCD_WriteData_Byte(Yend);
  
  LCD_WriteReg(0x2c);
}

/******************************************************************************
function: Clear screen function, refresh the screen to a certain color
input parameter : Color - The color you want to clear all the screen
******************************************************************************/
void LCD_Clear(UWORD Color)
{
  UWORD i,j;    
  LCD_SetCursor(0,0,LCD_WIDTH-1,LCD_HEIGHT-1);
  for(i = 0; i < LCD_WIDTH; i++){
    for(j = 0; j < LCD_HEIGHT; j++){
      LCD_WriteData_Word(Color);
    }
   }
}

/******************************************************************************
function: 
    Common register initialization
******************************************************************************/

void LCD_Init()
{
    LCD_Reset();

 	LCD_WriteReg(0xEF);
	LCD_WriteReg(0xEB);
	LCD_WriteData_Byte(0x14); 
	
    LCD_WriteReg(0xFE);			 
	LCD_WriteReg(0xEF); 

	LCD_WriteReg(0xEB);	
	LCD_WriteData_Byte(0x14); 

	LCD_WriteReg(0x84);			
	LCD_WriteData_Byte(0x40); 

	LCD_WriteReg(0x85);			
	LCD_WriteData_Byte(0xFF); 

	LCD_WriteReg(0x86);			
	LCD_WriteData_Byte(0xFF); 

	LCD_WriteReg(0x87);			
	LCD_WriteData_Byte(0xFF);

	LCD_WriteReg(0x88);			
	LCD_WriteData_Byte(0x0A);

	LCD_WriteReg(0x89);			
	LCD_WriteData_Byte(0x21); 

	LCD_WriteReg(0x8A);			
	LCD_WriteData_Byte(0x00); 

	LCD_WriteReg(0x8B);			
	LCD_WriteData_Byte(0x80); 

	LCD_WriteReg(0x8C);			
	LCD_WriteData_Byte(0x01); 

	LCD_WriteReg(0x8D);			
	LCD_WriteData_Byte(0x01); 

	LCD_WriteReg(0x8E);			
	LCD_WriteData_Byte(0xFF); 

	LCD_WriteReg(0x8F);			
	LCD_WriteData_Byte(0xFF); 


	LCD_WriteReg(0xB6);
	LCD_WriteData_Byte(0x00);
	LCD_WriteData_Byte(0x20);

	LCD_WriteReg(0x36);
	LCD_WriteData_Byte(0x08);

	LCD_WriteReg(0x3A);			
	LCD_WriteData_Byte(0x05); 


	LCD_WriteReg(0x90);			
	LCD_WriteData_Byte(0x08);
	LCD_WriteData_Byte(0x08);
	LCD_WriteData_Byte(0x08);
	LCD_WriteData_Byte(0x08); 

	LCD_WriteReg(0xBD);			
	LCD_WriteData_Byte(0x06);
	
	LCD_WriteReg(0xBC);			
	LCD_WriteData_Byte(0x00);	

	LCD_WriteReg(0xFF);			
	LCD_WriteData_Byte(0x60);
	LCD_WriteData_Byte(0x01);
	LCD_WriteData_Byte(0x04);

	LCD_WriteReg(0xC3);			
	LCD_WriteData_Byte(0x13);
	LCD_WriteReg(0xC4);			
	LCD_WriteData_Byte(0x13);

	LCD_WriteReg(0xC9);			
	LCD_WriteData_Byte(0x22);

	LCD_WriteReg(0xBE);			
	LCD_WriteData_Byte(0x11); 

	LCD_WriteReg(0xE1);			
	LCD_WriteData_Byte(0x10);
	LCD_WriteData_Byte(0x0E);

	LCD_WriteReg(0xDF);			
	LCD_WriteData_Byte(0x21);
	LCD_WriteData_Byte(0x0c);
	LCD_WriteData_Byte(0x02);

	LCD_WriteReg(0xF0);   
	LCD_WriteData_Byte(0x45);
	LCD_WriteData_Byte(0x09);
	LCD_WriteData_Byte(0x08);
	LCD_WriteData_Byte(0x08);
	LCD_WriteData_Byte(0x26);
 	LCD_WriteData_Byte(0x2A);

 	LCD_WriteReg(0xF1);    
 	LCD_WriteData_Byte(0x43);
 	LCD_WriteData_Byte(0x70);
 	LCD_WriteData_Byte(0x72);
 	LCD_WriteData_Byte(0x36);
 	LCD_WriteData_Byte(0x37);  
 	LCD_WriteData_Byte(0x6F);


 	LCD_WriteReg(0xF2);   
 	LCD_WriteData_Byte(0x45);
 	LCD_WriteData_Byte(0x09);
 	LCD_WriteData_Byte(0x08);
 	LCD_WriteData_Byte(0x08);
 	LCD_WriteData_Byte(0x26);
 	LCD_WriteData_Byte(0x2A);

 	LCD_WriteReg(0xF3);   
 	LCD_WriteData_Byte(0x43);
 	LCD_WriteData_Byte(0x70);
 	LCD_WriteData_Byte(0x72);
 	LCD_WriteData_Byte(0x36);
 	LCD_WriteData_Byte(0x37); 
 	LCD_WriteData_Byte(0x6F);

	LCD_WriteReg(0xED);	
	LCD_WriteData_Byte(0x1B); 
	LCD_WriteData_Byte(0x0B); 

	LCD_WriteReg(0xAE);			
	LCD_WriteData_Byte(0x77);
	
	LCD_WriteReg(0xCD);			
	LCD_WriteData_Byte(0x63);		


	LCD_WriteReg(0x70);			
	LCD_WriteData_Byte(0x07);
	LCD_WriteData_Byte(0x07);
	LCD_WriteData_Byte(0x04);
	LCD_WriteData_Byte(0x0E); 
	LCD_WriteData_Byte(0x0F); 
	LCD_WriteData_Byte(0x09);
	LCD_WriteData_Byte(0x07);
	LCD_WriteData_Byte(0x08);
	LCD_WriteData_Byte(0x03);

	LCD_WriteReg(0xE8);			
	LCD_WriteData_Byte(0x34);

	LCD_WriteReg(0x62);			
	LCD_WriteData_Byte(0x18);
	LCD_WriteData_Byte(0x0D);
	LCD_WriteData_Byte(0x71);
	LCD_WriteData_Byte(0xED);
	LCD_WriteData_Byte(0x70); 
	LCD_WriteData_Byte(0x70);
	LCD_WriteData_Byte(0x18);
	LCD_WriteData_Byte(0x0F);
	LCD_WriteData_Byte(0x71);
	LCD_WriteData_Byte(0xEF);
	LCD_WriteData_Byte(0x70); 
	LCD_WriteData_Byte(0x70);

	LCD_WriteReg(0x63);			
	LCD_WriteData_Byte(0x18);
	LCD_WriteData_Byte(0x11);
	LCD_WriteData_Byte(0x71);
	LCD_WriteData_Byte(0xF1);
	LCD_WriteData_Byte(0x70); 
	LCD_WriteData_Byte(0x70);
	LCD_WriteData_Byte(0x18);
	LCD_WriteData_Byte(0x13);
	LCD_WriteData_Byte(0x71);
	LCD_WriteData_Byte(0xF3);
	LCD_WriteData_Byte(0x70); 
	LCD_WriteData_Byte(0x70);

	LCD_WriteReg(0x64);			
	LCD_WriteData_Byte(0x28);
	LCD_WriteData_Byte(0x29);
	LCD_WriteData_Byte(0xF1);
	LCD_WriteData_Byte(0x01);
	LCD_WriteData_Byte(0xF1);
	LCD_WriteData_Byte(0x00);
	LCD_WriteData_Byte(0x07);

	LCD_WriteReg(0x66);			
	LCD_WriteData_Byte(0x3C);
	LCD_WriteData_Byte(0x00);
	LCD_WriteData_Byte(0xCD);
	LCD_WriteData_Byte(0x67);
	LCD_WriteData_Byte(0x45);
	LCD_WriteData_Byte(0x45);
	LCD_WriteData_Byte(0x10);
	LCD_WriteData_Byte(0x00);
	LCD_WriteData_Byte(0x00);
	LCD_WriteData_Byte(0x00);

	LCD_WriteReg(0x67);			
	LCD_WriteData_Byte(0x00);
	LCD_WriteData_Byte(0x3C);
	LCD_WriteData_Byte(0x00);
	LCD_WriteData_Byte(0x00);
	LCD_WriteData_Byte(0x00);
	LCD_WriteData_Byte(0x01);
	LCD_WriteData_Byte(0x54);
	LCD_WriteData_Byte(0x10);
	LCD_WriteData_Byte(0x32);
	LCD_WriteData_Byte(0x98);

	LCD_WriteReg(0x74);			
	LCD_WriteData_Byte(0x10);	
	LCD_WriteData_Byte(0x85);	
	LCD_WriteData_Byte(0x80);
	LCD_WriteData_Byte(0x00); 
	LCD_WriteData_Byte(0x00); 
	LCD_WriteData_Byte(0x4E);
	LCD_WriteData_Byte(0x00);					
	
    LCD_WriteReg(0x98);			
	LCD_WriteData_Byte(0x3e);
	LCD_WriteData_Byte(0x07);

	LCD_WriteReg(0x35);	
	LCD_WriteReg(0x21);

	LCD_WriteReg(0x11);
	delay(120);
	LCD_WriteReg(0x29);
	delay(20);
}

