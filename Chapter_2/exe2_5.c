#include <stdio.h>


int any(char s1[], char s2[]){

	int i = 0, ii;

	while(s1[i]){
		ii = 0;
		while(s2[ii] && s1[i] != s2[ii]) ii ++;
		if(s2[ii]) return i;
		i ++;
	}
	return -1;
}



int main(){

	char s1[] = "Miguel", s2[] = "arana";	
	
	printf("%d\n", any(s1, s2));

	return 0;
}
