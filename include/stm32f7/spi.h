#pragma once

struct stm_spi {
    uint32_t cr1;
    uint32_t cr2;
    uint32_t sr;
    uint32_t dr;
    uint32_t crcpr;
    uint32_t rxcrcr;
    uint32_t txcrcr;
    uint32_t i2scfgr;
    uint32_t i2spr;
};

#define SPI1_BASE       0x40013000

static struct stm_spi *volatile const spi1 = (struct stm_spi *) SPI1_BASE;
