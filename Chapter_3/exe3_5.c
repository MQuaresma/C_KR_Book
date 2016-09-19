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

/* itob: converts n to a string in the base pointed */
void itob(int n, char *s, int base){

    int sign;
    char *safe = s;

    if((sign = n) < 0) n = -n;

    do{
        *s = ((n % base) <= 9)?(n % base) + '0':'a' + (n % base)-10;
        s ++;    
    }while((n /= base) > 0);  
    
    
    (base == 16) ? ((*s) = 'x', s ++, (*s) = '0', s ++, *s = '\0' ): (*s = '\0'); /* The use of the ternary operator ?: helps to shrink the code */

    reverse(safe);
}



int main(){

    char s[100];
    
    itob(12, s, 16);
    printf("%s\n", s);
    return 0;

}