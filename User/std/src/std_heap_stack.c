/**
  ******************************************************************************
  * @file           : std_heap_stack.c
  * @brief          : Standard Heap and Stack Management
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
#include "std_heap_stack.h"
#include "std_cio.h"

/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
// Symbols defined in the linker script
extern uint32_t _estack;
extern uint32_t _Min_Heap_Size;
extern uint32_t _Min_Stack_Size;

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

/**
  * @brief  Prints the start and end addresses along with sizes of the heap and stack.
  * @retval None
  */
void std_heap_stack_info(void)
{
    uintptr_t stack_start = (uintptr_t)(&_estack);
    uintptr_t heap_size   = (uintptr_t)(&_Min_Heap_Size);
    uintptr_t stack_size  = (uintptr_t)(&_Min_Stack_Size);

    uintptr_t stack_end   = stack_start - stack_size;
    uintptr_t heap_end    = stack_end;
    uintptr_t heap_start  = heap_end - heap_size;

    // Print Heap Information
    printf("Heap Start Address : 0x%08" PRIxPTR "\r\n", heap_start);
    printf("Heap End Address   : 0x%08" PRIxPTR "\r\n", heap_end);
    printf("Heap Size          : %" PRIuPTR " bytes\r\n", heap_size);

    // Print Stack Information
    printf("Stack Start Address: 0x%08" PRIxPTR "\r\n", stack_start);
    printf("Stack End Address  : 0x%08" PRIxPTR "\r\n", stack_end);
    printf("Stack Size         : %" PRIuPTR " bytes\r\n", stack_size);
}
