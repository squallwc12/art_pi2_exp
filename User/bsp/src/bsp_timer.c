/**
  ******************************************************************************
  * @file           : bsp_timer.c
  * @brief          : broad support package for timer
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 Jousing.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
#ifdef USER_APPLI
/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
#include "tim.h"
#include "std_cio.h"
#include "bsp_exception.h"
#include "bsp_timer.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

/*
 * @brief 	Start the timer in interrupt mode for periodic cycle.
 * @param 	None
 * @return 	None
 */
void bsp_timer_start_tim1(void)
{
  if (HAL_TIM_Base_Start_IT(&htim1) != HAL_OK) {
	  BSP_EXCEP_HANDLER();
  }
}

/*
 * @brief 	Configure the timer for periodic cycle in milliseconds.
 * @param 	period_ms: period in milliseconds
 * @return 	None
 */
void bsp_timer_config_cycle_ms_tim1(uint32_t period_ms)
{
  uint32_t timer_clock = HAL_RCC_GetPCLK2Freq(); // TIM1 is on APB2
  uint32_t prescaler = (timer_clock / 1000) - 1; // Prescale to 1 kHz (1 ms tick)
  uint32_t period = period_ms - 1;               // Set the period for desired ms

  HAL_TIM_Base_Stop_IT(&htim1); // Stop timer before reconfiguring

  __HAL_TIM_SET_PRESCALER(&htim1, prescaler);
  __HAL_TIM_SET_AUTORELOAD(&htim1, period);
  __HAL_TIM_SET_COUNTER(&htim1, 0);              // Reset counter
}

#endif	/* USER_APPLI */
