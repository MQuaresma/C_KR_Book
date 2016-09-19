#include <stdio.h>


int bitcount(unsigned int x){
	int r;

	for(r = 0; x; x & 1){
		if(x & 1)
			r ++;
	}

	return r;
}



int main(){

	int x = 3; 
	
	printf("%d\n", bitcount(x));
	return 0;
}
