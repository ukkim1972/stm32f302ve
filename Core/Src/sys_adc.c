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
extern ADC_HandleTypeDef hadc1;
uint16_t Adc_Data[14];
uint32_t Adc_Volt[14];

void sys_Adc_channel_Select(uint8_t nSel)
{
	ADC_ChannelConfTypeDef sConfig;
	//HAL_ADC_Stop(&hadc1);
	sConfig.Rank = 1;
	switch(nSel)
	{

		case 0: sConfig.Channel = ADC_CHANNEL_4;	  	sConfig.Rank = 1;	break;
		case 1: sConfig.Channel = ADC_CHANNEL_5;	  	sConfig.Rank = 1;	break;
		case 2: sConfig.Channel = ADC_CHANNEL_6;		sConfig.Rank = 1;	break;
		case 3: sConfig.Channel = ADC_CHANNEL_10;		sConfig.Rank = 1;	break;
		case 4: sConfig.Channel = ADC_CHANNEL_11;		sConfig.Rank = 1;	break;
		case 5: sConfig.Channel = ADC_CHANNEL_12;		sConfig.Rank = 1;	break;
		case 6: sConfig.Channel = ADC_CHANNEL_13;		sConfig.Rank = 1;	break;
		case 7: sConfig.Channel = ADC_CHANNEL_14;		sConfig.Rank = 1;	break;
		case 8: sConfig.Channel = ADC_CHANNEL_15;		sConfig.Rank = 1;	break;

		case 9: sConfig.Channel = ADC_CHANNEL_16;	  	sConfig.Rank = 1;	break;
		case 10: sConfig.Channel = ADC_CHANNEL_VREFINT;	sConfig.Rank = 1;	break;
		case 11: sConfig.Channel = ADC_CHANNEL_4;	sConfig.Rank = 1;	break;
  }
    sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
    if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK){
	    printf("err");
    }
}

uint8_t adc_select_no;
uint8_t Adc_Read_flag;

void Adc_Read_Program(void)
{
  sys_Adc_channel_Select(adc_select_no);
  HAL_ADC_Start(&hadc1);

  if(HAL_ADC_PollForConversion(&hadc1,500) == HAL_OK){
    	if( (HAL_ADC_GetState(&hadc1)&HAL_ADC_STATE_REG_EOC) == HAL_ADC_STATE_REG_EOC){
			Adc_Data[adc_select_no] = HAL_ADC_GetValue(&hadc1);
			Adc_Volt[adc_select_no] =((uint32_t)( (805 * Adc_Data[adc_select_no])/10000));
			Adc_Read_flag=0;
			// Adc_Select_No++;

      printf("adc: %d , volt : %d \r\n",Adc_Data[adc_select_no] ,Adc_Volt[adc_select_no]);
		}
  }
}