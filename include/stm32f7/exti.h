#pragma once
#include <stdint.h>

#define EXTI_BASE 0x40013C00

struct stm_exti {
    uint32_t imr;
    uint32_t emr;
    uint32_t rtsr;
    uint32_t ftsr;
    uint32_t swier;
    uint32_t pr;
};

static struct stm_exti *volatile const exti = (struct stm_exti *) EXTI_BASE;
