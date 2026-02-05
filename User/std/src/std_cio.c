/**
  ******************************************************************************
  * @file           : std_cio.c
  * @brief          : Board Support Package
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
#include "usart.h"

/* Private includes ----------------------------------------------------------*/
#include "std_cio.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
#define STD_CIO_UART_HANDLE huart4

#ifdef USER_BOOT
#define PAON_LOGO \
   "\033[32m""\r\n" \
   " _________________"   "  " "\r\n" \
   "/     *** ***     "   "\\ ""\r\n" \
   "|   ** \\* */ **   "  "| " "\r\n" \
   "|**  \\*\\* */*/  **" "| " "\r\n" \
   "|  \\* \\*.V.*/ */  " "| " "\r\n" \
   "|    \\*\\/ \\/*/    ""| " "\r\n" \
   "|       \\_/       "  "| " "\r\n" \
   "\\_________________"  "/ " "\r\n"

#define PAON_VERSION "v0.2.0"
#endif

#ifdef USER_APPLI
#define PAON_LOGO \
   "\033[32m""\r\n" \
   " _________________"   "  " " _________ _________ _________ _________ \r\n" \
   "/     *** ***     "   "\\ ""|   ___   |   ___   |   ___   |   ___   |\r\n" \
   "|   ** \\* */ **   "  "| " "|  |   |  |  |   |  |  |   |  |  |   |  |\r\n" \
   "|**  \\*\\* */*/  **" "| " "|  |___|  |  |___|  |  |___|  |  |   |  |\r\n" \
   "|  \\* \\*.V.*/ */  " "| " "|   ______|_____/|__|_________|__|   |__|\r\n" \
   "|    \\*\\/ \\/*/    ""| " "|  |\r\n" \
   "|       \\_/       "  "| " "|  |\r\n" \
   "\\_________________"  "/ " "|__|\033[0m\r\n"

#define PAON_VERSION "v1.0.0"
#endif

/* Private macro -------------------------------------------------------------*/
#ifdef USER_BOOT
const char *paon_logo    = PAON_LOGO;
const char *paon_version = "Paon Bootloader : " PAON_VERSION "\r\n";
const char *paon_date    = "Build Date      : " __DATE__ " " __TIME__ "\r\n";
const char *paon_creator = "Created by      : Chadwick" "\r\n";
#endif

#ifdef USER_APPLI
const char *paon_logo    = PAON_LOGO;
const char *paon_version = "Paon Application: " PAON_VERSION "\r\n";
const char *paon_date    = "Build Date      : " __DATE__ " " __TIME__ "\r\n";
const char *paon_creator = "Created by      : Chadwick" "\r\n";
#endif

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
#if STD_LWPRINT
static int lwprintf_my_out_func(int ch, lwprintf_t* p);
#endif

/* Private user code ---------------------------------------------------------*/

#if STD_CIO_PRINT
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif

PUTCHAR_PROTOTYPE
{
	HAL_UART_Transmit(&STD_CIO_UART_HANDLE, (uint8_t*) &ch, 1, 100);
	return ch;
}
#endif

/**
 * @brief           standard Input/Output init
 * @param[in]       None
 * @param[in]       None
 * @return          None
 */
void std_cio_init(void)
{
#if STD_LWPRINT
	lwprintf_init( lwprintf_my_out_func );
	lwprintf_printf(paon_logo);
	lwprintf_printf(paon_version);
	lwprintf_printf(paon_date);
	lwprintf_printf(paon_creator);
	lwprintf_printf("\r\n" "Initializing LwPrintf..." "\r\n");
#endif

#if STD_CIO_PRINT
	std_printf(paon_logo);
	std_printf(paon_version);
	std_printf(paon_date);
	std_printf(paon_creator);
#endif
}

/**
 * @brief           Standard C I/O output function
 * @param[in]       buf: Buffer pointer
 * @param[in]       len: Buffer length
 * @return          None
 */
void std_cio_output(const char* buf, uint32_t len)
{
  HAL_UART_Transmit(&STD_CIO_UART_HANDLE, (const uint8_t*)buf, len, (len * 10));
}

#if STD_LWPRINT
/**
 * @brief           Output function to handle all characters for print operation
 * @param[in]       ch: Character to output
 * @param[in]       p: \ref lwprintf_t handle
 * @return          ch on success, 0 on failure
 */
static int lwprintf_my_out_func(int ch, lwprintf_t* p)
{
    uint8_t c = (uint8_t)ch;

    /* Don't print zero */
    if (c == '\0') {
        return ch;
    }
    HAL_UART_Transmit(&STD_CIO_UART_HANDLE, &c, 1, 100);
    return ch;
}
#endif
