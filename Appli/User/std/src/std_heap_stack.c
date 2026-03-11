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

// Structure to hold heap and stack information
std_heap_stack_info_t   heap_stack_info = {0};

/* Private function prototypes -----------------------------------------------*/
static void std_heap_stack_init(void);

/* Private user code ---------------------------------------------------------*/

/**
  * @brief  Initializes the heap and stack information.
  *         This function calculates the start and end addresses of the heap and stack,
  *         as well as their sizes based on linker script symbols.
  * @retval None
  */
static void std_heap_stack_init(void)
{
    heap_stack_info.stack_start = (uintptr_t)(&_estack);
    heap_stack_info.heap_size   = (uintptr_t)(&_Min_Heap_Size);
    heap_stack_info.stack_size  = (uintptr_t)(&_Min_Stack_Size);
    heap_stack_info.stack_end   = heap_stack_info.stack_start - heap_stack_info.stack_size;
    heap_stack_info.heap_end    = heap_stack_info.stack_end;
    heap_stack_info.heap_start  = heap_stack_info.heap_end - heap_stack_info.heap_size;
}

/**
  * @brief  Retrieves the heap and stack information.
  *         This function initializes the heap and stack information if not already done,
  *         and fills the provided structure with the current heap and stack details.
  * @param  pInfo Pointer to a std_heap_stack_info_t structure to fill with information.
  * @retval None
  */
void std_heap_stack_get_info(std_heap_stack_info_t *pInfo)
{
    std_heap_stack_init();

    if (pInfo != NULL) {
        pInfo->heap_start  = heap_stack_info.heap_start;
        pInfo->heap_end    = heap_stack_info.heap_end;
        pInfo->stack_start = heap_stack_info.stack_start;
        pInfo->stack_end   = heap_stack_info.stack_end;
        pInfo->heap_size   = heap_stack_info.heap_size;
        pInfo->stack_size  = heap_stack_info.stack_size;
    }
}

/**
  * @brief  Prints the start and end addresses along with sizes of the heap and stack.
  * @retval None
  */
void std_heap_stack_info(void)
{
  /*
    uintptr_t stack_start = (uintptr_t)(&_estack);
    uintptr_t heap_size   = (uintptr_t)(&_Min_Heap_Size);
    uintptr_t stack_size  = (uintptr_t)(&_Min_Stack_Size);

    uintptr_t stack_end   = stack_start - stack_size;
    uintptr_t heap_end    = stack_end;
    uintptr_t heap_start  = heap_end - heap_size;
    */

    std_heap_stack_info_t heap_stack_t;

    std_heap_stack_get_info(&heap_stack_t);

    // Print Heap Information
    printf("Heap Start Address : 0x%08" PRIxPTR "\r\n",   heap_stack_t.heap_start);
    printf("Heap End Address   : 0x%08" PRIxPTR "\r\n",   heap_stack_t.heap_end);
    printf("Heap Size          : %" PRIuPTR " bytes\r\n", heap_stack_t.heap_size);

    // Print Stack Information
    printf("Stack Start Address: 0x%08" PRIxPTR "\r\n",   heap_stack_t.stack_start);
    printf("Stack End Address  : 0x%08" PRIxPTR "\r\n",   heap_stack_t.stack_end);
    printf("Stack Size         : %" PRIuPTR " bytes\r\n", heap_stack_t.stack_size);
}


