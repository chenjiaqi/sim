#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "sim.h"
#include "virtual_flash.h"
int main(void) {

  virtual_flash_t cfg;
  cfg.erase_size = 4096;
  cfg.page_size = 4096;
  cfg.num_of_pages = 512;
  cfg.program_unit = 1;
  strncpy(cfg.flash_path, "./flash", sizeof(cfg.flash_path));

  virtual_flash_init(&cfg);

  uint8_t buf[100];
  virtual_flash_read(&cfg, 0, buf, sizeof(buf));
  for(int i = 0; i < sizeof(buf); i++) {
    printf("%02x ", buf[i]);
  }
  return 0;
}