#include "sim.h"

typedef struct priv {
  sim_cfg_t cfg;
  uint8_t *data;
}priv_t;

static int init(sim_t *obj, const sim_cfg_t *cfg) {
  if(!obj || !cfg) {
    printf("Param error\n");
    return -1;
  }

  if(obj->priv) {
    printf("Already initial\n");
    return -1;
  }

  priv_t *priv = (priv_t *)malloc(sizeof(priv_t));

  if(!priv) {
    printf("ERROR:priv memory \n");
    return -1;
  }

  memset(priv, 0, sizeof(priv_t));

  priv->cfg = *cfg;
  printf("total size is %u\n", (cfg->page_size + cfg->spare_size) * cfg->pages_per_block * cfg->block_num);
  priv->data = (uint8_t *)malloc((cfg->page_size + cfg->spare_size) * cfg->pages_per_block * cfg->block_num);
  memset(priv->data, 0xff, (cfg->page_size + cfg->spare_size) * cfg->pages_per_block * cfg->block_num);
  if(!priv->data) {
    printf("ERROR:priv data memory\n");
  }

  obj->priv = priv;
  return 0;
}

static int erase(sim_t *obj, uint32_t block) {
  if(!obj || !obj->priv) {
    printf("ERROR:params");
    return -1;
  }
  priv_t *priv = (priv_t *)obj->priv;
  printf("%d, %d, %d, %d\n", priv->cfg.page_size, priv->cfg.spare_size, priv->cfg.pages_per_block, priv->cfg.block_num);
  return 0;
}
sim_t * sim_allocate(void) {
  sim_t * sim = (sim_t *) malloc(sizeof(sim_t));
  if(!sim) {
    printf("eror\n");
    return NULL;
  }
  memset(sim, 0, sizeof(*sim));
  static const sim_ops_t ops = {
    .init = init,
    .erase = erase,
    .read = NULL,
    .write = NULL,
  };

  sim->ops = &ops;
  return sim;
}