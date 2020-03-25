ENTRY(kernel_entry);

MEMORY {
    FLASH (rx)       : ORIGIN = 0x08000000, LENGTH = 2M
    SRAM1(rwx)      : ORIGIN = 0x20020000, LENGTH = 368K
    SRAM2(rwx)      : ORIGIN = 0x2007C000, LENGTH = 16K
    DTCM(rwx)       : ORIGIN = 0x20000000, LENGTH = 128K
}

SECTIONS {
    .text : {
        _kernel_base = .;
        *(.text.vectors)
        *(.text)
    } >SRAM2

    .data : {
        *(.data)
    } >SRAM2
}
