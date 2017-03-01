#define F_CPU 20e6UL

#include <avr/io.h>
#include <util/delay.h>

// Input things
#define INPUT_PORT PORTD
#define INPUT_DDR DDRD
#define INPUT_DDR_MASK 0x00
#define SENSOR 6
#define RESET 7
// Output things
#define OUTPUT_PORT PORTC
#define OUTPUT_DDR DDRC
#define OUTPUT_DDR_MASK 0xFF
#define OUTPUT_MASK 0x0F



void setup();


int main() {
	setup();

	uint8_t counter = 0;
	
	while(1){
		if (INPUT&(1<<SENSOR)){
			counter++;
		}
 		if (INPUT&(1<<RESET)){
			counter=0;
		}
		OUTPUT_PORT = counter&OUTPUT_MASK;		

		_delay_ms(500);
	}	



	return 0;
}

void setup(){
	INPUT_DDR = INPUT_DDR_MASK;
	INPUT_PORT = 0xFF; // set all pull up resistors

	OUTPUT_DDR = OUTPUT_DDR_MASK;
	OUTPUT_DDR = 0x00; // output all zeros at first

}
