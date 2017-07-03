#include <avr/io.h>
#include "init.h"
#include "led.h"

int main(void){

	init();

	while(1){

		if (!((~PIND & (1 << PD2)) && (~PIND & (1 << PD3))))
//			PORTB |= (1 << PB1);
			ledRed(1);
		else
//			PORTB &= ~(1 << PB1);	
			ledRed(0);
		
		if ((~PIND & (1 << PD2)) || (~PIND & (1 << PD3)))
//			PORTB |= (1 << PB2);
			ledYellow(1);
		else
//			PORTB &= ~(1 << PB2);
			ledYellow(0);

		if (!(~PIND & (1 << PD2)) != !(~PIND & (1 << PD3)))
//			PORTB |= (1 << PB3);
			ledGreen(1);
		else
//			PORTB &= ~(1 << PB3);
			ledGreen(0);
	
	}
	
	return 0;
}
