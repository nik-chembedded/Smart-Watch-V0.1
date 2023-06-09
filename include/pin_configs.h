/*****************************************************************************
* | File        :   pin_configs.h
* | Author      :   Nik Cher
* | Function    :   Board Pin Declerations             
*----------------
* | This version:   V1.0
* | Date        :   2023-06-09
******************************************************************************/
#include <Arduino.h>

//////////////////////////////////////////////////////
/////////                                    /////////
/////////     INCLUDE ALL PIN NUMBERS HERE   /////////
/////////                                    /////////
//////////////////////////////////////////////////////

#define LCD_CLK     1           // LCD - SPI Clock Pin
#define LCD_MOSI    2           // LCD - SPI MOSI Pin
#define LCD_MISO    3           // LCD - MISO Pin             
#define LCD_CS      4           // LCD - Chip Select Pin
#define LCD_DC      5           // LCD - Data or Command Indication Pin
#define LCD_RST     6           // LCD - Reset Pin
#define LCD_BL      7           // LCD - Backlight Pin