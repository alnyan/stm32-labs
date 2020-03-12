#pragma once
#include <stddef.h>
#include <stdint.h>

struct object;

struct object *heap_alloc(void);
int heap_collect(void);

void heap_hold(struct object *v);
void heap_release(struct object *v);

int heap_init(uintptr_t base, size_t heap_max);
