#include <stdio.h>

int main(){

	int c; 

	while((c = getchar())!= EOF){
		//putchar(c);
		c = getchar();
	}
	printf("%d\n", getchar() == EOF);
	printf("%d\n", EOF);
}
