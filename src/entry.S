.syntax unified
.cpu cortex-m7
.thumb

.global reset_handler

.section .text, "ax", %progbits
.type reset_handler, %function
reset_handler:
    b reset_handler

.size reset_handler, . - reset_handler
