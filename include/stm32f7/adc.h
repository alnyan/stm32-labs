#pragma once
#include <stdint.h>
#define ADC_BASE                    0x40012000
#define ADC1_OFFSET                 0x000
#define ADC_COMMON_OFFSET           0x300

struct stm_adc {
    uint32_t sr;                // 0x00
    uint32_t cr1;               // 0x04
    uint32_t cr2;               // 0x08
    uint32_t smpr1;             // 0x0C
    uint32_t smpr2;             // 0x10
    uint32_t jofr1;             // 0x14
    uint32_t jofr2;             // 0x18
    uint32_t jofr3;             // 0x1C
    uint32_t jofr4;             // 0x20
    uint32_t htr;               // 0x24
    uint32_t ltr;               // 0x28
    uint32_t sqr1;              // 0x2C
    uint32_t sqr2;              // 0x30
    uint32_t sqr3;              // 0x34
    uint32_t jsqr;              // 0x38
    uint32_t jdr1;              // 0x3C
    uint32_t jdr2;              // 0x40
    uint32_t jdr3;              // 0x44
    uint32_t jdr4;              // 0x48
    uint32_t dr;                // 0x4C
};

struct stm_adc_common {
    uint32_t csr;
    uint32_t ccr;
    uint32_t cdr;
};


static struct stm_adc *volatile const adc1 = (struct stm_adc *) (ADC_BASE);
static struct stm_adc_common *volatile const adc_common =
        (struct stm_adc_common *) (ADC_BASE + ADC_COMMON_OFFSET);

#define ADC_CR1_OVRIE               (1 << 26)
#define ADC_CR1_EOCIE               (1 << 5)
#define ADC_CR1_RES_8               (2 << 24)

#define ADC_CR2_SWSTART             (1 << 30)
#define ADC_CR2_EXTEN_RISING        (1 << 28)
#define ADC_CR2_EXTSEL_TIM2_CH2     ( 3 << 24)
#define ADC_CR2_EXTSEL_TIM2_TRGO    (11 << 24)
#define ADC_CR2_DMA                 (1 << 8)
#define ADC_CR2_ADON                (1 << 0)

#define ADC_SR_EOC                  (1 << 1)
#define ADC_SR_STRT                 (1 << 4)
#define ADC_SR_OVR                  (1 << 5)

#define ADC_IRQ                     18
