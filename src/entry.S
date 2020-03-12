.syntax unified
.cpu cortex-m7
.thumb

.global reset_handler

.section .text, "ax", %progbits
.type reset_handler, %function
reset_handler:
    // Zero .bss section
    ldr r1, =__bss_start
    ldr r2, =__bss_end
    mov r0, #0
1:
    cmp r1, r2
    beq 2f
    str r0, [r1]
    add r1, r1, #4
    b 1b
2:

    // Copy .data section
    ldr r1, =__data_start_src
    ldr r2, =__data_start
    ldr r3, =__data_end
3:
    cmp r2, r3
    beq 4f
    ldr r4, [r1]
    str r4, [r2]
    add r1, r1, #4
    add r2, r2, #4
    b 3b
4:

    b main

.size reset_handler, . - reset_handler
