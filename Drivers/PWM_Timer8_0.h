#ifndef PWM_TIMER8_0_H
#define PWM_TIMER8_0_H

// if the CPU clk speed has not yet been defined, do it
#ifndef F_CPU
#define F_CPU 1000000 UL
#endif

#include <avr/io.h>

#define COM0A1 7
#define COM0A0 6
#define COM0B1 5
#define COM0B0 4

#define WGM00 0
#define WGM01 1
#define WGM02 3

#define CS00 0
#define CS01 1
#define CS02 2



void setTimer0(uint8_t n){
	TCNT0 = n;
}
void clearTimer0(){
	setTimer(0x00);	
}

uint8_t getTime0(){
	return TCNT0;
}

void setCompRegA0(uint8_t n){
	OCR0A = n;
}
void setCompRegB0(uint8_t n){
	OCR0B = n;
}
void enableA0(uint8_t m){
	if (m == 0){
		TCCR0A &= ~(1 << COM0A1) & ~(1 << COM0A0);
	}
	else if (m == 1){
		TCCR0A &= ~(1 << COM0A1);
		TCCR0A |= (1 << COM0A0);
	}
	else if (m == 2) {
		TCCR0A &= ~(1 << COM0A0);
		TCCR0A |= (1 << COM0A1);
	}
	else {
		TCCR0A |= (1 << COM0A1) | (1 << COM0A0);
	}
}

void enableB0(uint8_t m){
	if (m == 0){
		TCCR0A &= ~(1 << COM0B1) & ~(1 << COM0B0);
	}
	else if (m == 1){
		TCCR0A &= ~(1 << COM0B1);
		TCCR0A |= (1 << COM0B0);
	}
	else if (m == 2) {
		TCCR0A &= ~(1 << COM0B0);
		TCCR0A |= (1 << COM0B1);
	}
	else {
		TCCR0A |= (1 << COM0B1) | (1 << COM0B0);
	}
}


void setWGM0(uint8_t mode){
	if (mode == 0){
		TCCR0B &= ~(1 << WGM02);
		TCCR0A &= ~(1 << WGM01) & ~(1 << WGM00);
	}
	else if (mode == 1){
		TCCR0B &= ~(1 << WGM02);
		TCCR0A |= (1 << WGM00);
		TCCR0A &= ~(1 << WGM01);
	}
	else if (mode == 2){
		TCCR0B &= ~(1 << WGM02);
		TCCR0A |= (1 << WGM01);
		TCCR0A &= ~(1 << WGM00);
	}
	else if (mode == 3){
		TCCR0B &= ~(1 << WGM02);
		TCCR0A &= ~(1 << WGM01) & ~(1 << WGM00);
	}
	else if (mode == 4){
		TCCR0B |= (1 << WGM02);
		TCCR0A |= (1 << WGM01) | (1 << WGM00);
	}
	else if (mode == 5){
		TCCR0B |= (1 << WGM02);
		TCCR0A |= (1 << WGM00);
		TCCR0A &= ~(1 << WGM01);
	}
	else if (mode == 6){
		TCCR0B |= (1 << WGM02);
		TCCR0A |= (1 << WGM01);
		TCCR0A &= ~(1 << WGM00);
	}
	else if (mode == 7){
		TCCR0B |= (1 << WGM02);
		TCCR0A |= (1 << WGM01) | (1 << WGM00);
	}

}

void setPrescale0(uint8_t ps){
	if (ps == 0){
		TCCR0A &= ~(1 << CS02) & ~(1 << CS01) & ~(1 << CS00);
	}
	else if (ps == 1){
		TCCR0B |= (1 << CS00);
		TCCR0A &= ~(1 << CS02) & ~(1 << CS01);
	}
	else if (ps == 2){
		TCCR0B |= (1 << CS01);
		TCCR0A &= ~(1 << CS02) & ~(1 << CS00);
	}
	else if (ps == 3){
		TCCR0B |= (1 << CS01) | (1 << CS00);
		TCCR0A &= ~(1 << CS02);
	}
	else if (ps == 4){
		TCCR0B |= (1 << CS02);
		TCCR0A &= ~(1 << CS01) & ~(1 << CS00);
	}
	else if (ps == 5){
		TCCR0B |= (1 << CS02) | (1 << CS00);
		TCCR0A &= ~(1 << CS01);
	}
	else if (ps == 6){
		TCCR0B |= (1 << CS02) | (1 << CS01);
		TCCR0A &= ~(1 << CS00);
	}
	else if (ps == 7){
		TCCR0B |= (1 << CS02) | (1 << CS01) | (1 << CS00);
	}

}



#endif
