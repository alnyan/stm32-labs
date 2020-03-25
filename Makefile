O=$(abspath build)
OBJS=$(O)/vectors.o \
	 $(O)/entry.o
kernel_OBJS=$(O)/kernel.o

HDRS=$(shell find -name "*.h" -type f)

OC=$(CROSS_COMPILE)objcopy
CC=$(CROSS_COMPILE)gcc
LD=$(CROSS_COMPILE)ld

CFLAGS=-mthumb \
	   -mcpu=cortex-m7 \
	   -mfpu=fpv5-d16 \
	   -ffreestanding \
	   -O0 \
	   -gdwarf \
	   -Iinclude
LDFLAGS=-lgcc \
		-nostdlib

all: mkdirs $(O)/kernel.bin $(O)/image.hex
	$(CROSS_COMPILE)size $(O)/image.elf

clean:
	rm -rf $(O)

mkdirs:
	mkdir -p $(O)/host $(O)/util

$(O)/image.hex: $(O)/image.elf
	$(OC) -O ihex $< $@

$(O)/image.elf: $(OBJS) $(O)/kernel.bin f767.ld
	$(CC) $(LDFLAGS) -Tf767.ld -o $@ $(OBJS)

$(O)/kernel.bin: $(O)/kernel.elf
	$(OC) -O ihex $< $(O)/kernel.hex
	$(OC) -O binary $< $@

$(O)/kernel.elf: $(kernel_OBJS) kernel.ld
	$(CC) $(LDFLAGS) -Tkernel.ld -o $@ $(kernel_OBJS)

$(O)/%.o: src/%.S $(HDRS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(O)/%.o: src/%.c $(HDRS)
	$(CC) $(CFLAGS) -c -o $@ $<
