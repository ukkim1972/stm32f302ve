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

// #define HAL_PC09_ON()  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_RESET)
// #define HAL_PC09_OFF()  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET)

// #define HAL_PC12_ON()  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, GPIO_PIN_RESET)
// #define HAL_PC12_OFF()  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, GPIO_PIN_SET)

// #define HAL_LED0_ON()  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_2, GPIO_PIN_RESET)
// #define HAL_LED0_OFF()  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_2, GPIO_PIN_SET)

// #define HAL_LED1_ON()  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET)
// #define HAL_LED1_OFF()  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET)


// uint8_t U4_Rxbuff[10];
// /* USER CODE BEGIN 1 */
// void Com1_RxInt_Enable(void){
//  	// HAL_UART_Receive_IT(&huart1, (uint8_t *)U4_tBuff, 2);
//     HAL_UART_Receive_DMA(&huart4, (uint8_t *)U4_Rxbuff, 1);
// 	//printf("com1");
// }

// void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){

//   if(huart->Instance == UART4){
// 	// osSemaphoreRelease(hUart2RxHandle);
// 	// Com2_Rx_Con();	// osSemaphoreRelease(hUart2RxHandle);
//     printf("Hello world ~~ !!");
//   }
//   // if(huart->Instance == USART2){
// 	// osSemaphoreRelease(hUart2RxHandle);
// 	// // Com2_Rx_Con();	// osSemaphoreRelease(hUart2RxHandle);
//   // }
//   // if(huart->Instance == USART1){
// 	// osSemaphoreRelease(hUart1RxHandle);
// 	// //	Com1_Rx_Con();
//   // }
//   // if(huart->Instance == USART6){
// 	// osSemaphoreRelease(hUart6RxHandle);
// 	// // Com6_Rx_Con();
//   // }
// }
void delay_us(int nDelay)
{
  while(nDelay--);
}
// int fputc(int ch,FILE *f)
// {
//   uint8_t temp[1]= {ch};
//   HAL_UART_Transmit(&huart1,temp,1,2);
//   return (ch);
// }


short timercnt;
void timer_int(void)
{
  if(timercnt++>999)
  {
    timercnt=0;
    // printf("1sec timer~~ !! \r\n");
  }
}
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
