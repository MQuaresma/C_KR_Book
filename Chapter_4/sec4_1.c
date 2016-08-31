#include <stdio.h>
#define MAXLINE 100 /* max input length */


int getLine(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";


/* find all lines matching pattern */
main(){
	
	char line[MAXLINE];
	int found = 0;
	
	while(getLine(line, MAXLINE)){
		if(strindex(line, pattern) >= 0){
			printf("%s\n", line);
			found ++;
		}
	}
	return found;
}


/* getline: get line into s, return lenght */
int getLine(char s[], int max){

	int i = 0;
	char c;
	
	while(--max > 0 && ((c = getchar()) != EOF && c != '\n')) s[i++] = c;  
	
	s[i] = '\0';
	
	return i;
}


/* strindex: searches for searchfor in source and returns the index of searchfor in source */
int strindex(char source[], char searchfor[]){

	int i, j;
	
	for(i = 0; source[i]; i ++){
		j = 0;
		while(source[i+j] == searchfor[j] && searchfor[j]) j ++;	
		if(j && !(searchfor[j])) return i;	
	}
	return -1;
}
