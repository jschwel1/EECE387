#include <stdio.h>

int main(int argc, char ** argv){
	int x = 12;
	int y = 10;
	int t;

	// do the math part
	y = x+2;
	t = y;
	x = t;

	// output the variable values
	printf("t = %d\n", t);
	printf("x = %d\n", x);
	printf("y = %d\n", y);

	return 0;
}
