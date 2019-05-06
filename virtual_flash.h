/**
 * @brief
 *
 * @file virtual_flash.h
 * @date 2019-05-06
 * @author ChenJiaqi
 * @copyright (c) 2016-2018 by Druid Technology Co., Ltd.  All Rights Reserved.
 */
#ifndef __VIRTUAL_FLASH_H__
#define __VIRTUAL_FLASH_H__
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

struct virtual_flash_s {
  uint32_t page_size;
  uint32_t num_of_pages;
  uint32_t program_unit;
  uint32_t erase_size;
  char flash_path[60];
};

typedef struct virtual_flash_s virtual_flash_t;

bool virtual_flash_init(const virtual_flash_t *flash);

size_t virtual_flash_read(const virtual_flash_t *flash, size_t address, void *dest, size_t len);
size_t virtual_flash_erase(const virtual_flash_t *flash);
size_t virtual_flash_write(const virtual_flash_t *flash);
#endif