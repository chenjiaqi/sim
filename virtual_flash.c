/**
 * @brief
 *
 * @file virtual_flash.c
 * @date 2019-05-06
 * @author ChenJiaqi
 * @copyright (c) 2016-2018 by Druid Technology Co., Ltd.  All Rights Reserved.
 */
#include "virtual_flash.h"
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
static bool is_flash_exist(const char *path) {
  assert(path);
  FILE *f = fopen(path, "rb");
  if(f) {
    fclose(f);
  }

  return f ? true : false;
}

static bool create_virtual_flash(const char *path, uint32_t total_size) {
  printf("create %s %d\n", path, total_size);
  assert(path);

  FILE *f = fopen(path, "wb");
  if(f) {
    uint8_t *buf = (uint8_t *)malloc(total_size);
    memset(buf, 0xff, total_size);
    fwrite(buf, total_size, 1, f);
    fclose(f);
    free(buf);
  }

  return true;
}

bool virtual_flash_init(const virtual_flash_t *flash) {
  assert(flash);
  const char * path = flash->flash_path;
  assert(path);
  bool exist = is_flash_exist(path);
  return exist ? true : create_virtual_flash(path, flash->page_size * flash->num_of_pages);
}

size_t virtual_flash_read(const virtual_flash_t *flash, size_t address, void *dest, size_t len) {
  assert(flash);
  const char *path = flash->flash_path;
  size_t read_len = 0;
  FILE *f = fopen(path, "r");
  if(f) {
    printf("%d\n",fseek(f, address, 0));
    read_len = fread(dest, len, 1, f);
  }
  return read_len;
}

size_t virtual_flash_erase(const virtual_flash_t *flash) {
  assert(flash);
  return 0;
}

size_t virtual_flash_write(const virtual_flash_t *flash) {
  assert(flash);
  return 0;
}