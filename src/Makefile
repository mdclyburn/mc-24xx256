MSP430PATH = /usr/local/msp430
MSP430MCU = msp430g2553

MDLMSP430PATH = ../../msp430/src

GCCVERSION = $(shell ls $(MSP430PATH)/lib/gcc/msp430-elf | head -n1)
CC = $(MSP430PATH)/bin/msp430-elf-gcc
CFLAGS = -I $(MDLMSP430PATH) -Os -std=c++17 -nostdlib -ffreestanding -ffunction-sections -fdata-sections -fno-asynchronous-unwind-tables -fno-unwind-tables -fomit-frame-pointer -fno-exceptions -mmcu=$(MSP430MCU)

CXX = $(MSP430PATH)/bin/msp430-elf-g++
CXXFLAGS = $(CFLAGS)

AR = $(MSP430PATH)/bin/msp430-elf-ar

objects = $(addsuffix .o, $(basename $(shell ls *.cpp)))

libmdlmc24xx256.a: $(objects)
	$(AR) rvs $@ $^

$(objects):

.PHONY: clean

clean:
	$(RM) *.o libmdlmc24xx256.a
