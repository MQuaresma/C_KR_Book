#include <stdio.h>

int main(){
	char c;
	long b, t, n;
	b = t = n = 0;

	while((c = getchar()) != EOF){
		if(c == ' ')
			b ++;
		else if(c == '\t')
			t ++;
		else if(c == '\n')
			n ++;
	}
	
	printf("Blanks: %ld\n", b);
	printf("Tabs: %ld\n", t);
	printf("Lines: %ld\n", n);
	return 0;
}
