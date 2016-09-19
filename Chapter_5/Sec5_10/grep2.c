#include <stdio.h>
#include <string.h>
#define MAXLINE 100

int getLine(char *line, int max);

/* find: print lines that match pattern from 1st arg */
main(int argc, char *argv[]){

    char line[MAXLINE];
    long lineno = 0;
    int found = 0, c, except = 0, number = 0;


    while(--argc > 0 && (*++argv)[0] == '-')
        while(c = *++argv[0])
            switch(c){
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("Illegal option %c \n", c);
                    argc = 0;
                    found = -1;
                    break;
            }
    if(argc != 1)
        printf("Usage: find -x -n pattern\n");
    else
        while(getLine(line, MAXLINE) > 0){
            lineno ++;
            if((strstr(line, *argv) != NULL) != except){
                (number)? printf("%ld:%s\n", lineno, line): printf("%s\n", line);
                found ++;
            }
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
