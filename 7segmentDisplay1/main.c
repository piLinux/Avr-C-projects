/**
	@author Mahir
	@version 0.1
	@file one.c
	@brief Seven segment display
	pushbutton1 will increment from 0 to 9
	with debouncing and signal edge evaluation
*/

#define F_CPU 8000000UL

/******************************************************************************/
/* INCLUDED FILES                                                             */
/******************************************************************************/
#include <avr/io.h>
#include <util/delay.h>
/******************************************************************************/


/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
/**
	@brief Init input and output
*/
void init(void){
	
	// Input
	DDRD &= (1 << DDD2);
	PORTD |= (1 << PD2);

	// Output
	DDRB |= (1 << DDB0);
	DDRB |= (1 << DDB1);
	DDRB |= (1 << DDB2);
	DDRB |= (1 << DDB3);
	DDRC |= (1 << DDC0);
	DDRC |= (1 << DDC1);
	DDRC |= (1 << DDC2);

}
/******************************************************************************/

void sevensegment(uint8_t value){
	static uint8_t last = 255;
	
	// stop here if no change
	if (value == last)
		return;
	
	last = value;

	// Enable LEDs for value
	switch(value){
	
		case(1):
			PORTC |= (1 << PC2); // A
			PORTC &= ~(1 << PC1); // B
			PORTC &= ~(1 << PC0); // C
			PORTB |= (1 << PB0); // D
			PORTB |= (1 << PB1); // E
			PORTB |= (1 << PB2); // F
			PORTB |= (1 << PB3); // G
			
			break;
			
		case(2):
			PORTC &= ~(1 << PC2); // A
			PORTC &= ~(1 << PC1); // B
			PORTC |= (1 << PC0); // C
			PORTB &= ~(1 << PB0); // D
			PORTB &= ~(1 << PB1); // E
			PORTB |= (1 << PB2); // F
			PORTB &= ~(1 << PB3); // G
			
		break;

		case(3):
			PORTC &= ~(1 << PC2); // A
			PORTC &= ~(1 << PC1); // B
			PORTC &= ~(1 << PC0); // C
			PORTB &= ~(1 << PB0); // D
			PORTB |= (1 << PB1); // E
			PORTB |= (1 << PB2); // F
			PORTB &=  ~(1 << PB3); // G
			
		break;

		case(4):
			PORTC |= (1 << PC2); // A
			PORTC &= ~(1 << PC1); // B
			PORTC &= ~(1 << PC0); // C
			PORTB |= (1 << PB0); // D
			PORTB |= (1 << PB1); // E
			PORTB &= ~(1 << PB2); // F
			PORTB &= ~(1 << PB3); // G
			
		break;

		case(5):
			PORTC &= ~(1 << PC2); // A
			PORTC |= (1 << PC1); // B
			PORTC &= ~(1 << PC0); // C
			PORTB &= ~(1 << PB0); // D
			PORTB |= (1 << PB1); // E
			PORTB &= ~(1 << PB2); // F
			PORTB &= ~(1 << PB3); // G
			
		break;

		case(6):
			PORTC |= (1 << PC2); // A
			PORTC |= (1 << PC1); // B
			PORTC &= ~(1 << PC0); // C
			PORTB &= ~(1 << PB0); // D
			PORTB &= ~(1 << PB1); // E
			PORTB &= ~(1 << PB2); // F
			PORTB &= ~(1 << PB3); // G
			
		break;

		case(7):
			PORTC &= ~(1 << PC2); // A
			PORTC &= ~(1 << PC1); // B
			PORTC &= ~(1 << PC0); // C
			PORTB |= (1 << PB0); // D
			PORTB |= (1 << PB1); // E
			PORTB |= (1 << PB2); // F
			PORTB |= (1 << PB3); // G
			
		break;
			
		case(8):
			PORTC &= (1 << PC2); // A
			PORTC &= ~(1 << PC1); // B
			PORTC &= ~(1 << PC0); // C
			PORTB &= ~(1 << PB0); // D
			PORTB &= ~(1 << PB1); // E
			PORTB &= ~(1 << PB2); // F
			PORTB &= ~(1 << PB3); // G
			
		break;

		case(9):
			PORTC &= ~(1 << PC2); // A
			PORTC &= ~(1 << PC1); // B
			PORTC &= ~(1 << PC0); // C
			PORTB |= (1 << PB0); // D
			PORTB |= (1 << PB1); // E
			PORTB &= ~(1 << PB2); // F
			PORTB &= ~(1 << PB3); // G
			
		break;

		default:
			PORTC &= ~(1 << PC2); // A   pin 10
			PORTC &= ~(1 << PC1); // B   pin 9
			PORTC &= ~(1 << PC0); // C   pin 7
			PORTB &= ~(1 << PB0); // D   pin 5
			PORTB &= ~(1 << PB1); // E   pin 4 
			PORTB &= ~(1 << PB2); // F   pin 2
			PORTB |= (1 << PB3); // G    pin 1
			
		break;	
			
	}
  
}
/******************************************************************************/


/**
	@brief Main function
	@return only a dummy to avoid a compiler warning, not used
*/
int main(void){
	uint8_t value = 0;

	init(); 	// Function to initialise I/Os

	// Loop forever
	while (1){
		sevensegment(value);

		if(~PIND & (1 << PD2)){  
			_delay_ms(20);
			
			if(~PIND & (1 << PD2)){
				
				if(value>= 9){
						value = 0;		
					}
		
				else{
					value++;
					}
				
				sevensegment(value);
					
				//wait until button is released
				while(~PIND & (1<<PD2));
				
			}
		}
	}

	return 0;
}
/******************************************************************************/
