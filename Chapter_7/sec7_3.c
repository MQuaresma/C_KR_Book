#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>

void minprintf(char *, ... );

main(){

    char *test = "Current day is %d\n";

    minprintf(test, 12);

}


/* Problem: how many arguments are we recieving? The header stdarg has macros to run through the arguments list */
void minprintf(char *fmt, ... ){

    va_list v;          // variable to refer to each of the arguments in turn
    char *p, *sval;
    int ival;
    double fval;
    
    va_start(v, fmt);   // macro that initializes the variable, pointing it to the unnamed first argument

    for(p = fmt; *p; p ++){
        if(*p != '%'){
            putchar(*p);
            continue;
        }
        switch(*++p){
            case 'd':
                ival = va_arg(v, int);
                printf("%d", ival);
                break;
            case 'f':
                fval = va_arg(v, double);
                printf("%f", fval);
                break;
            case 's':
                sval = va_arg(v, char*);
                while(*sval) putchar(*sval ++);
                break;
            default:
                putchar(*p);
                break;
        }
    }

    va_end(v);
}
