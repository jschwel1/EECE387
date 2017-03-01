#include <stdio.h>
#include <stdlib.h>



int main(int argc, char ** argv){
	char min, sec;
	uint16_t ms;


	min = 0;
	sec = 0;
	ms = 0;

	while (1){
		delay(1);
		ms++;
		if (ms == 1000){
			ms = 0;
			sec++;
		}
		if (sec == 60){
			sec = 0;
			min++;
		}
		printf("%2d:%2d:%2d\n", min, sec, ms);
	}
	
	return 0;
}

