/**
  ******************************************************************************
  * File Name          : sys_timerutil.c
  * Description        : This file provides code for the configuration
  *                      of the USB instances.
  * name : kim un ki
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
#include "sys_timerutil.h"

uint32_t usectimer;
uint8_t usectimer_flag;


void testbug_IO(void)
{
    if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_12) == GPIO_PIN_RESET)
    {
        HAL_PC12_OFF();
    }
    else{
        HAL_PC12_ON();
    }
}


void sys_10usec_set(void)
{
    usectimer_flag=1;
    usectimer=0;
}

void sys_10usec_clr(void)
{
    usectimer_flag=0;
}

uint32_t sys_10usec_get(void)
{
    sys_10usec_clr();
    return usectimer;
}

void sys_10usec_timer(void)
{
    // 10 usec time
    if(usectimer_flag) usectimer++;
}


