

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LEDS PORTC
#define INPUT_DDR DDRD
#define INPUT PIND
#define LEDS_DDR DDRC
#define SENSOR 7
#define RST 6
#define LEDS_MASK 0x0F
#define INPUT_MASK 0xFF;


int main(){
	// setup port
	LEDS_DDR = LEDS_MASK;	
	INPUT_DDR = INPUT_MASK;

	uint8_t counter = 0;
	
	INPUT = 0xFF; // Set pull up resistors high
	LEDS = 0x00;

	LEDS |= ((LEDS_MASK&counter));

	while(1){

		if (!(INPUT&(1<<SENSOR))) counter++;
		if (!(INPUT&(1<<RST))) counter = 0;

		LEDS = ((LEDS_MASK&counter)) ;
		
		_delay_ms(500);
	}	
	return 0;
}

