#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>

// ADMUX -> ADC Mux selection register
#define refs1 7
#define refs0 6
#define adlar 5
#define mux3 3
#define mux2 2
#define mux1 1
#define mux0 0

// ADCSRA -> ADC Control Status Register
#define aden 7
#define adsc 6
#define adate 5
#define adif 4
#define adie 3
#define adps2 2
#define adps1 1
#define adps0 0

// ADCSRB -> ADC Control & Status Register B
#define acme 6
#define adts2 2
#define adts1 1
#define adts0 0

// DIDRO -> Digital Input Disable Register 0
#define adc5d 5
#define adc4d 4
#define adc3d 3
#define adc2d 2
#define adc1d 1
#define adc0d 0
#define adc_used 0

// Output stuff
#define LED_OUT PORTB
#define LED 6
#define LED_DDR DDRB
#define LED_DDR_MASK 0x40
#define LED_MASK 0x40

#define V_REF 3.3
#define V_THRESH 2.5
#define ADC_THRESH ((V_THRESH/V_REF)*1024)



int main(){
	/*	Using: ADC0 @ Pin 23
		ADMUX = 010x0000
		ADCSRA = 111x1011
		ADCSRB = xxxxx000
		DIDR0 = &~(1<<adc_used)
	*/	
	
	uint16_t adc_result;

	// set up ADC
	ADMUX &= ~(1<<refs1) & ~(1<<adlar) & ~(1<<mux3) & ~(1<<mux2)
			 & ~(1<<mux1) & ~(1<<mux0);
	ADMUX |= (1<<refs0);
	
	ADCSRA &= ~(1<<adps2);
	ADCSRA |=  (1<<adps1) | (1<<adate)| (1<<adps0);

	
	ADCSRB &= ~(1<<adts2) & ~(1<<adts1) & ~(1<<adts0);

	DIDR0 |= (1<<adc5d) | (1<<adc4d) | (1<<adc3d) | 
			 (1<<adc2d) | (1<<adc1d) | (1<<adc0d);	
	DIDR0 &= ~(1<<adc_used);
	
	LED_DDR = LED_DDR_MASK;
	
	// Start ADC
	ADCSRA |= (1<<aden) | (1<<adsc);
	
	while(1){
		adc_result = (ADCL | (ADCH<<8));
		
		if (adc_result > ADC_THRESH) {
			LED_OUT |= (1<<LED);
		}
		else { 
			LED_OUT &= ~(1<<LED);
		}
		_delay_ms(10);
	}

	
	return 0;
}
