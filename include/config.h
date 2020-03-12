#pragma once
#include <stdint.h>

extern char *__heap_start, *__heap_end;

#define CFG_HEAP_BASE           ((uintptr_t) 0x20000000)
#define CFG_HEAP_SIZE           ((size_t) (64 * 1024))
