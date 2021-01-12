
#include "LCD.h"
static I2C_HandleTypeDef*  hi2c;


static uint8_t LCD_address = 0x4E;

void Set_LCD(uint8_t lcd_nr)
{
	if (lcd_nr == 1)
		LCD_address = 0x4E;
	else
		LCD_address = 0x7E;
}

static void LCD_sendCommand(uint8_t command)
{
  const uint8_t command03 = (0xF0 & (command << 4));
  const uint8_t command47 = (0xF0 & command);
  uint8_t data[4] = {command47 | 0x04 | 0x08,command47 | 0x08,command03 | 0x04 | 0x08,command03 | 0x08,};

   HAL_I2C_Master_Transmit(hi2c, LCD_address, data, 4, 200);
}

static void LCD_sendData(uint8_t data1)
{
  const uint8_t byte03 = (0xF0 & (data1 << 4));
  const uint8_t byte47 = (0xF0 & data1);
  uint8_t data[4] = {byte47 | 0x04 | 0x08 | 0x01, byte47 | 0x08 | 0x01, byte03 | 0x04 | 0x08 | 0x01, byte03 | 0x08 | 0x01,};

    HAL_I2C_Master_Transmit(hi2c, LCD_address, data, 4, 200);
}



void LCD_init(uint8_t lcd_number, I2C_HandleTypeDef *i2cpointer)
{
	//uint8_t arg = lcd_number;
	Set_LCD(lcd_number);

    HAL_Delay(50);

    hi2c = i2cpointer;

    HAL_Delay(50);

    LCD_sendCommand(0x30);
    HAL_Delay(5);
    LCD_sendCommand(0x30);
    HAL_Delay(1);
    LCD_sendCommand(0x30);
    HAL_Delay(8);
    LCD_sendCommand(0x20);
    HAL_Delay(8);

    LCD_sendCommand(0x20 | 0x08);
    HAL_Delay(1);
    LCD_sendCommand(0x08);
    HAL_Delay(1);
    LCD_sendCommand(0x01);
    HAL_Delay(3);
    LCD_sendCommand(0x04 | 0x02);
    HAL_Delay(1);
    LCD_sendCommand(0x08 | 0x04);
    HAL_Delay(3);

    LCD_clear(lcd_1);
    LCD_clear(lcd_2);

}


void LCD_set_cursor(uint8_t lcd_number, uint8_t row, uint8_t col)
{
	Set_LCD(lcd_number);

    uint8_t cursor_data;
    cursor_data = (col) & 0x0F;
    if(row == 0)
    {
    	cursor_data |= 0x80;
    	LCD_sendCommand(cursor_data);
    }
    else
    {
    	cursor_data |= 0xC0;
    	LCD_sendCommand(cursor_data);
    }
}

void LCD_clear(uint8_t lcd_number)
{
	Set_LCD(lcd_number);

	LCD_sendCommand(0x01);
	HAL_Delay(3);
}


void LCD_display(uint8_t lcd_number,const char* text, ...)
{

	Set_LCD(lcd_number);

	char text_tab[20];
	va_list va_text;

	va_start(va_text, text);
	vsprintf(text_tab, text, va_text);
	va_end(va_text);

	for(uint8_t i = 0;  i < strlen(text_tab) && i < 16; i++)
	{
		LCD_sendData((uint8_t)text_tab[i]);
	}
}
