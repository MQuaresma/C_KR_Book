#include <stdio.h>
#include <string.h>

int strEnd(char *s, char *t){

    int len = strlen(t);

    while(*t) t ++;
    while(*s) s ++;

    t --;
    s --;

    while(*s -- == *t -- && --len);

    return (len == 0);
}



int main(){

    
    char s[] = "Miguelu";
    char t[] = "iguelu";

    printf("%d\n", strEnd(s, t));

    return 0;
}
