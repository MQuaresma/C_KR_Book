#include <stdio.h>


int itoa(char [], int);

main(){

    char s[100];
    int i = 120032;

    itoa(s, i);

    printf("%s\n", s);

    return 0;
}

int itoa(char s[], int i){
    int r = 0;

    if(i/10) r = itoa(s, i/10);
    s[r++] = i % 10 + '0';
    s[r] = '\0';
    return r;
}
