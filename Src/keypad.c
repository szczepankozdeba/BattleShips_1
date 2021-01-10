#include "main.h"
#include "keypad.h"


uint8_t check_button(void)
{
	//keypad 1
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET);
		HAL_Delay(10);
		if ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_5))==0)   // if the Col 1 is low
			{
				while ((!HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_5)));   // wait till the button is pressed
				return 1;
			}

			if ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_6))==0)   // if the Col 2 is low
			{
				while ((!HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_6)));   // wait till the button is pressed
				return 2;
			}

			if ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_7))==0)   // if the Col 3 is low
			{
				while ((!HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_7)));   // wait till the button is pressed
				return 3;
			}
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET);
		HAL_Delay(10);
		if ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_5))==0)   // if the Col 1 is low
					{
						while ((!HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_5)));   // wait till the button is pressed
						return 4;
					}

					if ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_6))==0)   // if the Col 2 is low
					{
						while ((!HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_6)));   // wait till the button is pressed
						return 5;
					}

					if ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_7))==0)   // if the Col 3 is low
					{
						while ((!HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_7)));   // wait till the button is pressed
						return 6;
					}
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_RESET);
		HAL_Delay(10);
		if ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_5))==0)   // if the Col 1 is low
					{
						while (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_5)));   // wait till the button is pressed
						return 7;
					}

					if ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_6))==0)   // if the Col 2 is low
					{
						while (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_6)));   // wait till the button is pressed
						return 8;
					}

					if ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_7))==0)   // if the Col 3 is low
					{
						while (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_7)));   // wait till the button is pressed
						return 9;
					}
	//keypad 2
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_SET);
		HAL_Delay(10);
		if ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_10))==0)   // if the Col 1 is low
			{
				while (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_10)));   // wait till the button is pressed
				return 10;
			}

			if ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_11))==0)   // if the Col 2 is low
			{
				while (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_11)));   // wait till the button is pressed
				return 11;
			}

			if ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_12))==0)   // if the Col 3 is low
			{
				while (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_12)));   // wait till the button is pressed
				return 12;
			}
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_SET);
		HAL_Delay(10);
		if ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_10))==0)   // if the Col 1 is low
			{
				while (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_10)));   // wait till the button is pressed
				return 13;
			}

			if ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_11))==0)   // if the Col 2 is low
			{
				while (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_11)));   // wait till the button is pressed
				return 14;
			}

			if ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_12))==0)   // if the Col 3 is low
			{
				while (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_12)));   // wait till the button is pressed
				return 15;
			}
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_RESET);
		HAL_Delay(10);
		if ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_10))==0)   // if the Col 1 is low
			{
				while (!(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_10)));   // wait till the button is pressed
				return 16;
			}

			if ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_11))==0)   // if the Col 2 is low
			{
				while ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_11)));   // wait till the button is pressed
				return 17;
			}

			if ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_12))==0)   // if the Col 3 is low
			{
				while ((HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_12)));   // wait till the button is pressed
				return 18;
			}

			else
			{
				return 0;
			}
};




uint8_t check_button_pressed(void)
{
//keypad 1
if(__HAL_GPIO_EXTI_GET_FLAG(GPIO_PIN_5))
	{
	switch (check_col(1,GPIOA, GPIO_PIN_5))
	{
	case 1:
		return 1;
	break;

	case 2:
		return 2;
	break;

	case 3:
		return 3;
	break;
	default:
		return 0;
	};
	};
if(__HAL_GPIO_EXTI_GET_FLAG(GPIO_PIN_6))
	{
	switch (check_col(1,GPIOA, GPIO_PIN_6))
	{
		case 1:
			return 4;
		break;

		case 2:
			return 5;
		break;

		case 3:
			return 6;
		break;
		default:
			return 0;
		};
	};
if(__HAL_GPIO_EXTI_GET_FLAG(GPIO_PIN_7))
	{
	switch (check_col(1,GPIOA, GPIO_PIN_7))
	{
		case 1:
			return 7;
		break;

		case 2:
			return 8;
		break;

		case 3:
			return 9;
		break;
		default:
			return 0;
	};
};
//keypad 2
if(__HAL_GPIO_EXTI_GET_FLAG(GPIO_PIN_10))
	{
	switch (check_col(2,GPIOA, GPIO_PIN_10))
		{
		case 1:
			return 10;
		break;

		case 2:
			return 11;
		break;

		case 3:
			return 12;
		break;
		default:
			return 0;
	};
	};
if(__HAL_GPIO_EXTI_GET_FLAG(GPIO_PIN_11))
	{
	switch (check_col(2,GPIOA, GPIO_PIN_11))
		{
		case 1:
			return 13;
		break;

		case 2:
			return 14;
		break;

		case 3:
			return 15;
		break;
		default:
			return 0;
	};
	};
if(__HAL_GPIO_EXTI_GET_FLAG(GPIO_PIN_12))
	{
	switch (check_col(2,GPIOA, GPIO_PIN_12))
		{
		case 1:
			return 16;
		break;

		case 2:
			return 17;
		break;

		case 3:
			return 18;
		break;
		default:
			return 0;
	};
};
};


