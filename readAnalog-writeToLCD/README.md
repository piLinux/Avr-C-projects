# Read Analog Value and Write to an LCD
[![Build Status](https://travis-ci.org/piLinux/Avr-C-projects.svg?branch=master)](https://travis-ci.org/piLinux/Avr-C-projects)

### Accessories
- myAVR MK2 board
- a HD44780 compatible LCD
- hookup wires

### Pin Configuration
- PB1 to red LED 
- PB2 to yellow LED 
- PB3 to green LED
- PC3 to potentiometer (Pot.1)
- LCD module to MK2 board 

![Image](readAnalog-writeToLCD/img1.jpg)

### Output
- When analog input is 0 – 1.66V, only Green LED is ON.
- When analog input is 1.66 – 3.32V, only Yellow LED is ON.
- When analog input is 3.32 – 5V, only Red LED is ON.
- The LCD module will show the updated adc value of potentiometer.
