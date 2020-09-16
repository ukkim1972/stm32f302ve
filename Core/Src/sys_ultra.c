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

#define SYS_UT0_ON()    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_SET)
#define SYS_UT0_OFF()   HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_RESET)
#define ARRAY_SIZE        10
#define alpha             0.9

uint32_t pre_dist=0;
uint32_t arr_dist[ARRAY_SIZE]={0,};
float LPF_DATA = 0;
float EX_LPF_DATA= 0; 

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
        HAL_NVIC_DisableIRQ(EXTI9_5_IRQn);

        SYS_UT0_ON();
        delay_us(75);
        SYS_UT0_OFF();

        utra_check_time();
        HAL_NVIC_EnableIRQ(EXTI4_IRQn);
        HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

    }
}

uint32_t ditance()
{
    return sys_10usec_get()*17;
}

uint32_t LPF()
{
  LPF_DATA = (alpha * (EX_LPF_DATA) +((1- alpha) * ditance()));
  EX_LPF_DATA = LPF_DATA;
  return (uint32_t)LPF_DATA;
}

uint32_t Moving_avreage_Filter()
{
  static uint8_t filter_count=0;
  uint32_t sum_data;
  uint32_t average_data;
  
  if(filter_count>=ARRAY_SIZE)
  {
    filter_count = 0;// 
  }
  else
  {
    filter_count++;
  }
   arr_dist[filter_count]= ditance();
  for(char i=0;i<ARRAY_SIZE;i++ )
  {
    sum_data +=arr_dist[filter_count];
  }
  average_data = sum_data/ARRAY_SIZE;
  
   return  average_data;
}


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  switch(GPIO_Pin)
  {
    case GPIO_PIN_4: //front sonic
      printf("F : dist %d ==> (%d)\r\n",sys_10usec_get(),sys_10usec_get()*17 );
      HAL_NVIC_DisableIRQ(EXTI4_IRQn);
      break;      
        
    case GPIO_PIN_5:
      printf("5 : dist %d ==> (%d)\r\n",sys_10usec_get(),sys_10usec_get()*17 );
      HAL_NVIC_DisableIRQ(EXTI9_5_IRQn);
      break;      
      
    case GPIO_PIN_6:
      printf("RIGHT : dist %d ==> (%d)\r\n",sys_10usec_get(),sys_10usec_get()*17 );
      HAL_NVIC_DisableIRQ(EXTI9_5_IRQn);
      break;      
      
    case GPIO_PIN_7:
      printf("7 : dist %d ==> (%d)\r\n",sys_10usec_get(),sys_10usec_get()*17 );
      HAL_NVIC_DisableIRQ(EXTI9_5_IRQn);
      break;      

  }
}