#include <ctype.h>

int getch(void);
void ungetch(int);


/* getint: get next integer from input into *pn */
int getin(int *pn){

    int c, sign, cBk;

    while(isspace(c=getch()));

    if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
        ungetch(c);
        return 0;
    }
    
    cBk = c; 
    if((cBk == '+' || cBk == '-') && !isdigit(c = getch())){
        ungetch(cBk);
        ungetch(c);
    }

    sign= (c=='-')?-1 : 1;
    if(c == '+' || c == '-') c = getch();

    for(*pn = 0; isidigit(c); c = getch())
        *pn = 10 * (*pn) + (c - '0');
        
    *pn *= sign;

    if(c!= EOF)
        ungetch(c);
    return c;

}