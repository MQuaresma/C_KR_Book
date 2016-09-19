#include <stdio.h>
#define UPPER 300
#define LOWER 0

void fahr2celsius(){
	
	float c, fhar;
	int  step;

	step = 20;

	fhar = UPPER;
	printf("Farenheit to Celsius\n\n\n");
	while(fhar >= LOWER){
		c = (5.0/9.0) * (fhar - 32.0);
		printf("%3.f\t%6.1f\n", fhar, c);
		fhar -= step;
	}
	printf("\n");
}

void celsius2fhar(){

	float c, fhar;
	int  step;

	step = 20;

	c = LOWER;
	printf("Farenheit to Celsius\n\n\n");
	while(c <= UPPER){
		fhar = (9.0/5.0) * c + 32.0;
		printf("%3.f\t%6.1f\n", c, fhar);
		c += step;
	}
}

int main(){
	
	fahr2celsius();
	celsius2fhar();
	return 0;
}
