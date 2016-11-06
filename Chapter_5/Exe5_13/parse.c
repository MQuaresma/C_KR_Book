#include <stdio.h>
#include <ctype.h>



int strToInt(char *s){

    int value;
    
    for(value = 0; isdigit(*s); s ++)
        value = value * 10 + (*s -'0');

    return value;
}


int getLine(char *s, int iLength){

    int i = 0, c;

    while(i < iLength-1 && (c = getchar()) != EOF && c!= '\n'){
       *s ++ = c;
        i ++;
    }

    *s = '\0';

    return i;
}