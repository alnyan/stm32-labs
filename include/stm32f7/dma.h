#pragma once
#include <stdint.h>

#define DMA2_BASE           0x40026400
#define DMA1_BASE           0x40026000

struct stm_dma_stream {
    uint32_t cr;
    uint32_t ndtr;
    uint32_t par;
    uint32_t m0ar;
    uint32_t m1ar;
    uint32_t fcr;
};

struct stm_dma {
    uint32_t lisr;
    uint32_t hisr;
    uint32_t lifcr;
    uint32_t hifcr;
    struct stm_dma_stream stream[8];
};

static struct stm_dma *volatile const dma1 = (struct stm_dma *) DMA1_BASE;
static struct stm_dma *volatile const dma2 = (struct stm_dma *) DMA2_BASE;

#define DMA_HISR_TCIF6          (1 << 21)
#define DMA_HISR_HTIF6          (1 << 20)
#define DMA_LISR_TCIF0          (1 << 5)
#define DMA_LISR_HTIF0          (1 << 4)
#define DMA_LISR_TEIF0          (1 << 3)

#define DMA1_STREAM0_IRQ        11
#define DMA1_STREAM1_IRQ        12
#define DMA1_STREAM2_IRQ        13
#define DMA1_STREAM3_IRQ        14
#define DMA1_STREAM4_IRQ        15
#define DMA1_STREAM5_IRQ        16
#define DMA1_STREAM6_IRQ        17

#define DMA2_STREAM0_IRQ        56

#define DMA_SxCR_CHAN(x)        (((x) & 0xF) << 25)
#define DMA_SxCR_CT             (1 << 19)
#define DMA_SxCR_DBM            (1 << 18)
#define DMA_SxCR_MINC           (1 << 10)
#define DMA_SxCR_PINC           (1 << 9)
#define DMA_SxCR_DIR_M2M        (2 << 6)
#define DMA_SxCR_DIR_M2P        (1 << 6)
#define DMA_SxCR_DIR_P2M        (0 << 6)
#define DMA_SxCR_MSIZE_WORD     (2 << 13)
#define DMA_SxCR_MSIZE_HWORD    (1 << 13)
#define DMA_SxCR_MSIZE_BYTE     (0 << 13)
#define DMA_SxCR_PSIZE_WORD     (2 << 11)
#define DMA_SxCR_PSIZE_HWORD    (1 << 11)
#define DMA_SxCR_PSIZE_BYTE     (0 << 11)
#define DMA_SxCR_CIRC           (1 << 8)
#define DMA_SxCR_TCIE           (1 << 4)
#define DMA_SxCR_HTIE           (1 << 3)
#define DMA_SxCR_TEIE           (1 << 2)
#define DMA_SxCR_DMEIE          (1 << 1)
#define DMA_SxCR_EN             (1 << 0)
