#include <stdio.h>
#include <string.h>


void squeeze(char s1[], char s2[]){

	int i, ii, rI = 0;
	for(i = 0; s1[i]; i ++){
		ii = 0;
		while(s2[ii] && s2[ii] != s1[i]) ii ++;
		if(!s2[ii]) s1[rI++] = s1[i];
	}
	s1[rI] = '\0';
}

main(){

	char s1[] = "Teste", s2[] = "Teste";
	squeeze(s1, s2);
	printf("%s\n", s1);
	return 0;
}
