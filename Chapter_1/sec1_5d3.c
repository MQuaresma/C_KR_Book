#include <stdio.h>

int main(){
	long nc = 0;
	char c;

	while((c = getchar()) != EOF)
		if(c == '\n') 
			++ nc;
	printf("%ld", nc);

	return 0;
}
