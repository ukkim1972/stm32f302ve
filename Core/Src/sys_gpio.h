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
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SYS_GPIO_H
#define __SYS_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

#define HAL_PC09_ON()  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_RESET)
#define HAL_PC09_OFF()  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET)

#define HAL_PC12_ON()  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, GPIO_PIN_RESET)
#define HAL_PC12_OFF()  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, GPIO_PIN_SET)

#define HAL_LED0_ON()  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_2, GPIO_PIN_RESET)
#define HAL_LED0_OFF()  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_2, GPIO_PIN_SET)

#define HAL_LED1_ON()  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET)
#define HAL_LED1_OFF()  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET)

#define HAL_LED0_Toggle() HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_2)
#define HAL_LED1_Toggle() HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_10)


#define HAL_LED4_Toggle()  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9)
#define HAL_LED5_Toggle()  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_12)

#define HAL_LED2_Toggle()  HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_0)
#define HAL_LED3_Toggle()  HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_1)

// void delay_us(int nDelay);
void timer_int(void);

//add
void Run_Sonic_Flag();
void Stop_Sonic_Flag();
uint8_t Get_Sonic_Flag();

//end

#ifdef __cplusplus
}
#endif

#endif /* __SYS_GPIO_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
