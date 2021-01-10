#include "main.h"
#include "matrix.h"



void matrices_init(void)
{

	for (uint8_t i=0; i<8;i++)
	{
		matrix_player1_friendly_a [i] = 0b00000000;
		matrix_player1_friendly_b [i] = 0b00000000;
		matrix_player1_enemy_a [i] = 0b00000000;
		matrix_player1_enemy_b [i] = 0b00000000;
		matrix_player2_friendly_a [i] = 0b00000000;
		matrix_player2_friendly_b [i] = 0b00000000;
		matrix_player2_enemy_a [i] = 0b00000000;
		matrix_player2_enemy_b [i] = 0b00000000;
	}

	spi_send(0x09, 0x00, CS1_GPIO_Port, CS1_Pin);         //  no decoding
	spi_send(0x0a, 0x01, CS1_GPIO_Port, CS1_Pin);         //  brightness intensity
	spi_send(0x0b, 0x07, CS1_GPIO_Port, CS1_Pin);         //  scan limit = 8 LEDs
	spi_send(0x0c, 0x01, CS1_GPIO_Port, CS1_Pin);         //  power down =0，normal mode = 1
	spi_send(0x0f, 0x00, CS1_GPIO_Port, CS1_Pin);         //  no test display

	spi_send(0x09, 0x00, CS2_GPIO_Port, CS2_Pin);         //  no decoding
	spi_send(0x0a, 0x01, CS2_GPIO_Port, CS2_Pin);         //  brightness intensity
	spi_send(0x0b, 0x07, CS2_GPIO_Port, CS2_Pin);         //  scan limit = 8 LEDs
	spi_send(0x0c, 0x01, CS2_GPIO_Port, CS2_Pin);         //  power down =0，normal mode = 1
	spi_send(0x0f, 0x00, CS2_GPIO_Port, CS2_Pin);         //  no test display

	spi_send(0x09, 0x00, CS3_GPIO_Port, CS3_Pin);         //  no decoding
	spi_send(0x0a, 0x01, CS3_GPIO_Port, CS3_Pin);         //  brightness intensity
	spi_send(0x0b, 0x07, CS3_GPIO_Port, CS3_Pin);         //  scan limit = 8 LEDs
	spi_send(0x0c, 0x01, CS3_GPIO_Port, CS3_Pin);         //  power down =0，normal mode = 1
	spi_send(0x0f, 0x00, CS3_GPIO_Port, CS3_Pin);         //  no test display

	spi_send(0x09, 0x00, CS4_GPIO_Port, CS4_Pin);         //  no decoding
	spi_send(0x0a, 0x01, CS4_GPIO_Port, CS4_Pin);         //  brightness intensity
	spi_send(0x0b, 0x07, CS4_GPIO_Port, CS4_Pin);         //  scan limit = 8 LEDs
	spi_send(0x0c, 0x01, CS4_GPIO_Port, CS4_Pin);         //  power down =0，normal mode = 1
	spi_send(0x0f, 0x00, CS4_GPIO_Port, CS4_Pin);         //  no test display
}

void matrix_send(uint8_t MATRIX[8], GPIO_TypeDef* PORT, uint16_t PIN)
{
	for (uint8_t i=0;i<8;i++)
	{
	spi_send(i+1, MATRIX[i],PORT,PIN);
	}

}

void matrix_send_all(void)
{
	matrix_send(matrix_player1_friendly_a, CS1_GPIO_Port, CS1_Pin);
	matrix_send(matrix_player2_friendly_a, CS2_GPIO_Port, CS2_Pin);
	matrix_send(matrix_player1_enemy_a, CS3_GPIO_Port, CS3_Pin);
	matrix_send(matrix_player2_enemy_a, CS4_GPIO_Port, CS4_Pin);
	HAL_Delay(300);
	matrix_send(matrix_player1_friendly_b, CS1_GPIO_Port, CS1_Pin);
	matrix_send(matrix_player2_friendly_b, CS2_GPIO_Port, CS2_Pin);
	matrix_send(matrix_player1_enemy_b, CS3_GPIO_Port, CS3_Pin);
	matrix_send(matrix_player2_enemy_b, CS4_GPIO_Port, CS4_Pin);
	HAL_Delay(300);
}

void matrix_LED_hit(void)
{

}

void matrix_LED_miss(void)
{

}
