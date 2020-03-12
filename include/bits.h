#pragma once

#define bit4_write(field, off, val) \
    (field) &= ~(0xF << ((off) * 4)); \
    (field) |= ((val) & 0xF) << ((off) * 4);
#define bit2_write(field, off, val) \
    (field) &= ~(0x3 << ((off) * 2)); \
    (field) |= ((val) & 0x3) << ((off) * 2);
#define bit1_write(field, off, val) \
    (field) &= ~(0x1 << ((off) * 1)); \
    (field) |= ((val) & 0x1) << ((off) * 1);
