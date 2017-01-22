#include <stdio.h>

/* Demo of the way variable scope works */

int i = 2;

int main(){
    
    int i = 3;
    char c = 'c';

    if(c == 'c'){
        int i = 1;
        printf("%d\n", i);
    }

    printf("%d\n", i);

}
