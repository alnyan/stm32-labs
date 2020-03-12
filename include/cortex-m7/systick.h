#pragma once
#include <stdint.h>
#define SYSTICK_BASE    0xE000E010

struct systick_regs {
    uint32_t csr;
    uint32_t rvr;
    uint32_t cvr;
    uint32_t calib;
};

static struct systick_regs *volatile const systick = (struct systick_regs *) SYSTICK_BASE;
