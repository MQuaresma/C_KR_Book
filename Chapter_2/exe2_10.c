#include <stdio.h>

/* lower: converts upper case to lower case */
void lower(char s[]){
	int i;
	
	for(i = 0; s[i]; i ++)
		s[i] = (s[i] >= 'A' && s[i] <= 'Z') ? s[i] + 32 : s[i]; /*if-else alternative using the ?: (ternary) operator, <condition>?<true> : <false>*/
}



int main(){

	char test[] = "H3lLo";
	lower(test);
	printf("%s\n", test);
	return 0;
}	
