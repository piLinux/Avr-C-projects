# Control LED with Atmel Microcontroller
[![Build Status](https://travis-ci.org/piLinux/avrLEDcontrol.svg?branch=master)](https://travis-ci.org/piLinux/avrLEDcontrol)

[![Coverage Status](https://coveralls.io/repos/github/piLinux/avrLEDcontrol/badge.svg?branch=master)](https://coveralls.io/github/piLinux/avrLEDcontrol?branch=master)

### Accessories
- myAVR MK2 board
- hookup wires

### Pin Configuration
- PB1  red LED 
- PB2  yellow LED 
- PB3  green LED 
- PD2  Taster1 
- PD3  Taster2

![Image](img1.jpg)

### Output
- When any or both pushbuttons (or taster) are pressed, yellow LED will be ON. Otherwise yellow LED is OFF. 
- When only one pushbutton is pressed, green LED will be ON. Otherwise green LED is OFF. 
- When both pushbuttons are pressed, red LED will be OFF. Otherwise red LED is ON.
