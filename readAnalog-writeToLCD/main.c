/**
	@author Mahir Hasan
	@version 0.1
	@file main.c
*/

#define F_CPU 3686400UL //CPU clock

/******************************************************************************/
/* INCLUDED FILES                                                             */
/******************************************************************************/
#include <avr/io.h>
// newly added
#include <util/delay.h>
#include <stdio.h>
#include "lcd.h"
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

/**
	@brief Init the microcontroller
*/
void init(void){
	// Digital I/O init----------------------------------------------------
	DDRB &= ~(1 << DDB0);		// PB0 as Input (key 1)
	PORTB |= ( 1 << PB0);		// Pullup PB0

	DDRB |=  (1 << DDB1);		// PB1 as Output (LED red)
	DDRB |=  (1 << DDB2);		// PB2 as Output (LED yellow)
	DDRB |=  (1 << DDB3);		// PB3 as Output (LED green)


	// ADC init------------------------------------------------------------
	DDRC &= ~(1 << DDC3);		// PC3 as Input (Poti)
	PORTC &= ~(1 << DDC3);		// Pullup PC3 OFF	
	
	// ADMUX
	ADMUX = 0;
	ADMUX |= (1 << REFS0); // AVCC as reference
	//TODO Use the datasheet
	ADMUX |= (1 << MUX1)|(1 << MUX0); // Select Channel ADC3
	
	// ADCSRA
	ADCSRA = (1 << ADPS2)|(1 << ADPS1); // Set ADC Prescale to 64

	// Start conversion, Free running, Enalbe ADC
	ADCSRA |= (1 << ADSC)|(1 << ADFR)|(1 << ADEN); 

}
/******************************************************************************/


/**
	@brief Main function
	@return only a dummy to avoid a compiler warning, not used
*/
int main(void){
	
	//user-defined variables
	uint16_t adc_value;
	//uint8_t buttonPressed;
	char str[17];
	
	// Init
	init();

	// Loop forever
	while (1){
	
		/** Task 2.2.3
		** ADC
		**/
		
		adc_value = ADCW;
		
		if (adc_value < 340){
			PORTB |= (1 << PB3);
			PORTB &= ~(1 << PB1);
			PORTB &= ~(1 << PB2);
		}
			
		if (adc_value >= 340 && adc_value < 680){
			PORTB |= (1 << PB2);
			PORTB &= ~(1 << PB3);
			PORTB &= ~(1 << PB1);
		}
			
		if (adc_value >= 680 && adc_value <=1023){
			PORTB |= (1 << PB1);
			PORTB &= ~(1 << PB2);
			PORTB &= ~(1 << PB3);
		}

		/** Task 2.2.3_bonus
		** Bonus part - Showing ADC on display
		**/

		lcd_init();
		lcd_clear();
		lcd_home();
		snprintf(str,17, "%d", adc_value);
		lcd_string(str);
		_delay_ms(500);
		
	}
	return 0;
}
