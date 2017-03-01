#ifndef TIMER1_H
#define TIMER1_H

// TCCR0A
#define COM0A1 7
#define COM0A0 6
#define COM0B1 5
#define COM0B0 4
#define WGM01 1
#define WGM00 0




void setCompOutputModeA(uint8_t mode){
	switch(mode){
		case 0:
			TCCR0A &= ~(1 << COMOA1) & ~(1 << COM0A0)
			break;
		case 1:
			TCCROA &= ~(1 << COM0A0);
			TCCROA |= (1 << COM0A1);
			break;
		case 2:
			TCCROA &= ~(1 << COM0A1);
			TCCROA |= (1 << COM0A0);
			break;
		case 3:
			TCCR0A |= (1 << COM0A1) | (1 << COM0A0);
			break;	
	}
}


void setCompOutputModeB(uint8_t mode){
	switch(mode){
		case 0:
			TCCR0A &= ~(1 << COMOB1) & ~(1 << COM0B0)
			break;
		case 1:
			TCCROA &= ~(1 << COM0B0);
			TCCROA |= (1 << COM0B1);
			break;
		case 2:
			TCCROA &= ~(1 << COM0B1);
			TCCROA |= (1 << COM0B0);
			break;
		case 3:
			TCCR0A |= (1 << COM0B1) | (1 << COM0B0);
			break;	
	}
}




#endif
