################################################################################
# Makefile for Timer/Counter                                                   #
# Author: Mahir Hasan                                                          #
################################################################################


# Options ######################################################################
PORT=/dev/ttyUSB0
PROGRAMMER=avr911
TARGET_CPU=atmega8
TARGET_PROCESSOR=m8
CFLAGS=-Wall -Os -c -mmcu=$(TARGET_CPU)
LDFLAGS=-Os -mmcu=$(TARGET_CPU)

# Program ######################################################################
all: main.hex
	echo program build complete

program: main.hex
	avrdude -p $(TARGET_PROCESSOR) -c $(PROGRAMMER) -P $(PORT) -U flash:w:main.hex:i


# Hex File #####################################################################
main.hex: main.elf
	avr-objcopy -O ihex main.elf main.hex

main.elf: main.o
	avr-gcc $(LDFLAGS) main.o -o main.elf


# Object Files #################################################################
main.o: main.c
	avr-gcc $(CFLAGS) main.c -o main.o


# Clean ########################################################################
clean:
	rm -f *.o *.elf *.hex *~
