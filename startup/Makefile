#
# Makefile for ARMv8-A sample
#

TOOLS_PREFIX = aarch64-none-elf-

CC = $(TOOLS_PREFIX)gcc
AS = $(TOOLS_PREFIX)gcc
LD = $(TOOLS_PREFIX)gcc
OBJCOPY = $(TOOLS_PREFIX)objcopy

RM = rm

CFLAGS  +=  -std=gnu11 -mcpu=cortex-a53
CFLAGS  += -g -gdwarf-3 -O2
AFLAGS  += $(CFLAGS) -D__ASM__
LDFLAGS += -mcpu=cortex-a53 -g -T $(LDSCRIPT)
LDFLAGS += -nostdlib -static -Wl,-Ttext=$(START_MEM_ADDR),--build-id=none
LDLIBS   = -lgcc -lc

INC   =
VPATH =

OBJS = $(C_SRCS:%.c=%.o) $(A_SRCS:%.S=%.o)

TARGET = startup
TARGET_BIN = $(TARGET).bin
TARGET_ELF = $(TARGET).elf

LDSCRIPT = link.ld
START_MEM_ADDR = 0x80000000

C_SRCS = main.c printf.c
A_SRCS = startup.S

.c.o:
	$(CC) -c $(CFLAGS) $(INC) $(DEFS) -v $<

.S.o:
	$(AS) -c $(AFLAGS) $(INC) $(DEFS) -v $<
	
$(TARGET_BIN): $(OBJS)
	$(LD) $(LDFLAGS) -o $(TARGET_ELF) $(OBJS) $(LDLIBS)
	$(OBJCOPY) -O binary $(TARGET_ELF) $(TARGET_BIN)

clean:
	$(RM) -f $(TARGET) $(TARGET_BIN) $(TARGET_ELF) $(OBJS)

run:
	Foundation_Platform --visualization --cores=1 --gicv3 --image=$(TARGET_ELF)
