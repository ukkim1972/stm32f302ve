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

#define SYS_UT0_ALL_ON()    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_SET)
#define SYS_UT0_ALL_OFF()   HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_RESET)

#define SYS_UT0_ON()    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_SET)
#define SYS_UT0_OFF()   HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_RESET)
#define SYS_UT1_ON()    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, GPIO_PIN_SET)
#define SYS_UT1_OFF()   HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, GPIO_PIN_RESET)
#define SYS_UT2_ON()    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_SET)
#define SYS_UT2_OFF()   HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_RESET)
#define SYS_UT3_ON()    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_SET)
#define SYS_UT3_OFF()   HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_RESET)

#define sonic_0 0
#define sonic_1 1
#define sonic_2 2
#define sonic_3 3
    
#define ARRAY_SIZE        10
#define alpha             0.9

uint32_t pre_dist=0;
uint32_t arr_dist[ARRAY_SIZE]={0,};
float LPF_DATA = 0;
float EX_LPF_DATA= 0; 

uint8_t sonic_flag =0;
uint8_t sonic_IT_flag = 0;
uint32_t sonic_data[4] ={0,} ;
uint8_t sonic_trig_flag=0;

uint8_t Echo_Bool_0 = 0;
uint8_t Echo_Bool_1 = 0;
uint8_t Echo_Bool_2 = 0;
uint8_t Echo_Bool_3 = 0;




void delay_us(uint16_t delayus)
{
    while(delayus--);
}

void utra_check_time(void)
{
    sys_10usec_set();
    sys_all_set_sonic();
}


uint8_t ultra_tx0_flag;
void ultra_tx(void)
{
    if(ultra_tx0_flag==0)
    {
        sys_10usec_clr();
        sys_all_clr_sonic_flag();
    //    HAL_NVIC_DisableIRQ(EXTI4_IRQn);
     //   HAL_NVIC_DisableIRQ(EXTI9_5_IRQn);

        SYS_UT0_ALL_ON();
        delay_us(75);
        SYS_UT0_ALL_OFF();

        //utra_check_time();
       // sys_all_set_sonic();
       // HAL_NVIC_EnableIRQ(EXTI4_IRQn);
       // HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

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

void get_sonic_data(uint8_t sonic_number)
{
  sonic_data[sonic_number] = sys_get_sonic(sonic_number);
  //sys_clr_sonic_flag(sonic_number);
  sys_clr_sonic_timer(sonic_number);
}
void Start_Sonic()
{
        //sys_ALL_clr_sonic_timer();
        SYS_UT0_ALL_ON();
        delay_us(75);
        SYS_UT0_ALL_OFF();
        Logic_Sonic();
}


void Sonic_Trig_0()
{
  SYS_UT0_ON();
  delay_us(75);
  SYS_UT0_OFF();
}
void Sonic_Trig_1()
{
  SYS_UT1_ON();
  delay_us(75);
  SYS_UT1_OFF();
}
void Sonic_Trig_2()
{
  SYS_UT2_ON();
  delay_us(75);
  SYS_UT2_OFF();
}
void Sonic_Trig_3()
{
  SYS_UT3_ON();
  delay_us(75);
  SYS_UT3_OFF();
}


void Logic_Sonic()
{ 
   switch(sonic_trig_flag)
   {
     case sonic_0:
          sonic_trig_flag++;
   //  printf("tr : %d\r\n",sonic_trig_flag);
     Sonic_Trig_0();
     break;
     
      case sonic_1:
           sonic_trig_flag++;
   //  printf("tr : %d\r\n",sonic_trig_flag);
     Sonic_Trig_1();
     break;
     
   case sonic_2:
        sonic_trig_flag++;
   //  printf("tr : %d\r\n",sonic_trig_flag);
     Sonic_Trig_2();
     break;
          
   case sonic_3:
   //  printf("tr : %d\r\n",sonic_trig_flag);
     Sonic_Trig_3();
   //   print_sonic();
     sonic_trig_flag=0;
     //printf(" %d %d %d %d\r\n",sonic_data[0],sonic_data[1], sonic_data[2], sonic_data[3] );
     break;
     
   default : 
     // printf("sonic : error\r\n");
     break;
   }
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

  switch(GPIO_Pin)
  {
    case GPIO_PIN_4: //front sonic1
      Echo_Bool_0++;
      if(Echo_Bool_0==1)
      {
        sonic_data[0]=0;
        ON_upcount_timer(sonic_0);
      }
      if(Echo_Bool_0==2)
      {
        Echo_Bool_0=0;
        sonic_data[0]=sys_get_sonic(sonic_0);
       printf("F : %d \r\n",sonic_data[0]);

       OFF_upcount_timer(sonic_0);
        sys_clr_sonic_timer(sonic_0);
      } 
      
      break;      
        
    case GPIO_PIN_5:
      Echo_Bool_1++;
      if(Echo_Bool_1==1)
      {
        sonic_data[1]=0;
        ON_upcount_timer(sonic_1);
      }
      if(Echo_Bool_1>=2)
      {
        Echo_Bool_1=0;
        sonic_data[1]=sys_get_sonic(sonic_1);
       printf("R: %d \r\n",sonic_data[1]);
        OFF_upcount_timer(sonic_1);
        sys_clr_sonic_timer(sonic_1);
      }
      break;      
      
    case GPIO_PIN_6:
      Echo_Bool_2++;
      
      if(Echo_Bool_2==1)
      {
        sonic_data[2]=0;
        ON_upcount_timer(sonic_2);
      }
      if(Echo_Bool_2>=2)
      {
        Echo_Bool_2=0;
        sonic_data[2]=sys_get_sonic(sonic_2);
     //  printf("l : %d \r\n",sonic_data[2]);
        OFF_upcount_timer(sonic_2);
        sys_clr_sonic_timer(sonic_2);
      break;      
      
    case GPIO_PIN_7:
      Echo_Bool_3++;
      
      if(Echo_Bool_3==1)
      {
        sonic_data[3]=0;
        ON_upcount_timer(sonic_3);
      }
      if(Echo_Bool_3>=2)
      {
        Echo_Bool_3=0;
        sonic_data[3]=sys_get_sonic(sonic_3);
      printf("b : %d \r\n",sonic_data[3]);
        OFF_upcount_timer(sonic_3);
        sys_clr_sonic_timer(sonic_3);
      break;   
      
      }
     }
  }
}



void print_sonic()
{
  printf(" %4d %d %4d %4d\r\n ",sonic_data[0],sonic_data[1],sonic_data[2],sonic_data[3]);
}