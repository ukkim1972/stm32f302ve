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
#ifndef __SYS_TIMEUTIL_H
#define __SYS_TIMEUTIL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

void sys_10usec_timer(void);
void testbug_IO(void);

void sys_10usec_set(void);
void sys_10usec_clr(void);
uint32_t sys_10usec_get(void);

//add ysh

void sys_10usec_set_sonic(void);
void sys_clr_sonic_flag(uint8_t sonic_flag);
void sys_10usec_timer_sonic(void);
uint32_t sys_get_sonic(uint8_t sonic_flag);
void sys_all_set_sonic();
void sys_ALL_clr_sonic_timer();
void sys_start_upcount_timer_sonic();
void ON_upcount_timer(uint8_t sonic_flag);
void OFF_upcount_timer(uint8_t sonic_flag);


//end  ysh

#ifdef __cplusplus
}
#endif

#endif /* __SYS_TIMEUTIL_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
