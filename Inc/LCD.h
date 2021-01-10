#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>


void LCD_init(I2C_HandleTypeDef *i2cpointer);
void LCD_set_cursor(uint8_t row, uint8_t col);
void LCD_clear(void);
void LCD_display(const char* text, ...);
void Set_LCD(uint8_t address);

