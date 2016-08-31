#include <stdio.h>
#include "calc.h"
#define MAXVAL 100

static int sp = 0;
static double val[MAXVAL];

/* push: push f onto the value stack */ 
void push(double f){

    if(sp < MAXVAL)
        val[sp++] = f;

    else
        printf("Error: stack full, can't push\n");
    
}


/* pop: pop and return the value at the top of the stack */
double pop(void){

    if(sp > 0)
        return val[--sp];
    else{
        printf("Error: stack is empty\n");
        return 0.0;
    }
}


