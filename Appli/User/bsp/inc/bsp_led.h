/**
  ******************************************************************************
  * @file    bsp_led.h
  * @brief   This file contains all the function prototypes for the BSP timer
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
#ifndef __BSP_LED_H
#define __BSP_LED_H


#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
/* Enum to represent the different LEDs. You can add more LEDs as needed.
 */
typedef enum {
	led_blue,
	led_red,
} led_t;

/* Enum to represent the state of the LED (on or off). */
typedef enum {
	led_off = 0,
	led_on = 1,
} led_state_t;

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
void bsp_led_init(void);
void bsp_led_set_state(led_t led, led_state_t state);

/* Private defines -----------------------------------------------------------*/
/* Macros to control the LEDs. These macros call the bsp_led_set_state
 * function with the appropriate parameters.
 * You can add more macros for additional LEDs as needed.
 */
#define bsp_led_blue_on()		bsp_led_set_state(led_blue, led_on)
#define bsp_led_blue_off()		bsp_led_set_state(led_blue, led_off)
#define bsp_led_red_on()		bsp_led_set_state(led_red, led_on)
#define bsp_led_red_off()		bsp_led_set_state(led_red, led_off)

#endif /*__BSP_LED_H */



