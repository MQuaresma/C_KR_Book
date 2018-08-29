#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>
#define WPF "%*.*f"
#define WF "%*.f"
#define PF "%.*f"

void minprintf(char *, ... );

main(){

    char *test = "Current day is %d\n";

    minprintf(test, 12);

}


/* minprintf: user-implementation of printf */
void minprintf(char *fmt, ... ){

    va_list v;          // variable to refer to each of the arguments in turn
    char *p, *sval;
    int ival, width, precision, finished;
    double fval;
    
    va_start(v, fmt);   // macro that initializes the variable, pointing it to the unnamed first argument

    for(p = fmt; *p; p ++){
        if(*p != '%'){
            putchar(*p);
            continue;
        }
        finished = 0;
        width = -1;
        precision = -1;
        while(!finished && *p){
            switch(*++p){
                case 'd':
                    ival = va_arg(v, int);
                    if(width >= 1)
                        printf("%*d", width, ival);
                    else 
                        printf("%d", ival);
                    finished = 1;
                    break;
                case 'f':
                    fval = va_arg(v, double);
                    if(width >= 1) 
                        (precision >= 1) ? printf("%*.*f", width, precision, fval) : printf("%*.f", width, fval);
                    else 
                        (precision >= 1) ? printf("%.*f", precision, fval) : printf("%f", fval);
                    finished = 1;
                    break;
                case 's':
                    sval = va_arg(v, char*);
                    while(*sval) putchar(*sval ++);
                    finished = 1;
                    break;
                case (isdigit(*p)):
                    width = 0;
                    while(*p && isdigit(*p)){ 
                        width = width*10 + (*p-'0');
                        p ++;
                    }
                    break;
                case '.':
                    precision = 0;
                    p ++;
                    while(*p && isdigit(*p)){ 
                        precision = precision*10 + (*p-'0');
                        p ++;
                    }
                    break;
                default:
                    putchar(*p);
                    finished = 1;
                    break;
            }
        }
        if(!finished) puts("Invalid input format. Aborting...");
    }

    va_end(v);
}
