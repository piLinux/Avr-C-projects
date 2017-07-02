all: main.hex

main.hex: main.elf
	avr-objcopy -O ihex main.elf main.hex

main.elf: main.o init.o led.o
	avr-gcc -mmcu=atmega8 -o main.elf main.o init.o led.o

main.o: main.c
	avr-gcc -coverage -mmcu=atmega8 -c -Os main.c

init.o: init.c init.h
	avr-gcc -coverage -mmcu=atmega8 -c -Os init.c

led.o: led.c led.h
	avr-gcc -coverage -mmcu=atmega8 -c -Os led.c

program: main.hex
	avrdude -P /dev/ttyUSB0 -p m8 -c avr911 -Uflash:w:main.hex:i

clean:
	rm -f main.hex
	rm -f *.o *.elf *~
