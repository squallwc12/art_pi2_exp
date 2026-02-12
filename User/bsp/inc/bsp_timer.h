/**
  ******************************************************************************
  * @file    bsp_timer.h
  * @brief   This file contains all the function prototypes for the BSP timer
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BSP_TIMER_H
#define __BSP_TIMER_H

#ifdef USER_APPLI

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
void bsp_timer_start_tim1(void);
void bsp_timer_config_cycle_ms_tim1(uint32_t period_ms);

/* Private defines -----------------------------------------------------------*/
/*
 * Macros to select the timer instance for periodic cycle configuration and start.
 * Here, we use TIM1 as an example. You can change TIM1 to any other timer instance
 * as needed by defining corresponding functions.
 */
#define bsp_timer_start(X)		bsp_timer_start_tim##X()

/*
 * Macro to configure the timer for periodic cycle in milliseconds.
 * X: Timer instance number (e.g., 1 for TIM1)
 * Y: Period in milliseconds
 */
#define bsp_timer_config_cycle_ms(X,Y)	bsp_timer_config_cycle_ms_tim##X(Y)

#endif	/* USER_APPLI */

#endif /*__BSP_TIMER_H */



