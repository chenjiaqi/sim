#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "sim.h"
#include "virtual_flash.h"
int main(void) {

  virtual_flash_t flash;
  flash.erase_size = 4096;
  flash.page_size = 4096;
  flash.num_of_pages = 512;
  flash.program_unit = 4;
  strncpy(flash.flash_path, "./flash", sizeof(flash.flash_path));

  virtual_flash_init(&flash);

  uint8_t buf[100];
  virtual_flash_read(&flash, 0, buf, sizeof(buf));
  for(int i = 0; i < sizeof(buf); i++) {
    printf("%02x ", buf[i]);
  }
  printf("\n");

  virtual_flash_erase(&flash, 0x00, 1);

  for(int i = 0; i < sizeof(buf); i++) {
    buf[i] = i;
  }
  virtual_flash_write(&flash, 0x00, buf, sizeof(buf));
  return 0;
}