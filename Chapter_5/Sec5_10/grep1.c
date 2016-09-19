#include <stdio.h>
#include <string.h>
#define MAXLINE 100

int getLine(char *line, int max);

/* find: print lines that match pattern from 1st arg */
main(int argc, char *argv[]){

    char line[MAXLINE];
    int found = 0;

    if(argc != 2)
        printf("Usage: find pattern\n");
    else
        while(getLine(line, MAXLINE) > 0)
            if(strstr(line, argv[1]) != NULL){
                printf("%s\n", line);
                found ++;
            }
    return found;
}


int getLine(char *line, int max){

    char c;
    int i = 0;

    while((c = getchar()) != '\n' && c != EOF && ++i<max)
        *line ++ = c;

    *line = '\0';

    return i;

}
