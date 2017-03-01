CCARGS = -mmcu=## -DF_CPU=1000000UL -Os
FILE  = lab5_second_try

default: test

test: $(addsuffix .c, $(FILE)) 
	@echo $(addsuffix .c, $(FILE))
	avr-gcc -g -Wall -mmcu=atmega328 -O1 $(addsuffix .c, $(FILE)) -o $(FILE)

program: test
	avrdude -c buspirate -P /dev/buspirate -p atmega328 
	avrdude -c buspirate -P /dev/buspirate -p atmega328 -U flash:w:$(FILE)
clean:
	-rm $FILE




# Bus Pirate -> AVR
# red (RESET) -> pin 1
# GND -> pin 8
# VCC -> pin 7
# orange (MOSI) -> pin 17
# brown (MISO) -> pin 18
# yellow (SCK) -> pin 19
