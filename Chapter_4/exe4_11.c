#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#define MAXVAL 100 /* maximum depth of val stack */
#define BUFSIZE 100
#define MAXOP 100
#define NUMBER '0'
#define NAME 'n'
#define MAXBUFFER 100



int getop(char []);
void push(double);
double pop(void);
void specialFunc(char *);
void duplicate(void);
void swapStack(void);
void clearStack(void);
double printTop(void);
double atoF(char []);
char getch(void);
void ungetch(char);
int powerF(int, int);

/* reverse Polish calculator */
int main(){

	int type;
	double op2, rec;        /* rec saves the last printed value */
	char s[MAXOP], c;

	while((type = getop(s)) != EOF){
		switch(type){
			case NUMBER:
				push(atoF(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if(op2)
					push(pop() / op2);
				else printf("Error: division by zero \n");
				break;
			case '%': 						/* add modulus operator */
				op2 = pop();
				if(op2)
					push((int)pop() % (int)op2);
				else printf("Error: division by zero \n");
				break;
            case NAME:
                specialFunc(s);
                break;
            case 'p':
				rec = printTop();
				break;
			case 'd':
				duplicate();
				break;
			case 's':
				swapStack();
				break;
			case 'c':
				clearStack();
				break;
			case 'l':
				printf("\t%g\n", rec);
				break;
			case '\n':
				printf("\t%.8g\n", (rec=pop()));
				break;
			default:
				printf("Error: unknown command\n");
				break;
		}
	}			

	return 0;
}



double stack[MAXVAL]; 	/* value stack */
int sp = 0;		/* pointer to the next free spot */

void push(double v){

	if(sp < MAXVAL)
		stack[sp++] = v;
	else printf("Error: stack is full \n");
}

double pop(){

	if(sp)
		return 	stack[--sp];
	else{ 
		printf("Error: stack is empty \n");
		return 0.0;
	}
}

void duplicate(){

	if(sp) stack[sp++] = stack[sp-1];
	else printf("Error: stack empty, nothing to duplicate\n");

}


void swapStack(){
	double temp;
	
	if(sp > 1){
		temp = stack[sp-1];
		stack[sp-1] = stack[sp-2];	
		stack[sp-2] = temp;
	}
	else printf("Error: not enough elements in stack to perform swap operation \n");
}

void clearStack(){

    sp = 0;

}

double printTop(){

	if(sp){ 
		printf("Top element: %g\n", stack[sp - 1]);
		return stack[sp-1];
	}
	else{ 
		printf("Error: stack empty, no element found \n");
		return 0.0;
	}
}

/* getop: returns next operator or NUMBER in case of operator */
int getop(char s[]){

	int i, c;
    static int buffer[MAXBUFFER];
	static int bufp;                /* no initialization required since static and external variables are initialized to 0 */

	while(s[0] = c = ((bufp) ? buffer[--bufp] : getchar())== ' ' || c == '\t');
	
	s[1] = '\0';
	
	if(!isdigit(c) && c != '.' && c != '-') return c; /* not a number  */	

    i = 0;

    if(isalpha(c)){
        s[i ++] = c;
        while(isalpha(c =  (bufp) ? buffer[--bufp] : getchar())) s[i++] = c;

        s[i] = '\0';

        if(i > 1) return NAME;
        else return s[0];
    }

    if(c == '-')
        if(isdigit(c =  (bufp) ? buffer[--bufp] : getchar()));

	
	if(c == '.')					/* fraction part */
		while(isdigit(s[++i] = c = (bufp) ? buffer[--bufp] : getchar()));

	s[i] = '\0';
	if(c != EOF && bufp < MAXBUFFER)
        buffer[bufp++] = c;
	return NUMBER;
}

char buf;	            /* input buffer */
int bufStatus = 0;		/* holds the status (available or not) of the one char buffer */

/* getch: read character from buffer or from input */
char getch(){

    if(!bufStatus){
        bufStatus = 1; 
        return buf;
    }
    else return getchar();
}

/* ungetch: store character c in a buffer for later reading */
void ungetch(char c){

	(bufStatus) ? buf = c, bufStatus = 0 : printf("Error: buffer in use\n");
}

char bufString[BUFSIZE];        /* buffer for the strings */
char bufp;                      /* next free slot in bufString */

/* ungets: stores a whole string s in a buffer for later reading */
void ungets(char s[]){
    int i = 0; 

    while(s[i] && bufp < BUFSIZE) bufString[bufp++] = s[i++];

    if(bufp < BUFSIZE) bufString[bufp++] = '\0'; 

    if(s[i]) printf("Error: buffer-overflow\n");

}

void specialFunc(char s[]){

    double op;

    if(!strcmp(s, "sin"))
        push (sin(pop()));
    else if(!strcmp(s, "cos"))
        push (cos(pop()));
    else if(!strcmp(s, "tan"))
        push (tan(pop()));
    else if(!strcmp(s, "exp"))
        push (exp(pop()));
    else if(!strcmp(s, "pow")){
        op = pop();
        push (pow(pop(), op));
    }
    else 
        printf("Error: unknown function \n");

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
