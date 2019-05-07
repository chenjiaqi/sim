/**
 * @brief
 *
 * @file gc.h
 * @date 2019-05-06
 * @author ChenJiaqi
 */
#ifndef __GC_H__
#define __GC_H__
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

struct gc_s {
    uint8_t gc;
};
typedef struct gc_s gc_t;
int gc_init()
int gc_allocate();
int gc_mark_dirty(uint8_t page_num);
#endif