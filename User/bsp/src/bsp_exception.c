/**
  ******************************************************************************
  * @file           : bsp_flash.c
  * @brief          : broad support package for flash memory
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
/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
#include "stm32h7rsxx_hal.h"
#include "std_exception.h"
#include "std_cio.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

/**
  * @brief  BSP Exception Handler
  * @param  _func_: Function name
  * @param  _line_: Line number
  * @param  _level_: Exception level
  * @retval None
  */
void bsp_exception_handler(const char *_func_, int _line_, int _level_)
{

}
