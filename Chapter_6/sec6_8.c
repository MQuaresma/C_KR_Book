#include <stdio.h>
#include "sec6_8.h"

main(){

    int utype;    // variable used to keep track of the current type of the union
    union u_test u;
    Symbol t;
    
    utype = t.utype = INT;
    u.i = t.u.i = 1;

    printf("Union int: %d \t %d\n", u.i, t.u.i);

    utype = t.utype = FLOAT;
    u.f = t.u.f = 1;

    printf("Union float: %.2f \t %.2f\n", u.f, t.u.f);

    utype = t.utype = CHAR;
    u.c = t.u.c = '3';

    printf("Union char: %c \t %c\n", u.c, t.u.c);

    return 0;
}
