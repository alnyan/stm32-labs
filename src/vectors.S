.syntax unified
.cpu cortex-m7
.thumb

.section .text
exc_generic:
1:
    b 1b

.section .vector_table, "a", %progbits
.type vtable, %object
vtable:
    .word __stack_top
    .word reset_handler
    .word nmi_handler
    .word hard_fault_handler
    .word 0
    .word 0
    .word 0
    .word 0
    .word 0
    .word 0
    .word 0
    .word svc_handler
    .word 0
    .word 0
    .word pending_sv_handler
    .word systick_handler
.size vtable, . - vtable

// ARM generic vectors
.weak nmi_handler
.weak hard_fault_handler
.weak svc_handler
.weak pending_sv_handler
.weak systick_handler

.thumb_set nmi_handler,         exc_generic
.thumb_set hard_fault_handler,  exc_generic
.thumb_set svc_handler,         exc_generic
.thumb_set pending_sv_handler,  exc_generic
.thumb_set systick_handler,     exc_generic
