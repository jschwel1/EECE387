#define F_CPU 1000000 // Switch to 8000000 for Dom
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

// HC-SR04 Ultrasonic Ranging Module
#define TRIGGER 5
#define LED 4
#define OUTPUT_PORT PORTC
#define OUTPUT_PORT_DDR DDRC
#define OUTPUT_PORT_DDR_MASK 0x30

#define ECHO 2 // D2 => INT0
#define ECHO_PIN PIND
#define ECHO_PIN_DDR DDRD
#define ECHO_PIN_DDR_MASK 0x00 // all inputs

#define PROXIMITY 174

#define CYCLE_DELAY_TIME 65 // Anything over 60ms should work according to datasheet
#define PULSE_TIME 10 // datasheet specifies 10us pulse
// Add timer stuff to count times
#define com1a1 7
#define com1a0 6
#define com1b1 5
#define com1b0 4

#define wgm10 0
#define wgm11 1
#define wgm12 3
#define wgm13 4

#define icnc1 7
#define ices1 6

#define cs10 0
#define cs11 1
#define cs12 2

// Interrupt Stuff
#define ISC01 1
#define ISC00 0

// EIMSK
#define INT0 0

// EIFR
#define INTF0 0

void setup();
void trigger();
void turnOffTimer();
void turnOnTimer();

volatile uint16_t time;

int main(){

	cli();
	setup();
		
	while(1){	
		trigger();
		_delay_ms(CYCLE_DELAY_TIME);

		

		// If the sensor finds something closer than PROXIMITY
		// it will output to the LED pin
		if (time < PROXIMITY) OUTPUT_PORT |= (1 << LED);	
		else OUTPUT_PORT &= ~(1 << LED);	
	
	}
	return 0;
}

void setup(){

	// Settings for Ultrasonic Sensor
	OUTPUT_PORT_DDR = OUTPUT_PORT_DDR_MASK;
	OUTPUT_PORT &= ~(1<<TRIGGER); // Clear trigger ppin

	ECHO_PIN_DDR = ECHO_PIN_DDR_MASK;
	ECHO_PIN |= (1<<ECHO); // set pull-up resistor
	
	// Timer settings

	TCCR1A &= ~(1 << com1a1) & ~(1 << com1b0) & ~(1 << com1b1) & ~(1 << com1b0) & ~(1 << wgm11) & ~(1 << wgm10);

	TCCR1B &= ~(1 << wgm13) &~(1 << wgm12) & ~(1 << icnc1) & ~( 1 << ices1) &
			  ~(1 << cs12) & ~(1 << cs10);
	
	TCNT1L = 0x0000;
	TCNT1H = 0x0000;

	EICRA |= (1 << ISC00);
	EICRA &= ~(1 << ISC01);

	EIMSK |= (1 << INT0);
	EIFR |= ( 1 << INTF0); 

	turnOffTimer();

	return;
}

void turnOffTimer(){

	TCCR1B &= ~(1 << cs12) & ~( 1 << cs11) 
			& ~(1 << cs10);	
	return;
}

void turnOnTimer(){

	TCCR1B &= ~(1 << cs12) & ~( 1 << cs11); 
	TCCR1B |= (1 << cs10);

	return;
}

void trigger(){
	cli(); // Turn off interrupts while sending the pulse

	// From Datasheet:
	// Send a 10us pulse of the Trigger to send out an 8 cycle burst
	// of ultrasound at 40kHz.
	OUTPUT_PORT |= (1<<TRIGGER);
	_delay_us(PULSE_TIME);
	OUTPUT_PORT &= ~(1<<TRIGGER);

	// Turn interrupts back on
	sei();
}

ISR(INT0_vect) {
	cli();
	if ( !(ECHO_PIN & (1 << ECHO))){
		turnOffTimer();
		time =  ((TCNT1H << 8)| TCNT1L) ;
	
	//	OUTPUT_PORT &= ~(1 << LED);
	}
	else{
		TCNT1L = 0x00;
		TCNT1H = 0x00;
		turnOnTimer();
		
//		OUTPUT_PORT |= (1 << LED);
	}	
	sei();
}
