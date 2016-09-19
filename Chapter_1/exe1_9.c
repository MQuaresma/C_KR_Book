#include <stdio.h>

int main(){
	char c, nc;

	while((c = getchar()) != EOF){
		if(c != ' ') putchar(c);
		else{
			nc = getchar();
			if(c == ' ' && nc != ' ' ){
				putchar(c);
				putchar(nc);
			}
			else{ 
				putchar(c);
				while((c = getchar()) == ' ');
				putchar(c);
			}
		}
	}
	return 0;
}
