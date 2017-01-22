#include <stdio.h>
#define N 5
#define MAX_LEN 20


void getInput(char *input){
    int i = 0;

    while(i < MAX_LEN-1) input[i++] = getchar();
    input[i] = '\0';

}

void foldInput(char *input){
    int i = 0, iF;

    while(input[i]){
        iF = 0;
        while(iF < N && input[i]){
            if(input[i] == '\n'){
                iF = 0;
                putchar(input[i]);
            }else{
                iF ++;
                putchar(input[i]);
            }
            i ++;
        }
        putchar('\n');
    }
}



int main(){

    char input[MAX_LEN];


    getInput(input);
    foldInput(input);

    return 0;
}
