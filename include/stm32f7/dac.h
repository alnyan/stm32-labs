#pragma once
#include <stdint.h>

#define DAC_BASE            0x40007400

struct stm_dac {
    uint32_t cr;            // 0x00
    uint32_t swtrigr;       // 0x04
    uint32_t dhr12r1;       // 0x08
    uint32_t dhr12l1;       // 0x0C
    uint32_t dhr8r1;        // 0x10
    uint32_t dhr12r2;       // 0x14
    uint32_t dhr12l2;       // 0x18
    uint32_t dhr8r2;        // 0x1C
    uint32_t dhr12rd;       // 0x20
    uint32_t dhr12ld;       // 0x24
    uint32_t dhr8rd;        // 0x28
    uint32_t dor1;          // 0x2C
    uint32_t dor2;          // 0x30
    uint32_t sr;            // 0x34
};

static struct stm_dac *volatile const dac = (struct stm_dac *) DAC_BASE;

#define DAC_CR_EN1          (1 << 0)
