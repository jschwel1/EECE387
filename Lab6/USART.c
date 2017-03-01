#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


#define BAUD_RATE 9600
#define FOSC 1000000 
#define MYUBRR FOSC/16/BAUD_RATE-1

#define OUTPUT_PORT PORTD
#define OUTPUT_PORT_DDR DDRD
#define OUTPUT_PORT_DDR_MASK 0xF0
#define LED 7

//Setup the timer 
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

// USART
// UCSR0A Register

// Doubles the speed of the BAUD_RATE
#define RXC0 	7
#define FE0	4 
#define DOR0	3
#define UPE0	2
#define U2X0	1 
#define MPCM0	0

// UCSR0B
#define RXCIE0 7	//Interrupt Enable
#define RXEN0 4		//Enable
#define UCSZ02 2		//Bit 2 of Size
#define RXB80 1		//9 Bits of data

// UCSR0C
#define UMSEL01	7	//USART mode select  
#define UMSEL00	6	//
#define UPM01	5	// Parity Mode
#define UPM00 	4	//
#define USBS0	3	//Stop Bit Select
#define UCSZ01	2	//Character Size
#define UCSZ00	1	
#define UPOL0	0	//Clock Polarity

volatile uint8_t data;

void setup();

int main(){
  
  cli();
  setup();
  sei();
  
  while(1){
    OCR0A = data;
  }
  
  return 0; 
}



void setup(){
  
  OUTPUT_PORT_DDR = OUTPUT_PORT_DDR_MASK;
  
//  COMA1:0 = 10 non inverting clears OC0A and sets OC0A at the BOTTOM
//  No Prescaling on CLK 
//  WGM defines Fast PWM
  
  data = 0x88;
  
  TCCR0A &= ~(1 << pwm_coma0); 
    
  TCCR0A |=   (1 << pwm_coma1) | (1 << pwm_comb1) 
	    | (1 << pwm_comb0) | (1 << pwm_wgm1) 
	    | (1 << pwm_wgm0);  //0xB3 Insert your code here
	    
  TCCR0B &=  ~(1 << pwm_wgm2) & ~(1 << pwm_cs2)
	    & ~(1 << pwm_cs1);  		//0x31Insert your code here

  TCCR0B |=  (1 << pwm_cs0);	//0x01;Insert your code here
  
// USART setup

   UCSR0A &= ~(1 << MPCM0);
   UCSR0A |= (1 << U2X0);
   UCSR0B &= ~(1 << RXB80) & ~(1 << UCSZ02);
   UCSR0B |= (1 << RXCIE0) | (1 << RXEN0);
   
   UCSR0C &= ~(1 << UMSEL01) & ~(1 << UMSEL00) & ~(1 << USBS0) & ~(1 << UPOL0);
   UCSR0C |= (1 << UPM01) | (1 << UPM00) | (1 << UCSZ00) | (1 << UCSZ01); 
   
   UBRR0H = 0;
   UBRR0L = 12; // Baud rate 9600 at 1MHz clk

 return; 
}

ISR(USART_RX_vect){
  OUTPUT_PORT |= (1 << LED);
  _delay_ms(1);
  OUTPUT_PORT = ~(1 << LED);
  
  cli();
 /*
  uint8_t err = (UCSR0A & (1 << FE0)) | (UCSR0A & (1 << DOR0)) | (UCSR0A & (1 << UPE0));
  
  if (err != 0){
   return; 
  }
  */
  data = UDR0; 
  sei();
}
