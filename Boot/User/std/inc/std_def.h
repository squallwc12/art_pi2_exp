/**
  ******************************************************************************
  * @file    std_type.h
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
#ifndef __STD_DEF_H
#define __STD_DEF_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

/* Private includes ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
/**
 * @brief error type
 */
typedef enum {
  RESULT_OK = 0,    		/*!< error_t value indicating success (no error) */
  RESULT_FAIL = -1, 		/*!< Generic error_t code indicating failure */
  ERROR_INVALID_ARG = 1, 	/*!< Invalid argument */
  ERROR_IO = 2,				/*!< IO error */
}error_t;

/**
 * @brief array type
 */
typedef struct {
  struct{
    uint16_t u_num;			/*!< number of units */
    uint8_t  u_len;			/*!< units length */
    uint8_t  flag;
  }param;
  void	     *buf;			/*!< buffer */
  uint32_t   ext_data;/*!< extended data */
}array_t;

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/
#define BYTES_TO_U32_LE(b0, b1, b2, b3) \
    (((uint32_t)(b0) << 0)  | \
     ((uint32_t)(b1) << 8)  | \
     ((uint32_t)(b2) << 16) | \
     ((uint32_t)(b3) << 24))

#define BYTES_TO_U32_LE_ARRAY(arr) \
    (((uint32_t)((arr)[0]) << 0)  | \
     ((uint32_t)((arr)[1]) << 8)  | \
     ((uint32_t)((arr)[2]) << 16) | \
     ((uint32_t)((arr)[3]) << 24))

/* Exported functions prototypes ---------------------------------------------*/

/* Private defines -----------------------------------------------------------*/
// 包含操作参数的数组
#define array_init(NAME, NUM, TYPE, EXT_DATA) \
  static TYPE NAME##_buf[NUM]; \
  array_t NAME = { \
    .param.u_num = NUM, \
    .param.u_len = sizeof(TYPE), \
    .param.flag = 0, \
    .buf = NAME##_buf, \
    .ext_data = EXT_DATA, \
  }

#define array_ext_data(array)		((array)->ext_data)
#define array_buf(array)		    ((array)->buf)
#define array_total_len(array)	(uint32_t)((uint32_t)((array)->param.u_num) * (uint32_t)((array)->param.u_len))

// 强制在RAM中执行的宏
#define RAM_FUNC __attribute__((section(".RamFunc"))) __attribute__((noinline)) __attribute__((optimize("O0")))

#ifdef __cplusplus
}
#endif
#endif /*__STD_TYPE_H__ */



