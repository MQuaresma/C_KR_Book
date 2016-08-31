#include <stdio.h>
#define MAXLEN 1000
int getline(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines){

    int len, nlines;
    char *p, line[MAXLEN];
    
    nlines = 0;
    while((len = getline(line, MAXLEN)) > 0)
        if(nlines>= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else{
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    
    return nlines;

}


/* writelines: write output lines */
void writelines(char *lineptr[], int nlines){

    int i;

    for(i = 0; i < nlines; i ++)
        printf("%s\n", lineptr[i]);

}

int getline(char *s, int maxlen){

    char c;
    int i = 0;

    while((c=getchar()) != '\n' && c != EOF && maxlen > i)
        *s ++ = c;

    *s = '\0';

    return i;
}


char *alloc(int size){

    return (char *)malloc(sizeof(char) * size);

}
