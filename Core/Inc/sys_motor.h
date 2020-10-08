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
#ifndef __SYS_MOTOR_H
#define __SYS_MOTOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
  
#define	Motor01_Forward	        GPIO_PIN_13
#define	Motor01_Backward	GPIO_PIN_6
#define	Motor03_Forward 	GPIO_PIN_2
#define	Motor03_Backward	GPIO_PIN_3
#define	Motor02_Open	        GPIO_PIN_14
#define	Motor02_Close	        GPIO_PIN_15
#define	Motor04_Left	        GPIO_PIN_4
#define	Motor04_Right	        GPIO_PIN_5
  
void case_motor(uint8_t ndirection);


#ifdef __cplusplus
}
#endif

#endif /* __SYS_MOTOR_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
