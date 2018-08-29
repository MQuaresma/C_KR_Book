#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXINPUT 1000
#define MAXLINES 100
#define MAXSIZE 10000


int strToInt(char *);
int getLine(char *, int);

main(int argc, char *argv[]){

    
    char *inp[MAXLINES], matrix[MAXSIZE], line[MAXINPUT], c;
    int keepL = 10, len, cL = 0, i, sp=0;

    while(--argc && **++argv == '-')
        switch(c = (*argv)[1]){
            case 'n':
                keepL = strToInt(argv[1]);
                break;
            case 'h':
                printf("Usage:\n -n no. - specify the number of lines to print\n");
                return ;
            default:
                printf("Invalid parameter\n");
                break;
        }

    while((len =getLine(line, MAXINPUT)) > 0){
        if(sp + len > MAXSIZE){
            printf("Out of space\n");
            break;
        }
        strcpy(&(matrix[sp]), line);
        inp[cL++] = &(matrix[sp]);
        sp += len+1;
    }

    i = cL;
    (keepL > i) ? i = 0 : (i -= keepL);

    while(keepL-- > 0 && i < cL)
        printf("%s\n", inp[i++]);
    

    return 0;

}
