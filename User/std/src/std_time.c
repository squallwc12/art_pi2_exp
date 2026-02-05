/**
  ******************************************************************************
  * @file           : std_time.c
  * @brief          : Board Support Package
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 Chadwick.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
#include "std_time.h"
#include "stm32h7rsxx_hal.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

/**
 * \brief           standard timer tick
 * \param[in]       None
 * \param[in]       None
 * \return          tick
 */
uint32_t std_gettick(void) {
#ifdef STM32H7RSxx_HAL_H
	return	HAL_GetTick();
#else
	return 0;
#endif
}
