/**
  ******************************************************************************
  * @file    bsp_exception.h
  * @brief   broad support package for exception handler
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BSP_EXCEPTIONIO_H
#define __BSP_EXCEPTIONIO_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/* Define --------------------------------------------------------------------*/

/* Typedef -------------------------------------------------------------------*/
/* BSP standard int32 type */
typedef enum {
    bsp_ok    =  0,
    bsp_error = -1,
}bsp_int32_t;

/* Function prototypes -------------------------------------------------------*/
void bsp_exception_handler(const char *_func_, int _line_, int _level_);

/* Macros --------------------------------------------------------------------*/
/** @defgroup bsp_exception_handler_macro BSP Exception Handler Macro
  * @{
  */
#define BSP_EXCEP_HANDLER()   bsp_exception_handler(__func__, __LINE__, 0)

/**
  * @}
  */

#ifdef __cplusplus
}
#endif
#endif /* __STD_CIO_H */
