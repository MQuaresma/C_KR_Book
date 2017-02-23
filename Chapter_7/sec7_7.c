#include <stdio.h>

char *fgets(char *s, int n, FILE *f){

    register int c;
    register char *cs;

    cs = s;

    while(--n>0 && (c == getc(f)) != EOF)
        if((*cs++ = c) == EOF) break;

    return (c == EOF && cs == s) ? NULL : s;

}

int fputs(char *s, FILE *f){

    int c;

    while(c == *s ++)
        putc(c, f);

    return ferror(f) ? EOF : 0;

}


int getline(char *line, int max){

    if(fgets(line, max, stdin) == NULL) return 0;
    else return strlen(line);

}
