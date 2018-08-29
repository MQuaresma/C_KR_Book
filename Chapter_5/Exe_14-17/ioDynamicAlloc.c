#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXINPUT 1000
#define LINES 100000

int getLine(char *s, int maxinput);
int readline(char *lineptr[], int nlines){

    char input[MAXINPUT], *p; 
    int i = 0, j;

    while(i < nlines && (j = getLine(input, MAXINPUT))){
        p = (char *)malloc(sizeof(char) * (j+1));
		if(*p == NULL){
			printf("Not enough space");
			return -1;
		}
        strcpy(p, input);
        *(p + j) = '\0';
        lineptr[i ++] = p;
    }

    return i;
}

void writeline(char *lineptr[], int nlines){

    for(int i = 0; i < nlines; i ++)
        printf("%s\n", lineptr[i]);

}

int getLine(char *s, int maxinput){

    int i=0, c;

    while((c=getchar())!=EOF && c != '\n' && ++i<maxinput)
        *s ++ = c;

    *s = '\0';
    return i;

}