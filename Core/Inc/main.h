/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "stm32f4xx_hal.h"

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
#define MCU_IN0_Pin GPIO_PIN_2
#define MCU_IN0_GPIO_Port GPIOE
#define MCU_IN1_Pin GPIO_PIN_3
#define MCU_IN1_GPIO_Port GPIOE
#define MCU_IN2_Pin GPIO_PIN_4
#define MCU_IN2_GPIO_Port GPIOE
#define MCU_IN3_Pin GPIO_PIN_5
#define MCU_IN3_GPIO_Port GPIOE
#define MCU_IN4_Pin GPIO_PIN_6
#define MCU_IN4_GPIO_Port GPIOE
#define MCU_IN5_Pin GPIO_PIN_13
#define MCU_IN5_GPIO_Port GPIOC
#define MCU_IN6_Pin GPIO_PIN_14
#define MCU_IN6_GPIO_Port GPIOC
#define MCU_IN7_Pin GPIO_PIN_15
#define MCU_IN7_GPIO_Port GPIOC
#define MCU_IN8_Pin GPIO_PIN_0
#define MCU_IN8_GPIO_Port GPIOF
#define MCU_IN9_Pin GPIO_PIN_1
#define MCU_IN9_GPIO_Port GPIOF
#define MCU_IN10_Pin GPIO_PIN_2
#define MCU_IN10_GPIO_Port GPIOF
#define MCU_IN11_Pin GPIO_PIN_3
#define MCU_IN11_GPIO_Port GPIOF
#define MCU_IN12_Pin GPIO_PIN_4
#define MCU_IN12_GPIO_Port GPIOF
#define MCU_IN13_Pin GPIO_PIN_5
#define MCU_IN13_GPIO_Port GPIOF
#define MCU_IN14_Pin GPIO_PIN_6
#define MCU_IN14_GPIO_Port GPIOF
#define MCU_IN15_Pin GPIO_PIN_7
#define MCU_IN15_GPIO_Port GPIOF
#define VCC_OUT_0_Pin GPIO_PIN_12
#define VCC_OUT_0_GPIO_Port GPIOB
#define GND_OUT_0_Pin GPIO_PIN_13
#define GND_OUT_0_GPIO_Port GPIOB
#define VCC_OUT_1_Pin GPIO_PIN_14
#define VCC_OUT_1_GPIO_Port GPIOB
#define GND_OUT_1_Pin GPIO_PIN_15
#define GND_OUT_1_GPIO_Port GPIOB
#define VCC_OUT_2_Pin GPIO_PIN_8
#define VCC_OUT_2_GPIO_Port GPIOD
#define GND_OUT_2_Pin GPIO_PIN_9
#define GND_OUT_2_GPIO_Port GPIOD
#define VCC_OUT_3_Pin GPIO_PIN_10
#define VCC_OUT_3_GPIO_Port GPIOD
#define GND_OUT_3_Pin GPIO_PIN_11
#define GND_OUT_3_GPIO_Port GPIOD
#define VCC_OUT_4_Pin GPIO_PIN_12
#define VCC_OUT_4_GPIO_Port GPIOD
#define GND_OUT_4_Pin GPIO_PIN_13
#define GND_OUT_4_GPIO_Port GPIOD
#define VCC_OUT_5_Pin GPIO_PIN_14
#define VCC_OUT_5_GPIO_Port GPIOD
#define GND_OUT_5_Pin GPIO_PIN_15
#define GND_OUT_5_GPIO_Port GPIOD
#define VCC_OUT_6_Pin GPIO_PIN_2
#define VCC_OUT_6_GPIO_Port GPIOG
#define GND_OUT_6_Pin GPIO_PIN_3
#define GND_OUT_6_GPIO_Port GPIOG
#define VCC_OUT_7_Pin GPIO_PIN_4
#define VCC_OUT_7_GPIO_Port GPIOG
#define GND_OUT_7_Pin GPIO_PIN_5
#define GND_OUT_7_GPIO_Port GPIOG
#define VCC_OUT_8_Pin GPIO_PIN_6
#define VCC_OUT_8_GPIO_Port GPIOG
#define GND_OUT_8_Pin GPIO_PIN_7
#define GND_OUT_8_GPIO_Port GPIOG
#define VCC_OUT_9_Pin GPIO_PIN_15
#define VCC_OUT_9_GPIO_Port GPIOA
#define GND_OUT_9_Pin GPIO_PIN_10
#define GND_OUT_9_GPIO_Port GPIOC
#define VCC_OUT_10_Pin GPIO_PIN_11
#define VCC_OUT_10_GPIO_Port GPIOC
#define GND_OUT_10_Pin GPIO_PIN_12
#define GND_OUT_10_GPIO_Port GPIOC
#define VCC_OUT_11_Pin GPIO_PIN_0
#define VCC_OUT_11_GPIO_Port GPIOD
#define GND_OUT_11_Pin GPIO_PIN_1
#define GND_OUT_11_GPIO_Port GPIOD
#define VCC_OUT_12_Pin GPIO_PIN_2
#define VCC_OUT_12_GPIO_Port GPIOD
#define GND_OUT_12_Pin GPIO_PIN_3
#define GND_OUT_12_GPIO_Port GPIOD
#define VCC_OUT_13_Pin GPIO_PIN_4
#define VCC_OUT_13_GPIO_Port GPIOD
#define GND_OUT_13_Pin GPIO_PIN_5
#define GND_OUT_13_GPIO_Port GPIOD
#define VCC_OUT_14_Pin GPIO_PIN_6
#define VCC_OUT_14_GPIO_Port GPIOD
#define GND_OUT_14_Pin GPIO_PIN_7
#define GND_OUT_14_GPIO_Port GPIOD
#define VCC_OUT_15_Pin GPIO_PIN_9
#define VCC_OUT_15_GPIO_Port GPIOG
#define GND_OUT_15_Pin GPIO_PIN_10
#define GND_OUT_15_GPIO_Port GPIOG

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
