#include <stdio.h>
#define MAX_S 1000
#define MAX_E 1000


int getLine(char *s){
	int i = 0; 
	char c;

	while((c=getchar()) != '\n' && i < MAX_S) s[i++] = c;

	s[i] = '\0';
	return i;
}


void strCpy(char *src, char *dest){
	int i = 0;

	while(src[i] && i < MAX_S) dest[i++] = src[i];	
	
	dest[i] = '\0';
}

void removeTrailing(char *src, int size){

	size --;
	if(size > 0){
		while(src[size] == ' ' || src[size] == '\t') size --;
		size ++;
		src[size] = '\0';
	}
}


void reverse(char *s){
	int i, ii;
	char c; 

	for(i = 0; s[i]; i ++);

	i --;
	
	for(ii = 0; ii < i; ii ++, i --){
		c = s[i];
		s[i] = s[ii];
		s[ii] = c;
	}	
}


int main(){

/*	int length = 1, pos = 0, i = 0;
	char s[MAX_S] = "";
	char sM[MAX_E][MAX_S];
	
	while(length != 0 && pos < MAX_E){
		length = getLine(s);
		if(length > 80){
			strCpy(s, sM[pos]);	
			pos ++;
		}
	}
	while(i < pos){
		printf("%s\n", sM[i]);
		i ++;
	}

*/
}
