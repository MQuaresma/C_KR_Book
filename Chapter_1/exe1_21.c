#include <stdio.h>
#define MAX_INPUT 10000
#define N 4

void entab(char *input){

    int i, cSp;

    for(i = 0; i < MAX_INPUT-1; i ++){
        cSp = 0;
        while((c = getchar()) == ' ' && i+cSp < MAX_INPUT) cSp ++;
        if(cSp){
            
        }
        else input[i] = c;
    }
    input[i] = '\0';

    printf("%s")
}


int main(){

    char input[MAX_INPUT];

    entab(input);

    return 0;
}


