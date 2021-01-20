#include "main.h"
#include "keypad.h"




uint8_t check_button(void)
{
	//keypad 1
		HAL_GPIO_WritePin(keypad1_GPIO_Port, keypad1_Pin, GPIO_PIN_RESET);

		if ((HAL_GPIO_ReadPin (C11_GPIO_Port, C11_Pin))==0)   // if the Col 1 is low
			{
				return 1;
			}

			if ((HAL_GPIO_ReadPin (C12_GPIO_Port, C12_Pin))==0)   // if the Col 2 is low
			{
				return 2;
			}

			if ((HAL_GPIO_ReadPin (C13_GPIO_Port, C13_Pin))==0)   // if the Col 3 is low
			{
				return 3;
			}
			if ((HAL_GPIO_ReadPin (C14_GPIO_Port, C14_Pin))==0)   // if the Col 3 is low
			{
				return 4;
			}

		HAL_GPIO_WritePin(keypad2_GPIO_Port, keypad2_Pin, GPIO_PIN_RESET);

		    if ((HAL_GPIO_ReadPin (C21_GPIO_Port, C21_Pin))==0)   // if the Col 1 is low
			{

				return 1;
			}

			if ((HAL_GPIO_ReadPin (C22_GPIO_Port, C22_Pin))==0)   // if the Col 2 is low
			{

				return 2;
			}
			if ((HAL_GPIO_ReadPin (C23_GPIO_Port, C23_Pin))==0)   // if the Col 3 is low

			{

				return 3;
			}
			if ((HAL_GPIO_ReadPin (C24_GPIO_Port, C24_Pin))==0)   // if the Col 3 is low

			{

				return 4;
			}

			else return 0;
}




