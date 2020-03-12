#pragma once
#include <stdint.h>

struct object {
    // ...

    struct object *gc_prev, *gc_next;
    uint32_t gc_flags;
};
