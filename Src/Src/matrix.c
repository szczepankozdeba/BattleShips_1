#include "main.h"
#include "matrix.h"


uint16_t delay_time = 300;

const uint8_t all_matrix_number = 4;

uint8_t matrix_LED_list[8][8] = {0};
GPIO_TypeDef* Port_list[8];
uint16_t Pin_list[8];
uint8_t matrix_on_list_a=0;
uint8_t matrix_on_list_b=1;


void matrix_init(GPIO_TypeDef* PORT, uint16_t PIN, Matrix_struct* matrix_name)
{

	spi_send(0x09, 0x00, PORT, PIN);         //  no decoding
	spi_send(0x0a, 0x01, PORT, PIN);         //  brightness intensity
	spi_send(0x0b, 0x07, PORT, PIN);         //  scan limit = 8 LEDs
	spi_send(0x0c, 0x01, PORT, PIN);         //  power down =0，normal mode = 1
	spi_send(0x0f, 0x00, PORT, PIN);         //  no test display


	matrix_name->Port = PORT;
	Port_list[matrix_on_list_a] = PORT;
	Port_list[matrix_on_list_b] = PORT;
	matrix_name->Pin = PIN;
	Pin_list[matrix_on_list_a] = PIN;
	Pin_list[matrix_on_list_b] = PIN;
	matrix_name->matrix_a=matrix_on_list_a;
	matrix_name->matrix_b=matrix_on_list_b;

	matrix_on_list_a=matrix_on_list_a +2;
	matrix_on_list_b=matrix_on_list_b +2;

}

void matrix_send_all(void)
{
	for (uint8_t m=0;m<(2*all_matrix_number);m=m+2)
	{
		for(uint8_t n=0;n<8;n++)
			spi_send(n+1, matrix_LED_list[m][n],Port_list[m],Pin_list[m]);
	}
	HAL_Delay(delay_time);

	for (uint8_t m=1;m<(2*all_matrix_number);m=m+2)
	{
		for(uint8_t n=0;n<8;n++)
			spi_send(n+1, matrix_LED_list[m][n],Port_list[m],Pin_list[m]);
	}
	HAL_Delay(delay_time);

}



void matrix_set_blink_time(uint16_t time)
{
	delay_time=time;
}

void matrix_LED_on_row(Matrix_struct* matrix_name, uint8_t row, uint8_t LED)
{
	matrix_LED_list[matrix_name->matrix_a][row-1] = LED;
	matrix_LED_list[matrix_name->matrix_b][row-1] = LED;
}

void matrix_LED_on(Matrix_struct* matrix_name, uint8_t x, uint8_t y)
{
	matrix_LED_list[matrix_name->matrix_a][x-1] |= (1<<(y-1));
	matrix_LED_list[matrix_name->matrix_b][x-1] |= (1<<(y-1));
}


void matrix_LED_off(Matrix_struct* matrix_name, uint8_t x, uint8_t y)
{
	matrix_LED_list[matrix_name->matrix_a][x-1] &= ~(1<<(y-1));
	matrix_LED_list[matrix_name->matrix_b][x-1] &= ~(1<<(y-1));
}


void matrix_LED_blink_row(Matrix_struct* matrix_name, uint8_t row, uint8_t LED)
{
	matrix_LED_list[matrix_name->matrix_a][row-1] = LED;
	matrix_LED_list[matrix_name->matrix_b][row-1] = 0b00000000;

}

void matrix_LED_blink(Matrix_struct* matrix_name, uint8_t x, uint8_t y)
{
	matrix_LED_list[matrix_name->matrix_a][x-1] |= (1<<(y-1));
	matrix_LED_list[matrix_name->matrix_b][x-1] &= ~(1<<(y-1));
}

void matrix_clear(Matrix_struct* matrix_name)
{
	for (uint8_t z=0; z<8; z++)
	{
		matrix_LED_list[matrix_name->matrix_a][z] = 0b00000000;
		uint8_t a = matrix_LED_list[matrix_name->matrix_a][z];
		uint8_t b = matrix_name->matrix_b;
		matrix_LED_list[matrix_name->matrix_b][z] = 0b00000000;
		b = matrix_LED_list[matrix_name->matrix_b][z];
	}
}
