#include <stdio.h>
#include <string.h>
#define MAXINPUT 1000
#define LINES 100000

static int sp = 0;
char lines[LINES];

int getLine(char *s, int maxinput);
int readline(char *lineptr[], int nlines){

    char input[MAXINPUT]; 
    int i = 0, j;

    while(sp < LINES && i < nlines && (j = getLine(input, MAXINPUT))){
        if(j+sp >= LINES){
            printf("Not enough space\n");
            return -1;
        }
        strcpy(lines+sp, input);
        lineptr[i ++] = lines+sp;
        sp = sp+1+j;
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


void resetCounters(void){
	sp = 0;
	
}
