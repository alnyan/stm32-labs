#pragma once
#include <stdint.h>
#define TIM2_BASE           0x40000000

struct stm_gp_timer {
    uint32_t cr1;
    uint32_t cr2;
    uint32_t smcr;
    uint32_t dier;
    uint32_t sr;
    uint32_t egr;
    uint32_t ccmr1;
    uint32_t ccmr2;
    uint32_t ccer;
    uint32_t cnt;
    uint32_t psc;
    uint32_t arr;
};

static struct stm_gp_timer *volatile const tim2 = (struct stm_gp_timer *) TIM2_BASE;

#define GPTIM_CR1_CEN           (1 << 0)

#define GPTIM_CR2_MMS_OC2REF_TRGO   (5 << 4)
#define GPTIM_CR2_MMS_UE_TRGO       (2 << 4)

#define GPTIM_DIER_TIE          (1 << 6)
#define GPTIM_DIER_CC2IE        (1 << 2)
#define GPTIM_DIER_CC1IE        (1 << 1)
#define GPTIM_DIER_UIE          (1 << 0)

#define GPTIM_SR_TIF            (1 << 6)
#define GPTIM_SR_CC2IF          (1 << 2)
#define GPTIM_SR_CC1IF          (1 << 1)
#define GPTIM_SR_UIF            (1 << 0)

#define TIM2_IRQ                28
