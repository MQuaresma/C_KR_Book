#include <stdio.h>

int getLine(char *s, int len){

    register int i = 0, c;

    for(i = 0; i < len - 1 && (c = getchar()) != '\n' && c != EOF; i ++)
        *s ++ = c;

    *s = '\0';
    return i;
}

char *strStr(char *s, char *t){

    char *auxS;
    char *auxT = t;

    while(*s){
        auxS = s;
        t = auxT;
        while(*s  == *t && *t ++ && *s ++);
        if(!*t) return auxS;
        s = auxS+1;  
    }

    return NULL;
}
