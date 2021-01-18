#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#ifndef __LCD_H__
#define __LCD_H__

#define lcd_1     1
#define lcd_2     2

void LCD_init(uint8_t lcd_number, I2C_HandleTypeDef *i2cpointer);
void LCD_set_cursor(uint8_t lcd_number, uint8_t row, uint8_t col);
void LCD_clear(uint8_t lcd_number);
void LCD_display(uint8_t lcd_number, const char* text, ...);
void Set_LCD(uint8_t lcd_number);

#endif
