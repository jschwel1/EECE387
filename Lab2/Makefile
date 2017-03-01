CCARGS = -mmcu=## -DF_CPU=1000000UL -Os

default: test

test: lab2.c 
	avr-gcc -g -Wall -mmcu=atmega328 -O1 lab2.c -o lab2

program: test
	avrdude -c buspirate -P /dev/buspirate -p atmega328 
	avrdude -c buspirate -P /dev/buspirate -p atmega328 -U flash:w:lab2
clean:
	-rm programming_demo
