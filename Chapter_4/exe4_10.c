#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#define MAXVAL 100  /* maximum depth of val stack */
#define BUFSIZE 100
#define MAXINPUT 1000   /* maximum input length */
#define NUMBER '0'
#define NAME 'n'



int getOp(char *);
void push(double);
double pop(void);
void swapStack(void);
void clearStack(void);
double printTop(void);
double atoF(char []);
int powerF(int, int);
int getLine();
void specialFunc(char *s);



/* reverse Polish calculator */
int main(){

	int type;
	double op1, op2, rec;                    /* rec saves the last printed value */
	char s[MAXINPUT];  /* no stores numbers in input string */ 


    while((type = getOp(s)) != EOF){
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
            case '%': 						
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
                op2 = pop();
                push(op2);
                push(op2);
                break;
            case 's':
                op2 = pop();
                op1 = pop();
                push(op2);
                push(op1);
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

char input[MAXINPUT];
int pos = 0;

/* getLine: gets a string form input */
int getLine(){
    
    int i = 0;
    char c;

    while(i < MAXINPUT-1 && (c = getchar()) != EOF && c != '\n')
        input[i++] = c; 

    if(i && i < MAXINPUT - 1 && c == '\n') 
        input[i++] = c;

    input[i] = '\0';

    return i; 
}


/* getOp: returns next operator or NUMBER in case of operator */
int getOp(char s[]){

    int sI = 0;

    if(input[pos] == '\0'){         
        if(!getLine()) return EOF; 
        else pos = 0;
    }

    while(input[pos] == ' ' || input[pos] == '\t') pos ++; 

    while(isalpha(input[pos])) s[sI++] = input[pos++];

    if(sI > 1){
        s[sI] = '\0';
        return NAME; 
    }


    if(!isdigit(input[pos]) && input[pos] != '.' && input[pos] != '-') return input[pos++];

    sI = 0;
    if(input[pos] == '-'){
        pos ++;
        if(isdigit(input[pos])) s[sI++] = '-';
        else return '-';
    }

    while(isdigit(input[pos]))
        s[sI++] = input[pos++];
    
    if(input[pos] == '.'){
        s[sI++] = input[pos++];
        while(isdigit(input[pos]))
            s[sI++] = input[pos++];
    }

    if(input[pos] == 'e' || input[pos] == 'E'){
        s[sI++] = input[pos++];
        while(isdigit(input[pos]))
            s[sI++] = input[pos++];
    }

    s[sI] = '\0';

    return NUMBER;
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

void specialFunc(char s[]){

    double op2;

    if(!strcmp(s, "sin"))
        push(sin(pop()));
    else if(!strcmp(s, "cos"))
        push(cos(pop()));
    else if(strcmp(s, "tan"))
        push(tan(pop()));
    else if(!strcmp(s, "exp"))
        push(exp(pop()));
    else if(!strcmp(s, "pow")){
        op2 = pop();
        push(pow(pop(), op2));
    }
    else
        printf("Error: unknown function\n");

}


/* swapStack: swaps the first two elements in the stack */
void swapStack(){
	double temp;
	
	if(sp > 1){
		temp = pop();
        push(pop());
		stack[sp-2] = temp;
	}
	else printf("Error: not enough elements in stack to perform swap operation \n");
}

/* clearStack: empties the stack */
void clearStack(){

    sp = 0;
    printf("\t Stack cleared with sucess\n");
}

/* printTop: prints the top element of the stack */
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
