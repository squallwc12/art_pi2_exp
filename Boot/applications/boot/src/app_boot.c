/**
  ******************************************************************************
  * @file           : app_boot.c
  * @brief          : application boot file
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
#include "app_boot.h"

/* Private includes ----------------------------------------------------------*/
#include "std_cio.h"
#include "stm32h7rsxx_hal.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

/**
  * @brief  Jumps to application code located at the specified address.
  * @param  DestAddress: The starting address of the application to jump to.
  * @retval int: Returns 0 on success.
  */
int app_boot_jump_to(uint32_t DestAddress)
{
    typedef void (*pFunction)(void);
    pFunction JumpToApp;
    uint32_t  Application_vector;

    /* Suspend SysTick */
    SysTick->CTRL = 0;

    /* Disable I-Cache---------------------------------------------------------*/
    SCB_DisableICache();  //TODO SCB_Disables Cache and jump success

    /* Disable D-Cache---------------------------------------------------------*/
    SCB_DisableDCache();

    /* Apply offsets for image location and vector table offset */
    //  Application_vector += EXTMEM_XIP_IMAGE_OFFSET + EXTMEM_HEADER_OFFSET;
    Application_vector = DestAddress;
    SCB->VTOR = (uint32_t)Application_vector;
    JumpToApp = (pFunction)(*(__IO uint32_t *)(Application_vector + 4u));

    __set_MSP(*(__IO uint32_t *)Application_vector);
    __set_CONTROL(0);

    __DSB();
    __ISB();

    JumpToApp();
    return 0;
}

