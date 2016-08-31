#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXVAL 100 /* maximum depth of val stack */
#define BUFSIZE 100
#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);
double atoF(char []);
int getch(void);
void ungetch(int);
int powerF(int, int);


/* reverse Polish calculator */
int main(){

    int type;
    double op2;
    char s[MAXOP];

    while((type = getop(s)) != EOF){
        switch(type){
            case NUMBER:
                push(atoF(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop(); 
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop(); 
                if(op2 != 0.0)
                    push(pop() / op2);
                else printf("Error, cannot divide by zero");
                break;
            case '\n':
                printf("\t.8%g\n", pop());
                break;
            default:
                printf("Error: unknown command \n");
                break;
        }
    }
    return 0;
}


int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

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

/* getop: get next operator or numeric operand */
int getop(char s[]){

    int i, c;

    while((s[0] = c = getch()) == ' ' || c == '\t');

    s[1] = '\0';
    if(!isdigit(c) && c != '.') return c; /* not a number */

    i = 0;
    if(isdigit(c))                              /* collect integer part */
        while(isdigit(s[++i] = c = getch()));

    if(c == '.')                                /* collect fraction part */
        while(isdigit(s[++i] = c = getch()));
    
    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}


char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

int getch(void){ /* get a (possibly pushed back) character */

    return (bufp > 0) ? buf[--bufp] : getchar();

}

void ungetch(int c){ /* push character back on input */

    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else buf[bufp++] = c;

}



/* atoF: converts string s to double */
double atoF(char s[]){

    double value, power, exp;
    int sign, i, expSign;

    for(i = 0; isspace(s[i]); i ++);

    sign = (s[i] == '-') ? -1 : 1;

    if(s[i] == '+' || s[i] == '-') i ++;

    for(value = 0.0; isdigit(s[i]); i ++)
        value = 10.0 * value + (s[i] - '0');
    
    if(s[i] == '.') i ++;

    for(power = 1.0; isdigit(s[i]); i ++){
        value = 10.0 * value + (s[i] - '0');
        power *= 10.0;
    }

    if(s[i] == 'e' || s[i] == 'E') i ++;

    expSign = (s[i] == '-') ? -1 : 1;

    if(s[i] == '+' || s[i] == '-') i ++;

    for(exp = 0.0; isdigit(s[i]); i ++)
        exp = 10.0 * exp + (s[i] - '0');

    
    if(expSign == -1) return (sign*value/power) / powerF(10, exp);


    else return (sign*value/power) * powerF(10, exp);

}

/* power: calculates base to the exp power */
int powerF(int base, int exp){

    int r = 1;

    while(exp){
        r *= base;
        exp --;
    }
    return r;
}

