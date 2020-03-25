#pragma once
#include <stdint.h>
#define USART2_BASE     0x40004400
#define USART2_IRQ      38

struct stm_usart {
    uint32_t cr1;   // 0x00
    uint32_t cr2;   // 0x04
    uint32_t cr3;   // 0x08
    uint32_t brr;   // 0x1C
    uint32_t gtpr;  // 0x20
    uint32_t rtor;  // 0x24
    uint32_t rqr;   // 0x28
    uint32_t isr;   // 0x2C
    uint32_t icr;   // 0x30
    uint32_t rdr;   // 0x34
    uint32_t tdr;   // 0x38
};

static struct stm_usart *volatile const usart2 = (struct stm_usart *) USART2_BASE;

#define USART_CR1_UE        (1 << 0)
#define USART_CR1_RE        (1 << 2)
#define USART_CR1_TE        (1 << 3)
#define USART_CR1_RXNEIE    (1 << 5)

#define USART_CR3_DMAT      (1 << 7)

#define USART_ISR_RXNE      (1 << 5)
#define USART_ISR_TXE       (1 << 7)
#define USART_ISR_ORE       (1 << 3)
