.syntax unified
.cpu cortex-m7
.thumb

// Input values
.set A, 123
.set B, 321
.set C, 121

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
    bl usart_init

    ldr r1, =A
    ldr r2, =B
    ldr r3, =C

    mul r0, r1, r2
    cmp r0, #10         // if (r0 >= 10)
    blt 1f
    // r0 >= 10, r0 = r1 | r2
    orr r0, r1, r2
    b 2f
1:
    // r0 < 10, r0 = r1 & r2
    and r0, r1, r2
2:
    // r0 *= r3
    mul r0, r0, r3

    // Preserve the value so it's not
    // clobbered by putd and gdb can see it
    mov r8, r0
    // Output r0
    bl usart_putd
    mov r0, r8

    b .
