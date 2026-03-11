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
#include "std_cio.h"
#include "bsp_exception.h"
#include "bsp_flash.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

/**
  * @brief FLASH Initialization Function
  * @param None
  * @retval None
  */
void bsp_flash_OB_init(void)
{
    FLASH_OBProgramInitTypeDef pOBInit = {0};

    if (HAL_FLASH_Unlock() != HAL_OK) {
        BSP_EXCEP_HANDLER();
    }

    if (HAL_FLASH_OB_Unlock() != HAL_OK) {
        BSP_EXCEP_HANDLER();
    }

    pOBInit.OptionType = OPTIONBYTE_USER;
    pOBInit.USERType = OB_USER_IWDG_SW | OB_USER_NRST_STOP
                       | OB_USER_NRST_STDBY | OB_USER_VDDIO_HSLV
                       | OB_USER_IWDG_STOP | OB_USER_IWDG_STDBY
                       | OB_USER_XSPI1_HSLV | OB_USER_XSPI2_HSLV
                       | OB_USER_I2C_NI3C;
    pOBInit.USERConfig1 = OB_IWDG_SW | OB_STOP_NORST
                          | OB_STANDBY_NORST | OB_VDDIO_HSLV_DISABLE
                          | OB_IWDG_STOP_RUN | OB_IWDG_STDBY_RUN
                          | OB_XSPI1_HSLV_ENABLE | OB_XSPI2_HSLV_ENABLE;
    pOBInit.USERConfig2 = OB_I2C_NI3C_I2C;

    if (HAL_FLASHEx_OBProgram(&pOBInit) != HAL_OK) {
        BSP_EXCEP_HANDLER();
    }

    if (HAL_FLASH_OB_Lock() != HAL_OK) {
        BSP_EXCEP_HANDLER();
    }

    if (HAL_FLASH_Lock() != HAL_OK) {
        BSP_EXCEP_HANDLER();
    }

}
