.syntax unified
.cpu cortex-m7
.thumb

// Constants
.set GPIOB,         0x40020400
.set GPIO_ODR,      20
.set RCC,           0x40023800
.set RCC_AHB1ENR,   48

.section .text.vectors
// Kernel stack
.word _kernel_base + 0x4000
// Kernel entrypoint
.word kernel_entry
// Load address
.word _kernel_base

.section ".text"
.global kernel_entry
kernel_entry:
    // No hosted debugging mode,
    // Just use a blinking LED instead
    // PB7 - LED1
    // enable gpiob clock
    ldr r2, =RCC
    ldr r0, [r2, #RCC_AHB1ENR]
    orr r0, #(1 << 1)
    str r0, [r2, #RCC_AHB1ENR]

    // moder[7] = out
    ldr r2, =GPIOB
    ldr r0, [r2]
    and r0, #~(3 << 14)
    orr r0, #(1 << 14)
    str r0, [r2]

    mov r1, #1
1:
    subs r1, r1, #1
    bne 1b
    ldr r1, =10000000
    ldr r0, [r2, #GPIO_ODR]
    eor r0, r0, #(1 << 7)
    str r0, [r2, #GPIO_ODR]
    b 1b
