/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "spi.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "LCD.h"
#include "matrix.h"
#include "game.h"
#include "keypad.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */



/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI2_Init();
  MX_I2C3_Init();
  MX_I2C2_Init();
  /* USER CODE BEGIN 2 */

  LCD_init(lcd_1, &hi2c3);
  LCD_init(lcd_2, &hi2c3);
  LCD_clear(lcd_1);
  LCD_clear(lcd_2);
  LCD_set_cursor(lcd_1, 0, 0);
  LCD_set_cursor(lcd_2, 0,0);
  LCD_display(lcd_1, "LCD1DDD");
  LCD_display(lcd_2, "LCD2CCC");

  matrices_init();
  matrix_player1_friendly_a[0] = 0b00000001;
  matrix_player1_friendly_b [1] = 0b00000001;
  matrix_player1_enemy_a [2] = 0b00000001;
  matrix_player1_enemy_b [2] = 0b00000001;
  matrix_player2_friendly_a [3] = 0b00000001;
  matrix_player2_friendly_b [3] = 0b00000001;
  matrix_player2_enemy_a [3] = 0b00000001;
  matrix_player2_enemy_b [2] = 0b00000001;

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  matrix_send_all();

	  switch (check_button())
	  {
	  case 1:
		  matrix_player1_friendly_a[0] = 0b11111111;
		  matrix_player1_friendly_b[1] = 0b11111111;
		  break;
	  case 2:
	 		  matrix_player1_enemy_a[0] = 0b11111111;
	 		  matrix_player1_enemy_b[1] = 0b11111111;
	 		  break;
	  case 3:
	 		  matrix_player2_friendly_a[0] = 0b11111111;
	 		  matrix_player2_friendly_b[1] = 0b11111111;
	 		  break;
	  case 4:
	 		  matrix_player2_enemy_a[0] = 0b11111111;
	 		  matrix_player2_enemy_b[1] = 0b11111111;
	 		  break;
	  case 5:
	  		  matrix_player1_friendly_a[2] = 0b11111111;
	  		  matrix_player1_friendly_b[3] = 0b11111111;
	  		  break;
	  case 6:
	  	 	matrix_player1_enemy_a[2] = 0b11111111;
	  	 	matrix_player1_enemy_b[3] = 0b11111111;
	  	 	break;
	  case 7:
	  	 	matrix_player2_friendly_a[2] = 0b11111111;
	  	 	matrix_player2_friendly_b[3] = 0b11111111;
	  	 	break;
	  case 8:
	  	 	matrix_player2_enemy_a[2] = 0b11111111;
	  	 	matrix_player2_enemy_b[3] = 0b11111111;
	  	 	break;

	  case 10:
	  		matrix_player1_friendly_a[4] = 0b11111111;
	  		matrix_player1_friendly_b[5] = 0b11111111;
	  		break;
	 case 11:
	  		 matrix_player1_enemy_a[4] = 0b11111111;
	  		 matrix_player1_enemy_b[5] = 0b11111111;
	  		 break;
	 case 12:
	  		matrix_player2_friendly_a[4] = 0b11111111;
	  		matrix_player2_friendly_b[5] = 0b11111111;
	  		break;
	case 13:
	  		matrix_player2_enemy_a[4] = 0b11111111;
	  		matrix_player2_enemy_b[5] = 0b11111111;
	  		break;
	case 14:
	  		matrix_player1_friendly_a[6] = 0b11111111;
	  		matrix_player1_friendly_b[7] = 0b11111111;
	  		break;
	case 15:
	  		matrix_player1_enemy_a[6] = 0b11111111;
	  		matrix_player1_enemy_b[7] = 0b11111111;
	  		break;
	case 16:
	  		matrix_player2_friendly_a[6] = 0b11111111;
	  		matrix_player2_friendly_b[7] = 0b11111111;
	  		break;
	case 17:
	  		matrix_player2_enemy_a[6] = 0b11111111;
	  		matrix_player2_enemy_b[7] = 0b11111111;
	  		break;
	  default:
		  break;
	  };
	  HAL_Delay(200);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  };
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_I2C2|RCC_PERIPHCLK_I2C3;
  PeriphClkInit.I2c2ClockSelection = RCC_I2C2CLKSOURCE_HSI;
  PeriphClkInit.I2c3ClockSelection = RCC_I2C3CLKSOURCE_HSI;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
