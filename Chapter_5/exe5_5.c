#include <stdio.h>


void strNcpy(char *s, char *t, int n){

    while(n -- && (*s ++ = *t ++));

    if(*t) *s = '\0';

}


void strNcat(char *s, char *t, int n){

    while(*s) s ++; 


    while(n -- && (*s ++ = *t ++));

    if(*t) *s = '\0';

}

