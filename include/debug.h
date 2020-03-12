#pragma once
#include <stdint.h>
#include <stdarg.h>

#define dprintf(fmt, ...)       \
    debug_printf("[" __FILE__ ":%d] " fmt "\r\n", __LINE__, ##__VA_ARGS__)

char serial_getc(void);
void serial_putc(char c);
void serial_puts(const char *s);
void serial_putsn(const char *s);

void debug_printf(const char *fmt, ...);
void debug_printfv(const char *fmt, va_list args);
