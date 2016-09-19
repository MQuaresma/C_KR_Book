#include <stdio.h>
#define MAXLINE 1000


int getLine(char s[], int max);
int strindex(char source[], char patter[]);

char pattern[] = "ould";

/* find all lines matching pattern */
main(){

	char line[MAXLINE];
	int found = 0;

	while(getLine(line, MAXLINE) > 0){
		if(strindex(line, pattern) >= 0){
			printf("%s\n", line);
			found ++;	
		}
	}

	return found;
}

/* strindex: searches for searchfor in source and returns the rightmost index of searchfor in source */
int strindex(char source[], char patter[]){

	int i, j, r = -1;

	for(i = 0; source[i]; i ++){
		j = 0;
		while(source[i+j] == patter[j] && patter[j]) j ++;
		if(j && !patter[j]) r = i; /* the last index to be saved is the answer */
	}
	return r;
}

/* getline: get line into s, return lenght */
int getLine(char s[], int max){

	int i = 0;
	char c;

	while(--max > 0 && ((c=getchar()) != EOF && c != '\n')) s[i++] = c;
	
	s[i] = '\0';

	return i;
}
