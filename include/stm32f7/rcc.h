#pragma once
#include <stdint.h>
#define RCC_BASE        0x40023800

struct stm_rcc {
    uint32_t cr;
    uint32_t pllcfgr;
    uint32_t cfgr;
    uint32_t cir;
    uint32_t ahb1rstr;
    uint32_t ahb2rstr;
    uint32_t ahb3rstr;
    uint32_t __res0;
    uint32_t apb1rstr;
    uint32_t apb2rstr;
    uint32_t __res1;
    uint32_t __res2;
    uint32_t ahb1enr;
    uint32_t ahb2enr;
    uint32_t ahb3enr;
    uint32_t __res3;
    uint32_t apb1enr;
    uint32_t apb2enr;
    uint32_t __res4;
    uint32_t __res5;
    uint32_t __skip0[15];
    uint32_t dckcfgr1;
    uint32_t dckcfgr2;
};

// AHB1
#define RCC_GPIOAEN             (1 << 0)
#define RCC_GPIOBEN             (1 << 1)
#define RCC_GPIOCEN             (1 << 2)
#define RCC_GPIODEN             (1 << 3)
#define RCC_GPIOEEN             (1 << 4)
#define RCC_AHB1ENR_DMA2EN      (1 << 22)
#define RCC_AHB1ENR_DMA1EN      (1 << 21)

// APB1
#define RCC_USART2EN            (1 << 17)
#define RCC_TIM2EN              (1 << 0)
#define RCC_APB1ENR_DACEN       (1 << 29)

// APB2
#define RCC_SPI1EN              (1 << 12)
#define RCC_ADC1EN              (1 << 8)

static struct stm_rcc *volatile const rcc = (struct stm_rcc *) RCC_BASE;
