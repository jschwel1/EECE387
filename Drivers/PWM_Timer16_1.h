#ifndef PWM_TIMER16_1_H
#define PWM_TIMER16_1_H

#ifndef F_CPU
#define F_CPU 1000000 UL
#endif

#include <avr/io.h>

//TCCR1A
#define COM1A1 7
#define COM1A0 6
#define COM1B1 5
#define COM1B0 4

#define WGM11 1
#define WGM10 0

//TCCR1B
#define ICNC1 7
#define ICES1 6

#define WGM13 4
#define WGM12 3
#define CS12 2
#define CS11 1
#define CS10 0

void setTimer1(uint16_t n){
	TCNT1H = n&0xFF00;
	TCNT1L = n&0x00FF;
}

void clearTimer1(){
	setTimer1(0x0000);	
}

uint16_t getTime1(){
	return ((TCNT1H << 8)| TCNT1L);
}

void setCompRegA(uint16_t n){
	OCR1AH = n&0xFF00;
	OCR1AL = n&0x00FF;
}
void setCompRegB(uint16_t n){
	OCR1BH = n&0xFF00;
	OCR1BL = n&0x00FF;
}

void enableTCCR1A( uint16_t mode){

	if(mode ==0){
		TCCR1A &= ~(1 << COM1A1) & ~(1 << COM1A0);
	}

	else if(mode == 1){
		TCCR1A &= ~(1 << COM1A1);
		TCCR1A |= (1 << COM1A0);
	} 
	
	else if(mode == 2){
		TCCR1A &= ~(1 << COM1A0);
		TCCR1A |= (1 << COM1A1);
	}

	else{
		TCCR1A |= (1 << COM1A1) | (1 << COM1A0);		
	}
	return;
}

void enableTCCR1B( uint16_t mode){

	if(mode ==0){
		TCCR1B &= ~(1 << COM1B1) & ~(1 << COM1A0);
	}

	else if(mode == 1){
		TCCR1B &= ~(1 << COM1B1);
		TCCR1B |= (1 << COM1B0);
	} 
	
	else if(mode == 2){
		TCCR1B &= ~(1 << COM1B0);
		TCCR1B |= (1 << COM1B1);
	}

	else{
		TCCR1B |= (1 << COM1B1) | (1 << COM1B0);		
	}
	return;
}

void setWGM1(uint16_t mode){
	
	if(mode ==0){
		TCCR1A &= ~(1 << WGM11) & ~(1 << WGM10);
		TCCR1B &= ~(1 << WGM13) & ~(1 << WGM12);
	}

	else if(mode == 1){
		TCCR1A |=  (1 << WGM10);
		TCCR1A &= ~(1 << WGM11);
		TCCR1B &= ~(1 << WGM13) & ~(1 << WGM12);
	}
	
	else if(mode == 2){
		TCCR1A |=  (1 << WGM11);
		TCCR1A &= ~(1 << WGM10);
		TCCR1B &= ~(1 << WGM13) & ~(1 << WGM12);
	}	

	else if(mode == 3){
		TCCR1A |=  (1 << WGM11)| (1 << WGM10);
		TCCR1B &= ~(1 << WGM13) & ~(1 << WGM12);
	}

	else if(mode == 4){
		TCCR1A &= ~(1 << WGM11) & ~(1 << WGM10);
		TCCR1B |= (1 << WGM12);
		TCCR1B &= ~(1 << WGM13);
	}
	
	else if(mode == 5){
		TCCR1A |= (1 << WGM10);
		TCCR1A &= ~(1 << WGM11);
		TCCR1B |= (1 << WGM12);
		TCCR1B &= ~(1 << WGM13);
	}
	
	else if(mode == 6){
		TCCR1A &= ~(1 << WGM10);
		TCCR1A |= (1 << WGM11);
		TCCR1B |= (1 << WGM12);
		TCCR1B &= ~(1 << WGM13);
	}

	else if(mode == 7){
		TCCR1A |= (1 << WGM10);
		TCCR1A |= (1 << WGM11);
		TCCR1B |= (1 << WGM12);
		TCCR1B &= ~(1 << WGM13);
	}

	else if(mode == 8){
		TCCR1A &= ~(1 << WGM10);
		TCCR1A &= ~(1 << WGM11);
		TCCR1B &= ~(1 << WGM12);
		TCCR1B |= (1 << WGM13);
	}

	else if(mode == 9){
		TCCR1A |= (1 << WGM10);
		TCCR1A &= ~(1 << WGM11);
		TCCR1B &= ~(1 << WGM12);
		TCCR1B |= (1 << WGM13);
	}

	else if(mode == 10){
		TCCR1A &= ~(1 << WGM10);
		TCCR1A |= (1 << WGM11);
		TCCR1B &= ~(1 << WGM12);
		TCCR1B |= (1 << WGM13);
	}

	else if(mode == 11){
		TCCR1A |= (1 << WGM10);
		TCCR1A |= (1 << WGM11);
		TCCR1B &= ~(1 << WGM12);
		TCCR1B |= (1 << WGM13);
	}	

	else if(mode == 12){
		TCCR1A &= ~(1 << WGM10);
		TCCR1A &= ~(1 << WGM11);
		TCCR1B |= (1 << WGM12);
		TCCR1B |= (1 << WGM13);
	}

	else if(mode == 13){
		TCCR1A |= (1 << WGM10);
		TCCR1A &= ~(1 << WGM11);
		TCCR1B |= (1 << WGM12);
		TCCR1B |= (1 << WGM13);
	}

	else if(mode == 14){
		TCCR1A &= ~(1 << WGM10);
		TCCR1A |= (1 << WGM11);
		TCCR1B |= (1 << WGM12);
		TCCR1B |= (1 << WGM13);
	}
	
	else if(mode == 15){
		TCCR1A |= (1 << WGM10);
		TCCR1A |= (1 << WGM11);
		TCCR1B |= (1 << WGM12);
		TCCR1B |= (1 << WGM13);
	}

	return;
}

void setPrescale1(uint16_t ps){

	if(ps == 0){
		TCCR1B &= ~(1 << CS10);
		TCCR1B &= ~(1 << CS11);
		TCCR1B &= ~(1 << CS12);
	}

	else if(ps == 1){
		TCCR1B |= (1 << CS10);
		TCCR1B &= ~(1 << CS11);
		TCCR1B &= ~(1 << CS12);
	}

	else if(ps == 2){
		TCCR1B &= ~(1 << CS10);
		TCCR1B |= (1 << CS11);
		TCCR1B &= ~(1 << CS12);
	}

	else if(ps == 3){
		TCCR1B |= (1 << CS10);
		TCCR1B |= (1 << CS11);
		TCCR1B &= ~(1 << CS12);
	}

	else if(ps == 4){
		TCCR1B &= ~(1 << CS10);
		TCCR1B &= ~(1 << CS11);
		TCCR1B |= (1 << CS12);
	}

	else if(ps == 5){
		TCCR1B |= (1 << CS10);
		TCCR1B &= ~(1 << CS11);
		TCCR1B |= (1 << CS12);
	}

	else if(ps == 6){
		TCCR1B &= ~(1 << CS10);
		TCCR1B |= (1 << CS11);
		TCCR1B |= (1 << CS12);
	}

	else if(ps == 7){
		TCCR1B |= (1 << CS10);
		TCCR1B |= (1 << CS11);
		TCCR1B |= (1 << CS12);
	}

	return;
}

#endif
