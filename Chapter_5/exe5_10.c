#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXOP 100


main(int argc, char *argv[]){

    int operands[MAXOP], i, j = 0;
    char operators[50], inputBuf[10];

    if(argc <= 1) return -1;

    while(isdigit((*++argv)[0])){
        --argc;
        i = 0;
        operands[j] = 0;
        while((*++argv)[i]){
            operands[j] += operands[j] * 10 + ((*argv)[i] - '0');
            i ++;
        }
        j ++;
    }
    if(argc < 0){
        printf("No operators provided \n");
        return -1;
    }


}
