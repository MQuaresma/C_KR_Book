#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdlib.h>

/* Prints value ranges for char, short, int, long, both signed and unsigned */

/* power: Calculates the result of elevating a base to a certain exponent, both negative and positive */
float power(float base, float exp){

	float r = 1;
	if(exp < 0) r = 1/power(base, -exp);
	else{
		while(exp){ 
			r *= base;
			exp --;
		}
	}

	return r;
}


int main(){ 
	
	unsigned int max_Uint, max_Uchar;
	int max_char, min_char, max_int, min_int;
	unsigned short min_Ushort, max_Ushort;
	short max_short, min_short;
	unsigned long max_Ulong;
	long max_long, min_long;
	char choice;

	max_char = (int) power(2, 7)-1;
	min_char = - ((int) power(2, 7));
	max_Uchar = (int) power(2, 8)-1;	
	max_short = (int) power(2, 15)- 1;
	min_short = -((int) power(2, 15));
	max_Ushort = (int) power(2, 16) -1;
	max_int = (int) power(2, 31) - 1; 
	min_int = -((int) power(2, 31));
	max_Uint = (unsigned int) power(2, 32);//TODO: not calculated correctly
	max_long = (long) power(2, 63) - 1; 	
	min_long = -((long) power(2, 63));
	max_Ulong = (unsigned long) pow(2, 64);

	
	printf("Which range do you want to check? \n");
	printf("Char(c) \t Short(s) \t Int(i) \t Long(l) \n");
	scanf("%c", &choice);
	switch(choice){
		case 'c': printf("Signed [%d, %d]\nUnsigned [0, %d]\n", SCHAR_MIN, SCHAR_MAX, UCHAR_MAX);
			break;

		default: printf("%d,%d \t %d,%d \t %d,%d \t %ld,%ld\n", SCHAR_MIN, SCHAR_MAX, SHRT_MIN, SHRT_MAX, INT_MIN, INT_MAX, LONG_MIN, LONG_MAX);
	}
	
	return 0;
}
