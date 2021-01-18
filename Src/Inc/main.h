/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define C14_Pin GPIO_PIN_13
#define C14_GPIO_Port GPIOC
#define C21_Pin GPIO_PIN_0
#define C21_GPIO_Port GPIOC
#define C22_Pin GPIO_PIN_1
#define C22_GPIO_Port GPIOC
#define C23_Pin GPIO_PIN_2
#define C23_GPIO_Port GPIOC
#define C24_Pin GPIO_PIN_3
#define C24_GPIO_Port GPIOC
#define CS4_Pin GPIO_PIN_14
#define CS4_GPIO_Port GPIOB
#define CS2_Pin GPIO_PIN_6
#define CS2_GPIO_Port GPIOC
#define CS1_Pin GPIO_PIN_7
#define CS1_GPIO_Port GPIOC
#define CS3_Pin GPIO_PIN_8
#define CS3_GPIO_Port GPIOC
#define C11_Pin GPIO_PIN_10
#define C11_GPIO_Port GPIOA
#define C12_Pin GPIO_PIN_11
#define C12_GPIO_Port GPIOA
#define C13_Pin GPIO_PIN_12
#define C13_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define keypad2_Pin GPIO_PIN_10
#define keypad2_GPIO_Port GPIOC
#define keypad1_Pin GPIO_PIN_11
#define keypad1_GPIO_Port GPIOC
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
