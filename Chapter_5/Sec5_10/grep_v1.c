#include <stdio.h>
#define MAXLINE 1000

int getLine(char *s, int max);
char *strStr(char *p, char *s);

/* find: print lines that contain the pattern in arg 1 */
main(int argc, char *argv[]){

    char line[MAXLINE];
    int found = 0;

    if(argc != 2)
        printf("Insuficient parameters, check usage.\n");

    else
        while(getLine(line, MAXLINE) > 0)
            if(strStr(line, argv[1])){
                printf("%s\n", line);
                found ++;
            }
    return found;

}