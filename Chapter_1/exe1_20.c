#include <stdio.h>
#define N 4
#define MAX_INPUT 10000


void detab(char *input){

    int count = 0, i;
    char c;

    while((c = getchar()) != '\n' && count < MAX_INPUT-1){
       if(c == '\t'){
           for(i = 0; i < N && (count+i) < MAX_INPUT-1; i ++) input[count + i] = '.';
           count += i;
       }
       else input[count ++] = c; 
    }
    input[count] = '\0';
    printf("%s\n", input);
}

int main(){

    char input [MAX_INPUT];

    detab(input);    

    return 0;
}