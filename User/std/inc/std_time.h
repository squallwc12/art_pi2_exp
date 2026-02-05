/**
  ******************************************************************************
  * @file    std_time.h
  * @brief   This file contains all the function prototypes for
  *          the std_time.c file
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
#ifndef __STD_TIME_H__
#define __STD_TIME_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"
/* Define --------------------------------------------------------------------*/

/* Function ------------------------------------------------------------------*/
uint32_t std_gettick(void);

#ifdef __cplusplus
}
#endif
#endif /*__STD_TIME_H__ */



