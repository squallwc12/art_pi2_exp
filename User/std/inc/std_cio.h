/**
  ******************************************************************************
  * @file    std_cio.h
  * @brief   This file contains all the function prototypes for
  *          the std_cio.c file
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
#ifndef __STD_CIO_H
#define __STD_CIO_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/* Define --------------------------------------------------------------------*/
/* Configuration */
#define STD_CIO_PRINT			1	/*!< 使能标准printf  */
#define STD_LWPRINT				0	/*!< 使能lwprintf   */

/* Print Color Definition */
#define PR_COLOR_GREEN       "\033[0;32m"
#define PR_COLOR_RED         "\033[0;31m"
#define PR_COLOR_YELLOW      "\033[0;33m"
#define PR_COLOR_BLUE        "\033[0;34m"
#define PR_COLOR_DEFAULT     "\033[0m"

/**
 * stand printf
 *
 */
#if STD_CIO_PRINT
    /* Includes */
    #include <stdio.h>
    /* Print_Debug */
    #define stdio_printf(format, ...) \
      do { \
        printf(format, ##__VA_ARGS__); \
        fflush(stdout); \
      } while(0)
    /* Conditional Print */
    #ifdef stdio_printf
    #define std_printf(format, ...)		stdio_printf(format, ##__VA_ARGS__)
    #else
    #define std_printf(format, ...)		__NOP()
    #endif

    #define PRINT_LOG
    #ifdef PRINT_LOG
    #define LOG_I(format, ...) 	stdio_printf(PR_COLOR_GREEN format PR_COLOR_DEFAULT "\r\n", ##__VA_ARGS__)
    #define LOG_D(format, ...) 	stdio_printf(PR_COLOR_BLUE format PR_COLOR_DEFAULT "\r\n", ##__VA_ARGS__)
    #define LOG_E(format, ...) 	stdio_printf(PR_COLOR_RED format PR_COLOR_DEFAULT "\r\n", ##__VA_ARGS__)
    #endif

#endif /* STD_CIO_PRINT */

/**
 * lwprintf
 *
 */
#if STD_LWPRINT
    /* Includes */
    #include "std_time.h"
    #include "lwprintf/lwprintf.h"
    /* Print_Debug */
    #define sys_printf(format, ...)		        lwprintf_printf(format, ##__VA_ARGS__)
    #define sys_snprintf(s, n, format, ...)   lwprintf_snprintf(s, n, format, ##__VA_ARGS__)
    #define sys_vsnprintf(s, n, format, arg)  lwprintf_vsnprintf(s, n, format, arg)
    /* Conditional Print */
    #ifdef sys_printf
    #define debug_printf(format, ...) 	sys_printf("[%u]: " format, std_gettick(), ##__VA_ARGS__)
    #define warn_printf(format, ...)    sys_printf("\033[33;22m[WARN] [%u]: " format "\033[0m", std_gettick(), ##__VA_ARGS__)
    #define error_printf(format, ...) 	sys_printf("\033[31;22m[ERROR] [%u]: " format "\033[0m", std_gettick(), ##__VA_ARGS__)
    #define info_printf(format, ...)    sys_printf("\033[32;22m[INFO] [%u]: " format "\033[0m", std_gettick(), ##__VA_ARGS__)

    /* Print Color Definition */
    #define PRINT_COLOR_DEFAULT   "0;22"
    #define PRINT_COLOR_BLUE      "34;22"
    #define PRINT_COLOR_RED       "31;22"
    #define PRINT_COLOR_GREEN     "32;22"
    #define PRINT_COLOR_YELLOW    "33;22"

    #define color_printf(color, format, ...)  sys_printf("\033[%sm" format "\033[0m", color, ##__VA_ARGS__)

    #define USER_FORMAT_PRINT
    #ifdef USER_FORMAT_PRINT

    #define USER_FORMAT_CURSOR_SAVE     "\033[s"
    #define USER_FORMAT_CURSOR_RESTORE  "\033[u"

    /* Byte buffer hex line print macro */
    #define byte_hex_line_printf(tag, fmt, buf, len, line_i) \
          do { \
            uint8_t *ptr; \
            uint32_t i; \
            sys_printf(USER_FORMAT_CURSOR_SAVE); \
            for (ptr = buf, i = 0; i < len; ptr++, i++) { \
              if ((i % line_i == 0) && (i != 0)) { \
                sys_printf("\r\n" tag); \
                sys_printf(USER_FORMAT_CURSOR_RESTORE); \
              } \
              sys_printf(fmt, *ptr); \
            } \
            sys_printf("\r\n"); \
          }while(0)

    #endif

    #endif
#endif /* STD_LWPRINT */

/* Function prototypes ------------------------------------------------------*/
void std_cio_init(void);
void std_cio_output(const char* buf, uint32_t len);

#ifdef __cplusplus
}
#endif
#endif /* __STD_CIO_H */
