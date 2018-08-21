#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "sim.h"
int main(void) {
  printf("hello world\n");
  sim_cfg_t cfg = {
    .page_size = 2048,
    .spare_size = 64,
    .block_num = 1024,
    .pages_per_block = 64,
  };
  sim_t * sim = sim_allocate();
  if(!sim) {
    printf("sim allocate error");
  }
  sim->ops->init(sim, &cfg);
  sim->ops->erase(sim, 0);
  return 0;
}