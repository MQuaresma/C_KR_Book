#include <stdio.h>



void strCat(char *s, char *t){

    while(*++ s);


    while((*s ++ = *t ++));

}



int main(){


    char s[] = "Miguel", t[] = " Quaresma";


    strCat(s, t);


    printf("%s\n", s);

    return 0;
}
