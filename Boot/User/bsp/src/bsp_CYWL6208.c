/**
  ******************************************************************************
  * @file           : bsp_CYWL6208.c
  * @brief          : broad support package for timer
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
#include "gpio.h"
#include "bsp_CYWL6208.h"
#include "std_cio.h"
#include "bsp_exception.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
/* CYWL6208 Bluetooth Module pins */
#define BT_WAKE_PIN 			GPIO_PIN_2
#define BT_WAKE_GPIO_PORT 		GPIOF
#define BT_HOST_WAKE_PIN 		GPIO_PIN_3
#define BT_HOST_WAKE_GPIO_PORT 	GPIOF
#define BT_RST_PIN 				GPIO_PIN_3
#define BT_RST_GPIO_PORT 		GPIOM
/* CYWL6208 Wireless Module pins */
#define WL_REG_ON_PIN 			GPIO_PIN_2
#define WL_REG_ON_GPIO_PORT 	GPIOM
#define WL_HOST_WAKE_PIN 		GPIO_PIN_5
#define WL_HOST_WAKE_GPIO_PORT 	GPIOC

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/
