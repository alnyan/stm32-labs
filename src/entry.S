.syntax unified
.cpu cortex-m7
.thumb

.global reset_handler

.set _kernel_size, (kernel_image_end - kernel_image) / 4

.section .text, "ax", %progbits
.type reset_handler, %function
reset_handler:
    ldr r0, =kernel_image
    ldr r1, [r0, #4]                            // Kernel entry
    ldr r2, [r0, #8]                            // Kernel load address

    // Stack
    ldr r3, [r0, #0]
    mov sp, r3

    ldr r3, =_kernel_size
1:
    subs r3, r3, #1
    beq 2f

    ldr r4, [r0, r3, lsl #2]
    str r4, [r2, r3, lsl #2]

    b 1b
2:

    // Jump to entrypoint
    mov pc, r1

.align 4
kernel_image:
    .incbin "build/kernel.bin"
kernel_image_end:

.size reset_handler, . - reset_handler
