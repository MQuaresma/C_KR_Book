#include <stdio.h>
#define swapF(t, a, b) t temp = a; a = b; b = temp;


int main(){

    int a = 3;
    int b = 4;

    swapF(int, a, b);


    printf("%d \t %d \n", a, b);
}
