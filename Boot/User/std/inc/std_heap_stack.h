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
#ifndef __STD_HEAP_STACK_H
#define __STD_HEAP_STACK_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <inttypes.h>

/* Private includes ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
//
typedef struct {
    uintptr_t heap_start;   // Start address of the heap
    uintptr_t heap_end;     // End address of the heap
    uintptr_t stack_start;  // Start address of the stack
    uintptr_t stack_end;    // End address of the stack

    size_t    heap_size;    // Size of the heap in bytes
    size_t    stack_size;   // Size of the stack in bytes
} std_heap_stack_info_t;

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
void std_heap_stack_get_info(std_heap_stack_info_t *pInfo);
void std_heap_stack_info(void);

/* Private defines -----------------------------------------------------------*/

#ifdef __cplusplus
}
#endif
#endif /*__STD_HEAP_STACK_H*/



