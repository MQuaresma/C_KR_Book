#include <stdio.h>
#include <string.h>

void reverse(char s[]){

    char c;
    int i, j;

    for(i = 0, j = strlen(s)-1; i<j; i ++, j --){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}


void itoa(int n, char *s, int width){
    char *safe = s;
    int sign;

    if((sign = n) < 0) n = -n;

    do{
        *s = (n%10) + '0', s ++;
        width --;
    }while(n/=10);

    if(sign < 0){
        *s = '-', s ++;
        width --;
    }

    while((width--) > 0){
        *s = ' ', s ++;
        width --;
    }
    *s = '\0';
    reverse(safe);
}

int main(){

    char s[100];
    
    itoa(-12, s, 4);
    printf("%s\n", s);
    return 0;
}