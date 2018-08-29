#include <stdio.h>
#include <string.h>
#define MAXLEN 1000

int getLine(char *, int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines, char *lines, int maxinput){

    int len, nlines, curPos;
    char *p, line[MAXLEN];
    
    nlines = curPos = 0;
    while((len = getLine(line, MAXLEN)) > 0)
        if(nlines>= maxlines && len+curPos > maxinput)
            return -1;
        else{
            line[len-1] = '\0';
            strcpy(lines+curPos, line);
            lineptr[nlines++] = lines+curPos;
            curPos += len;
        }
    
    return nlines;

}


/* writelines: write output lines */
void writelines(char *lineptr[], int nlines){

    int i;

    for(i = 0; i < nlines; i ++)
        printf("%s\n", lineptr[i]);

}

int getLine(char *s, int maxlen){

    char c;
    int i = 0;

    while((c=getchar()) != '\n' && c != EOF && maxlen > i)
        *s ++ = c;

    *s = '\0';

    return i;
}
