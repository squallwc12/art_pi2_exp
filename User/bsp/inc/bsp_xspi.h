/**
  ******************************************************************************
  * @file    bsp_xspi.h
  * @brief   broad support package for xspi memory
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
#ifndef __BSP_XSPI_H
#define __BSP_XSPI_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/* Define --------------------------------------------------------------------*/

/* Function prototypes -------------------------------------------------------*/
// Initialize XSPI memories
void bsp_xspi_memory_init(void);
// Flash memory
void bsp_xspi_memory_mapped(void);

/* Macros --------------------------------------------------------------------*/
/** @defgroup bsp_flash_macro BSP Flash Macro
  * @{
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif
#endif /* __BSP_XSPI_H */
