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
#include "sys_ultra.h"
// #define HAL_PC09_ON()  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_RESET)
// #define HAL_PC09_OFF()  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET)

#define SYS_UT0_ON()    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_SET)
#define SYS_UT0_OFF()   HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_RESET)

void delay_us(uint16_t delayus)
{
    while(delayus--);
}

void utra_check_time(void)
{
    sys_10usec_set();
}

uint8_t ultra_tx0_flag;
void ultra_tx(void)
{
    if(ultra_tx0_flag==0)
    {
        HAL_NVIC_DisableIRQ(EXTI4_IRQn);

        SYS_UT0_ON();
        delay_us(75); // 10usec 
        SYS_UT0_OFF();

        utra_check_time();
        HAL_NVIC_EnableIRQ(EXTI4_IRQn);
    }
}



void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if(GPIO_Pin == GPIO_PIN_4){

    // printf("dist %d ==> (%d)\r\n",sys_10usec_get(),sys_10usec_get()*17 );
    //  printf("dist %d ==> (%d)\r\n",sys_10usec_get(),sys_10usec_get()*17 );    
    HAL_NVIC_DisableIRQ(EXTI4_IRQn);
    }
}