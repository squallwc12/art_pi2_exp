/**
  ******************************************************************************
  * @file           : sd_card.c
  * @brief          : SD Card configuration code
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
#include "sdmmc.h"

/* Private includes ----------------------------------------------------------*/
#include "sd_card.h"
#include "std_cio.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
#define SD_TIMEOUT              ((uint32_t)0x00100000U) //等待时间
#define BLOCK_SIZE              512   //块的数目
#define NUMBER_OF_BLOCKS        50    //块的数据大小
#define MULTI_BUFFER_SIZE       (BLOCK_SIZE * NUMBER_OF_BLOCKS)

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
static HAL_StatusTypeDef sd_card_wait_ready(void);

/* Private user code ---------------------------------------------------------*/

void sd_card_erase_t(void)
{
    HAL_StatusTypeDef Status = HAL_OK;
    HAL_StatusTypeDef EraseStatus = HAL_OK;

    if (Status == HAL_OK) {
        Status = HAL_SD_Erase(&hsd1, 0x00, (BLOCK_SIZE * NUMBER_OF_BLOCKS));
        // wait until the SD card is ready
        if(sd_card_wait_ready() != HAL_OK) {
            EraseStatus = HAL_ERROR;
        }
    }

    if (EraseStatus == HAL_OK) {
      LOG_I("SD_Card Erase Test Succeeded!");
    }
    else {
      LOG_E("SD_Card Erase Test Failed!");
    }
}

void sd_card_single_block_t(void)
{
    int      SD_status;
    uint16_t sd_test_ii=0;

    uint8_t  Buffer_Block_Tx[512];
    uint8_t  Buffer_Block_Rx[512];

    for (sd_test_ii = 0; sd_test_ii < 512; sd_test_ii++) {
        Buffer_Block_Tx[sd_test_ii] = sd_test_ii % 216;
    }

    SD_status = HAL_SD_WriteBlocks(&hsd1, (uint8_t *)Buffer_Block_Tx, 0, 1, 0xfff);

    if (SD_status == HAL_OK) {
        LOG_I("SD_Card write Succeeded!");
    }

    for (sd_test_ii = 0; sd_test_ii < 512; sd_test_ii++) {
        Buffer_Block_Rx[sd_test_ii] = 0;
    }

    SD_status = HAL_SD_ReadBlocks(&hsd1, (uint8_t *)Buffer_Block_Rx, 0, 1, 0xfff);

    if (SD_status == HAL_OK) {
        LOG_I("SD_Card read Succeeded!");
    }
}

static HAL_StatusTypeDef sd_card_wait_ready(void)
{
    uint32_t loop = SD_TIMEOUT;

    while (loop > 0) {
        loop--;
        if(HAL_SD_GetCardState(&hsd1) == HAL_SD_CARD_TRANSFER) {
            return HAL_OK;
        }
    }
    return HAL_ERROR;
}

