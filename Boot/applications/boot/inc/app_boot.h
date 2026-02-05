/**
  ******************************************************************************
  * @file    app_boot.h
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
#ifndef __APP_BOOT_H
#define __APP_BOOT_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"

/* Private includes ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
int app_boot_jump_to(uint32_t DestAddress);

/* Private defines -----------------------------------------------------------*/
#define APPLICATION_ADDRESS   (uint32_t)0x70000000  //XSPI2_BASE

#ifdef __cplusplus
}
#endif
#endif /*__APP_BOOT_H */



