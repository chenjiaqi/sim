#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct sim_ops;

typedef struct sim_cfg {
  uint32_t page_size;
  uint32_t spare_size;
  uint32_t block_num;
  uint32_t pages_per_block;
}sim_cfg_t;

typedef struct sim {
  const struct sim_ops *ops;
  void * priv;
}sim_t;

typedef struct sim_ops {
  int (*init)(sim_t *obj, const sim_cfg_t *cfg);
  int (*erase)(sim_t *obj, uint32_t block);
  int (*read)(sim_t *obj, uint32_t page);
  int (*write)(sim_t *obj, uint32_t page);
}sim_ops_t;


sim_t * sim_allocate(void);


