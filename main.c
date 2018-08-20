#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "sim.h"
int main(void) {
  printf("hello world\n");
  sim_t * sim = sim_allocate();
  return 0;
}
