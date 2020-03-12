#pragma once
#include <stdint.h>

#define SYSCFG_BASE 0x40013800

struct stm_syscfg {
    uint32_t memrmp;
    uint32_t pmc;
    uint32_t exticr1;
    uint32_t exticr2;
    uint32_t exticr3;
    uint32_t exticr4;
};

static struct stm_syscfg *volatile const syscfg = (struct stm_syscfg *) SYSCFG_BASE;
