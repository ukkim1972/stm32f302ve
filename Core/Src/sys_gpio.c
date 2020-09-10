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
#include "sys_gpio.h"


// void delay_us(int nDelay)
// {
//   while(nDelay--);
// }


uint32_t timercnt;
uint32_t timergroup[10];


uint8_t Timer_CheckFlag;
void checkTimer(void)
{
  if(Timer_CheckFlag==0)
  {
    sys_10usec_set();
    Timer_CheckFlag=1;
  }
  else{
    Timer_CheckFlag=0;
    // sys_10usec_clr();
    printf(" %d ms \r\n",sys_10usec_get()/100);

  }
}

void timer_Loop(void)
{
  // 10ms
  if(timergroup[0]>9)
  {
    // HAL_LED1_Toggle();
    // checkTimer();
    timergroup[0]=0;
  }

  // 50ms
  if(timergroup[1]>299)
  {
    HAL_LED1_Toggle();

    ultra_tx();

    timergroup[1]=0;
  }  

  // 1000ms
  if(timergroup[2]>999)
  {
    // checkTimer();
    timergroup[2]=0;
  }    
}

void timer_int(void)
{
  if(timercnt++>999)
  {
    timercnt=0;
  }
  for(int i=0; i<10;i++)
  {
    timergroup[i] +=1;
  }
  timer_Loop();
}
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
