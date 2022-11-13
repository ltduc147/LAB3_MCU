/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32f1xx_hal.h"

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
#define SELECT_Pin GPIO_PIN_2
#define SELECT_GPIO_Port GPIOA
#define INC_Pin GPIO_PIN_3
#define INC_GPIO_Port GPIOA
#define SET_Pin GPIO_PIN_4
#define SET_GPIO_Port GPIOA
#define R_a_Pin GPIO_PIN_6
#define R_a_GPIO_Port GPIOA
#define G_a_Pin GPIO_PIN_7
#define G_a_GPIO_Port GPIOA
#define led0_a_Pin GPIO_PIN_0
#define led0_a_GPIO_Port GPIOB
#define led1_a_Pin GPIO_PIN_1
#define led1_a_GPIO_Port GPIOB
#define led2_a_Pin GPIO_PIN_2
#define led2_a_GPIO_Port GPIOB
#define led2_b_Pin GPIO_PIN_10
#define led2_b_GPIO_Port GPIOB
#define led3_b_Pin GPIO_PIN_11
#define led3_b_GPIO_Port GPIOB
#define led4_b_Pin GPIO_PIN_12
#define led4_b_GPIO_Port GPIOB
#define led5_b_Pin GPIO_PIN_13
#define led5_b_GPIO_Port GPIOB
#define led6_b_Pin GPIO_PIN_14
#define led6_b_GPIO_Port GPIOB
#define Y_a_Pin GPIO_PIN_8
#define Y_a_GPIO_Port GPIOA
#define R_b_Pin GPIO_PIN_9
#define R_b_GPIO_Port GPIOA
#define G_b_Pin GPIO_PIN_10
#define G_b_GPIO_Port GPIOA
#define Y_b_Pin GPIO_PIN_11
#define Y_b_GPIO_Port GPIOA
#define EN0_a_Pin GPIO_PIN_12
#define EN0_a_GPIO_Port GPIOA
#define EN1_a_Pin GPIO_PIN_13
#define EN1_a_GPIO_Port GPIOA
#define EN0_b_Pin GPIO_PIN_14
#define EN0_b_GPIO_Port GPIOA
#define EN1_b_Pin GPIO_PIN_15
#define EN1_b_GPIO_Port GPIOA
#define led3_a_Pin GPIO_PIN_3
#define led3_a_GPIO_Port GPIOB
#define led4_a_Pin GPIO_PIN_4
#define led4_a_GPIO_Port GPIOB
#define led5_a_Pin GPIO_PIN_5
#define led5_a_GPIO_Port GPIOB
#define led6_a_Pin GPIO_PIN_6
#define led6_a_GPIO_Port GPIOB
#define led0_b_Pin GPIO_PIN_8
#define led0_b_GPIO_Port GPIOB
#define led1_b_Pin GPIO_PIN_9
#define led1_b_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
