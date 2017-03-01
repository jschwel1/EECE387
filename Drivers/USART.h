#ifndef USART_H
#define USART_H

#ifndef F_CPU
#define FCPU 1000000UL
#endif

#define BAUD_RATE 9600
#define UBRR_VAL_ASYNC ((F_CPU/16)/BUAD_RATE) - 1)
#define UBRR_VAL_SYNC ((F_CPU/8)/BUAD_RATE) - 1)

// Registers and bits
// UCSR0A
#define RXC0	7	// Rx Complete flag
#define TXC0	6	// Tx Complete flag
#define UDRE0	5	// Data Reg Empty flag
#define FE0		4	// Frame Error flag
#define DOR0	3	// Data OverRun flag
#define UPE0	2	// USART Parity Error
#define U2X0	1	// Double Tx speed
#define MPCM0	0	// Multi-processor Communication Mode

// UCSR0B
#define RXCIE0	7	// Rx Complete Int. En.
#define TXCIE0	6	// Tx Complete Int. En.
#define UDRIE0	5	// UDR Int. En.
#define RXEN0	4	// Rx En
#define TXEN0	3	// Tx En
#define UCSZ02	2	// Character Size bit 2
#define RXB80	1	// Rx Receive Data bit 8 (For 9 bits)
#define TXB80	0	// Tx Tx Data bit 8 (For 9 bits)

// UCSR0C
#define UMSEL01	7	// USART mode select  
#define UMSEL00	6	//
#define UPM01	5	// Parity Mode (1:0)
#define UPM00 	4	//
#define USBS0	3	// Stop Bit Select
#define UCSZ01	2	// Character Size (1:0)
#define UCSZ00	1	
#define UPOL0	0	// Clock Polarity


// Receiving

uint8_t readBuffer(){
	return UDR0;
}


// Transmitting
void loadBuffer(uint8_t d){
	UDR0 = d;
}


#endif
