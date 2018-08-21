#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "sim.h"
int main(void) {
  printf("hello world\n");
  sim_t * sim = sim_allocate();
  if(!sim) {
    printf("sim allocate error");
  }
  sim->ops->init(sim, NULL);
  return 0;
}