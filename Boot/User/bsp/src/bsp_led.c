/**
  ******************************************************************************
  * @file           : bsp_led.c
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
#include "bsp_led.h"
#include "std_cio.h"
#include "bsp_exception.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
// Macros to define the GPIO pins and ports for the LEDs. Replace with actual values.
#define LED_BLUE_PIN GPIO_PIN_5
#define LED_BLUE_GPIO_PORT GPIOO
#define LED_RED_PIN GPIO_PIN_1
#define LED_RED_GPIO_PORT GPIOO

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

/**
  * @brief  Initialize the GPIO for LED control.
  * @retval None
  */
void bsp_led_init(void)
{
  /* Initialize the GPIO for LED control */
  // Assuming LED is connected to GPIO pin defined in gpio.h
  // You can replace GPIO_PIN_X and GPIO_PORT_Y with actual values
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* Enable the GPIO clock for the LED port */
  __HAL_RCC_GPIOO_CLK_ENABLE(); // Replace with actual port clock enable

  /* BLUE LED Low/drain active, REDLEDHigh active. */
  /* Set the LED off initially */
  HAL_GPIO_WritePin(GPIOO, GPIO_PIN_5, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOO, GPIO_PIN_1, GPIO_PIN_RESET);

  /* Configure the GPIO pin for LED as output */
  /* PO5 Blue LED */
  GPIO_InitStruct.Pin = LED_BLUE_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_BLUE_GPIO_PORT, &GPIO_InitStruct);

  /* PO1 Red LED */
  GPIO_InitStruct.Pin = LED_RED_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_RED_GPIO_PORT, &GPIO_InitStruct);
}

/**
  * @brief  Set the state of the specified LED.
  * @param  led: The LED to control (e.g., led_blue, led_red).
  * @param  state: The desired state of the LED (led_on or led_off).
  * @retval None
  */
void bsp_led_set_state(led_t led, led_state_t state)
{
  switch (led) {
	case led_blue:
	  HAL_GPIO_WritePin(LED_BLUE_GPIO_PORT, LED_BLUE_PIN, ((state == led_on) ? GPIO_PIN_RESET : GPIO_PIN_SET));
	  break;
	case led_red:
	  HAL_GPIO_WritePin(LED_RED_GPIO_PORT, LED_RED_PIN, ((state == led_on) ? GPIO_PIN_SET : GPIO_PIN_RESET));
	  break;
	default:
	  // Handle invalid LED selection if necessary
	  break;
  }
}
