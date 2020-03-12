#pragma once

static uint32_t *volatile const nvic_iser0 = (uint32_t *) 0xE000E100;
static uint32_t *volatile const nvic_ispr0 = (uint32_t *) 0xE000E200;
static uint32_t *volatile const nvic_icpr0 = (uint32_t *) 0xE000E280;
static uint32_t *volatile const nvic_ipr0 = (uint32_t *) 0xE000E400;

static inline void nvic_enable_irq(int irq) {
    nvic_iser0[irq / 32] |= 1 << (irq % 32);
}

static inline void nvic_clear_irq(int irq) {
    nvic_icpr0[irq / 32] |= 1 << (irq % 32);
}

static inline void nvic_set_priority(int irq, int prio) {
    nvic_ipr0[irq / 4] &= 0xFF << ((irq % 4) * 8);
    nvic_ipr0[irq / 4] |= prio << ((irq % 4) * 8);
}
