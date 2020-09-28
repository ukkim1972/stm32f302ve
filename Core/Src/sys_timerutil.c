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

#define sonic_0 0
#define sonic_1 1
#define sonic_2 2
#define sonic_3 3


uint32_t usectimer;

uint32_t sonic_timer_0;
uint32_t sonic_timer_1;
uint32_t sonic_timer_2;
uint32_t sonic_timer_3;

uint8_t sonic_upcount_flag_0=0;
uint8_t sonic_upcount_flag_1=0;
uint8_t sonic_upcount_flag_2=0;
uint8_t sonic_upcount_flag_3=0;

uint8_t sonic_0_flag;
uint8_t sonic_1_flag;
uint8_t sonic_2_flag;
uint8_t sonic_3_flag;

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


void sys_all_set_sonic()
{
    usectimer_flag=1;
    sonic_0_flag=1;
    sonic_1_flag=1;
    sonic_2_flag=1;
    sonic_3_flag=1;

    sonic_timer_0=0;
    sonic_timer_1=0;
    sonic_timer_2=0;
    sonic_timer_3=0;
}



void sys_set_sonic1_flag(uint8_t sonic_flag)
{
  switch(sonic_flag)
  {
  case sonic_0 :
    sonic_0_flag=1;
    break;
 
  case sonic_1 :
    sonic_1_flag=1;
    break;
 
  case sonic_2 :
    sonic_2_flag=1;
    break;
  
  case sonic_3 :
    sonic_3_flag=1;    
    break;
    
  }
}

void sys_10usec_clr(void)
{
    usectimer_flag=0;
}

void sys_all_clr_sonic_flag()
{
   sonic_1_flag=0;
   sonic_2_flag=0;
   sonic_3_flag=0;
   sonic_0_flag=0;
}

void sys_clr_sonic_flag(uint8_t sonic_flag)
{
  switch(sonic_flag)
  {
  case sonic_0 :
    sonic_0_flag=0;
    break;
 
  case sonic_1 :
    sonic_1_flag=0;
    break;
 
  case sonic_2 :
    sonic_2_flag=0;
    break;
  
  case sonic_3 :
    sonic_3_flag=0;    
    break;
    
  }
}

uint32_t sys_10usec_get(void)
{
    // sys_10usec_clr();
    return usectimer;
}

uint32_t sys_get_sonic(uint8_t sonic_flag)
{
  if(sonic_flag == sonic_0)
    return sonic_timer_0;
  
  else if(sonic_flag == sonic_1)
    return sonic_timer_1;
  
  else if(sonic_flag == sonic_2)
    return sonic_timer_2;
  
  else if(sonic_flag ==sonic_3)
    return sonic_timer_3;
  
  else
  {
    printf("no connect sonic\r\n");
    sonic_flag = NULL;
  }
   
  return 0;
}

void sys_10usec_timer(void)
{
    // 10 usec time
    if(usectimer_flag) usectimer++;
}

void sys_10usec_timer_sonic()
{
    // 10 usec time 
      sonic_timer_0++;        
      sonic_timer_1++;  
      sonic_timer_2++;
      sonic_timer_3++;
}
void ON_upcount_timer(uint8_t sonic_flag)
{
  if(sonic_flag ==sonic_0)
    sonic_upcount_flag_0=1;
  
  else if(sonic_flag==sonic_1)
    sonic_upcount_flag_1=1;
  
  else if(sonic_flag == sonic_2)
   sonic_upcount_flag_2=1;
  
  else if(sonic_flag ==sonic_3)
    sonic_upcount_flag_3=1;
}

void OFF_upcount_timer(uint8_t sonic_flag)
{
  if(sonic_flag ==sonic_0)
    sonic_upcount_flag_0=0;
  
  else if(sonic_flag==sonic_1)
    sonic_upcount_flag_1=0;
  
  else if(sonic_flag == sonic_2)
   sonic_upcount_flag_2=0;
  
  else if(sonic_flag ==sonic_3)
    sonic_upcount_flag_3=0;
}


void sys_start_upcount_timer_sonic()
{
    // 10 usec time 
  if(sonic_upcount_flag_0)
      sonic_timer_0++;    
  
  if(sonic_upcount_flag_1)
      sonic_timer_1++;  

  if(sonic_upcount_flag_2)
      sonic_timer_2++;

  if(sonic_upcount_flag_3)
      sonic_timer_3++;
}



void sys_ALL_clr_sonic_timer()
{
      sonic_timer_0 =0;        
      sonic_timer_1 =0;  
      sonic_timer_2 =0;
      sonic_timer_3=0;
}

void sys_clr_sonic_timer(uint8_t sonic_flag)
{
   if(sonic_flag ==sonic_0)
      sonic_timer_0=0;
  
  else if(sonic_flag==sonic_1)
    sonic_timer_1=0;
  
  else if(sonic_flag == sonic_2)
   sonic_timer_2=0;
  
  else if(sonic_flag ==sonic_3)
    sonic_timer_3=0;
  
}



