/**
  ******************************************************************************
  * File Name          : USB.c
  * Description        : This file provides code for the configuration
  *                      of the USB instances.
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

/* Includes ------------------------------------------------------------------*/
#include "sys_adc.h"
#include "sys_motor.h"

#define HAL_MOTOR1_ON()  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, GPIO_PIN_SET)
#define HAL_MOTOR1_OFF()  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, GPIO_PIN_RESET)

#define HAL_MOTOR2_ON()  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, GPIO_PIN_SET)
#define HAL_MOTOR2_OFF()  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, GPIO_PIN_RESET)

void case_stop(void)
{
    HAL_MOTOR1_OFF();
    HAL_MOTOR2_OFF(); 
}

void case_motor(uint8_t ndirection)
{
    switch (ndirection)
    {
    case 'f':
        case_stop();
        HAL_MOTOR1_ON();
        HAL_MOTOR2_OFF();        
        break;
    case 'b':
        case_stop();    
        HAL_MOTOR1_OFF();
        HAL_MOTOR2_ON();        
        break;    
    case 's':
        case_stop();
        break;            
    default:
        break;
    }
}

void motordrv()
{

}