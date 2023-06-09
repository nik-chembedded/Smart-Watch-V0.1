/*****************************************************************************
* | File        :   main.cpp
* | Author      :   Nik Cher
* | Function    :   Main Program Entry         
*----------------
* | This version:   V1.0
* | Date        :   2023-06-09
******************************************************************************/
#include <Arduino.h>
#include "pin_configs.h"
#include "LCD_Driver.h"

#define BAUD_RATE       115200
#define DEFUALT_LCD_BL  140

static void Internal_HW_Init(void);
static void External_HW_Init(void);


void setup() {
  // put your setup code here, to run once:
  Internal_HW_Init();
  External_HW_Init();
}

void loop() {
  // put your main code here, to run repeatedly:
}

static void Internal_HW_Init(void)
{
  pinMode(LCD_CS, OUTPUT);
  pinMode(LCD_RST, OUTPUT);
  pinMode(LCD_DC, OUTPUT);
  pinMode(LCD_BL, OUTPUT);
  analogWrite(LCD_BL, DEFUALT_LCD_BL);

  // Serial Port Init
  Serial.begin(BAUD_RATE);

  // SPI Init
  SPI.setDataMode(SPI_MODE3);
  SPI.setBitOrder(MSBFIRST);
  SPI.setClockDivider(SPI_CLOCK_DIV4);
  SPI.begin();
}

static void External_HW_Init(void)
{
  LCD_Init();
  LCD_Set_BL(1000);
}
