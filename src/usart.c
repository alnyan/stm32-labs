#include "stm32f7/usart.h"
#include "stm32f7/gpio.h"
#include "stm32f7/rcc.h"
#include "bits.h"

#define MHz             * 1000000
#define FREQ_HSE        (25 MHz)
#define FREQ_HSI        (16 MHz)

void usart_init(void) {
    rcc->apb1enr |= RCC_USART2EN;
    rcc->ahb1enr |= RCC_GPIODEN;

    bit4_write(gpiod->afrl, 5, 7);
    bit2_write(gpiod->pupdr, 5, GPIO_PUPDR_UP);
    bit2_write(gpiod->moder, 5, GPIO_MODER_ALT);

    usart2->cr1 &= ~USART_CR1_UE;
    usart2->brr = 138;
    usart2->cr1 |= USART_CR1_TE;
    usart2->cr1 |= USART_CR1_UE;
}

void usart_puts(const char *line) {
    char c;
    while ((c = *line++)) {
        while (!(usart2->isr & USART_ISR_TXE)) {
        }
        usart2->tdr = c;
    }
}

void usart_putd(uint32_t v) {
    char res[32];
    int c;
    c = 0;

    while (v) {
        res[c++] = '0' + v % 10;
        v /= 10;
    }
    res[c] = 0;

    for (int i = 0, j = c - 1; i < j; ++i, --j) {
        res[i] ^= res[j];
        res[j] ^= res[i];
        res[i] ^= res[j];
    }

    usart_puts(res);
    usart_puts("\r\n");
}
