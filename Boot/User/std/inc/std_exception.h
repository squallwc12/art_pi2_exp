/**
  ******************************************************************************
  * @file    std_exception.h
  * @brief   This file contains all the function prototypes for
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
#ifndef __STD_EXCEPTION_H
#define __STD_EXCEPTION_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/

/* Private defines -----------------------------------------------------------*/
#define _std_exception_try(c, tag) \
  do{ if(!(c)){ goto tag; } }while(0)

#define _std_exception_throw(tag, param) \
  do{ goto tag; }while(0)

#define _std_exception_catch(tag) \
  tag:

#ifdef __cplusplus
}
#endif
#endif /*__STD_TYPE_H__ */



