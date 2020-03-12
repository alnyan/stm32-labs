#pragma once
#include <stdint.h>
#define USART2_BASE     0x40004400
#define USART2_IRQ      38

struct stm_usart {
    uint32_t cr1;
    uint32_t cr2;
    uint32_t cr3;
    uint32_t brr;
    uint32_t gtpr;
    uint32_t rtor;
    uint32_t rqr;
    uint32_t isr;
    uint32_t icr;
    uint32_t rdr;
    uint32_t tdr;
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
