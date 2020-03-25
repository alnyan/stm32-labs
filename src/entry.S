.syntax unified
.cpu cortex-m7
.thumb

.global reset_handler

.set _kernel_size, kernel_image_end - kernel_image

.section .text, "ax", %progbits
.type reset_handler, %function
reset_handler:
    ldr r0, =kernel_image
    ldr r1, [r0, #4]                            // Kernel entry
    ldr r2, [r0, #8]                            // Kernel load address
    // Stack
    ldr r3, [r0, #0]
    mov sp, r3

    // TODO: maybe align this word-up
    mov r3, _kernel_size                        // Kernel size
1:
    // *dst = *src
    ldr r4, [r0]
    str r4, [r2]

    // ++dst, ++src, --size
    add r2, r2, #4
    add r0, r0, #4
    subs r3, r3, #4
    bne 1b

    // Jump to entrypoint
    mov r0, r0
    mov pc, r1

.align 4
kernel_image:
    .incbin "build/kernel.bin"
kernel_image_end:

.size reset_handler, . - reset_handler
