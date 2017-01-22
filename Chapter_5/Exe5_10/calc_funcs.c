#include <stdio.h>
#include <ctype.h>
#define STACKSZ 1000

float powf(float, float);
static float stack[STACKSZ];
static int sp = 0;

/* strToFlt: converts input streams to float */
float strToFlt(char *s){

    float value;
    int sign = 1, dec, exp, power=1;

    if(*s == '+' || *s == '-'){
        sign = (*s == '-') ? -1 : 1;
        s ++;
    }
 
    for(value = 0; isdigit(*s) && *s; s ++)
        value = value*10 + (*s - '0');

    if(*s == '.') s ++;
    for(dec = 1; isdigit(*s); s ++, dec *= 10)
        value = value*10 + (*s - '0');

    if(*s == '^'){ 
        s ++;
        for(power = 0; isdigit(*s) && *s; s ++)
            power = power*10 + (*s - '0');
    }
        
    
    if(*s == 'e' || *s == 'E') s ++;
    for(exp = 0; isdigit(*s) && *s; s ++)
        exp = exp*10 + (*s - '0');


    return powf(sign*(value/dec), power) * powf(10,exp) ;
}

char type(char *s){

    if((*s == '-' || *s == '+' || *s == '/' || *s == 'x') && !isdigit(*(s+1)))
        return *s;
    else if(((*s == '-' || *s == '+') && isdigit(*(s+1))) || isdigit(*s))
        return 'n';
    else if(*s == 'e')
        return *s;
    else return 'E';

}

void push(float x){

    if(sp == STACKSZ) printf("Full stack\n");
    else stack[sp ++] = x;

}


float pop(){

    if(!sp){
        printf("Stack Empty");
        return -1;
    }
    else
        return stack[--sp];
}

float powf(float base, float exp){

   float result = 1;     

   while(exp --)
       result *= base;

   return result;
}
