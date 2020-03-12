.set A, 123
.set B, 321
.set C, 121

.syntax unified
.cpu cortex-m7
.thumb

.global reset_handler

.section .text, "ax", %progbits
.type reset_handler, %function
reset_handler:
    ldr r1, =A
    ldr r2, =B
    ldr r3, =C

    mul r4, r1, r2
    cmp r4, #10         // if (r4 >= 10)
    blt 1f
    // r4 >= 10, r4 = r1 | r2
    orr r4, r1, r2
    b 2f
1:
    // r4 < 10, r4 = r1 & r2
    and r4, r1, r2
2:
    // r4 *= r3
    mul r4, r4, r3

_hang:
    wfe
    b _hang

.size reset_handler, . - reset_handler
