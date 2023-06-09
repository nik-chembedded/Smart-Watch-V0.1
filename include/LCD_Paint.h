/*****************************************************************************
* | File        :   LCD_Paint.h
* | Author      :   Nik Cher
* | Function    :   LCD Paint Functions Decleration             
*----------------
* | This version:   V1.0
* | Date        :   2023-06-09
******************************************************************************/
#include <string.h>
#include <math.h>
#include "pin_configs.h"
#include "LCD_Driver.h"

#define WHITE         0xFFFF
#define BLACK         0x0000    
#define BLUE          0x001F  
#define BRED          0XF81F
#define GRED          0XFFE0
#define GBLUE         0X07FF
#define RED           0xF800
#define MAGENTA       0xF81F
#define GREEN         0x07E0
#define CYAN          0x7FFF
#define YELLOW        0xFFE0
#define BROWN         0XBC40 
#define BRRED         0XFC07 
#define GRAY          0X8430 
#define DARKBLUE      0X01CF  
#define LIGHTBLUE     0X7D7C   
#define GRAYBLUE      0X5458 
#define LIGHTGREEN    0X841F 
#define LGRAY         0XC618 
#define LGRAYBLUE     0XA651
#define LBBLUE        0X2B12 