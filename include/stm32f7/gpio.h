#pragma once
#include <stdint.h>

struct stm_gpio {
    uint32_t moder;     // 0x00
    uint32_t otyper;    // 0x04
    uint32_t ospeedr;   // 0x08
    uint32_t pupdr;     // 0x0C
    uint32_t idr;       // 0x10
    uint32_t odr;       // 0x14
    uint32_t bsrr;      // 0x18
    uint32_t lckr;      // 0x1C
    uint32_t afrl;      // 0x20
    uint32_t afrh;
};

#define GPIOA_BASE      0x40020000
#define GPIOB_BASE      0x40020400
#define GPIOC_BASE      0x40020800
#define GPIOD_BASE      0x40020C00
#define GPIOE_BASE      0x40021000

#define GPIO_PUPDR_UP   1
#define GPIO_PUPDR_DOWN 2

#define GPIO_MODER_OUT      1
#define GPIO_MODER_ALT      2
#define GPIO_MODER_ANALOG   3

static struct stm_gpio *volatile const gpioa = (struct stm_gpio *) GPIOA_BASE;
static struct stm_gpio *volatile const gpiob = (struct stm_gpio *) GPIOB_BASE;
static struct stm_gpio *volatile const gpioc = (struct stm_gpio *) GPIOC_BASE;
static struct stm_gpio *volatile const gpiod = (struct stm_gpio *) GPIOD_BASE;
static struct stm_gpio *volatile const gpioe = (struct stm_gpio *) GPIOE_BASE;
