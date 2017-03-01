
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



