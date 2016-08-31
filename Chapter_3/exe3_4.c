#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

void reverse(char s[]){

    char c;
    int i, j;

    for(i = 0, j = strlen(s)-1; i<j; i ++, j --){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[]){

    int i, sign;

    if((sign = n) < 0) n = -n; /* if n is negative, invert it's sign */

    i = 0;

    do{
        s[i++] = n%10 +'0'; /* ascii code of the digit */
    }while((n/=10) > 0);    
    if(sign < 0) s[i++] = '-';  /* if n was negative put the - to represent it */
    s[i] = '\0';
    reverse(s);
}


/* itoaRevised: same as itoa but handles the case in which the input contains the largest negative number */
void itoaRevised(int n, char s[]){

    int sign = n;
    char *safe = s;

    do{
        *s = abs(n%10) + '0';
        s ++;
    }while((n/=10) != 10);

    if(sign < 0) *s = '-', s ++;
    
    *s = '\0';

    s = safe;
}


int main(){

    return 0;
}