
#define F_CPU 8000000UL
#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>


#define pwm_coma1 7
#define pwm_coma0 6
#define pwm_comb1 5
#define pwm_comb0 4

#define pwm_wgm0 0
#define pwm_wgm1 1
#define pwm_wgm2 3

#define pwm_cs0 0
#define pwm_cs1 1
#define pwm_cs2 2

#define DEC 0x20


int main (){

        DDRD = 0x40; //Sets OC0A and OC0B to outputs


        TCCR0A &= ~(1 << pwm_coma0);

        TCCR0A |=   (1 << pwm_coma1) | (1 << pwm_comb1)
                                | (1 << pwm_comb0) | (1 << pwm_wgm1)
                                | (1 << pwm_wgm0);  //0xB3 Insert your code here

        TCCR0A |= 0xB3;
        TCCR0B &=  ~(1 << pwm_wgm2) & ~(1 << pwm_cs2)
                                & ~(1 << pwm_cs1);              //0x31Insert your code here

        TCCR0B |=  (1 << pwm_cs0);      //0x01;Insert your code here

	OCR0A = 0xFF;
    while (OCR0A > DEC){
		OCR0A -= DEC;
		_delay_ms(1000);

    }
	
	DDRD = 0x60;
	PORTD = 0x20;

	OCR0A = 0x00;
	TCCR0A &= ~(1<<pwm_coma0);

	while(1){}

return 0;

}



/*
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

// TCCR0A
#define com0A1 7
#define com0A0 6
#define com0B1 5
#define com0B0 4
#define wgm01 1
#define wgm00 0

// TCCR0B
#define foc0A 7
#define foc0B 6
#define wgm02 3
#define cs02 2
#define cs01 1
#define cs00 0

// OUTPUT Stuff
#define LED_PORT PORTD
#define LED_PORT_DDR DDRD
#define LED 6
#define LED_MASK 0x40

// Counter
#define DECREMENT 0x20



int main(){
		
	// setup
	// Use COM0A1, with Fast PWM (inverting, clear on match)
	TCCR0A |= (1<<com0A1) | (1<<wgm01) | (1<<wgm00);
	TCCR0A &= ~(1<<com0A0) & ~(1<<com0B1) & ~(1<<com0B0);

	TCCR0B |= (1<<cs00) | (1<<wgm02);
	TCCR0B &= ~(1<<foc0A) & ~(1<<foc0B) & ~(1<<cs01) & ~(1<<cs02);
	
	LED_PORT_DDR = LED_MASK;
	LED_PORT = 0x00;

	// Compare value
	int8_t comp = 0x7E;
	OCR0A = comp;

	OCR0A = 0xFF;
	_delay_ms(1000);
	OCR0A = 0x00;
	_delay_ms(1000);
	

	while(comp > DECREMENT){
		OCR0A = comp;
		
		comp-=DECREMENT;
		_delay_ms(500);
		_delay_ms(500);
	}
	// turn off LED
	OCR0A = 0x00;
	
	while(1){}
	
	return 0;
}


*/

