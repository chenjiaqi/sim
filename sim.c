#include "sim.h"

sim_t * sim_allocate(void) {
  return (sim_t *) malloc(sizeof(sim_t));
}