#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#define lcd_1     1
#define lcd_2     2

void LCD_init(I2C_HandleTypeDef *i2cpointer);
void LCD_set_cursor(uint8_t lcd_number, uint8_t row, uint8_t col);
void LCD_clear(lcd_number);
void LCD_display(uint8_t lcd_number, const char* text, ...);
void Set_LCD(uint8_t lcd_number);
