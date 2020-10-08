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
#ifndef __SYS_ULTRA_H
#define __SYS_ULTRA_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

void ultra_tx(void);

/**start add ysh**/
uint32_t ditance(void);
void UT_1_4_ON(void);
void print_sonic();
void sys_all_clr_sonic_flag();
void sys_clr_sonic_timer(uint8_t sonic_flag);
void get_sonic_data(uint8_t sonic_number);
void Start_Sonic();
void Logic_Sonic();
void Sonic_Trig_0();
void Sonic_Trig_1();
void Sonic_Trig_2();
void Sonic_Trig_3();
/**end ysh**/




#ifdef __cplusplus
}
#endif

#endif /* __SYS_GPIO_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
