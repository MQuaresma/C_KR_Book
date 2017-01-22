#include "header.h"
#define CAPACITY 1000
/*#include <stdio.h>
#include<ctype.h>
#include<string.h>

extern enum {NAME, PARENS, BRACKETS};
extern char *out;
extern int tokentype;
extern char *token;
extern char *name;
extern char *datatype;*/


int gettoken(void){ /*return next token */
    int c, getch(void);
    void ungetch(int);
    char *p = token;

    while((c=getch()) == ' ' || c == '\t');

    if(c == '('){
        if((c = getch()) == ')'){
            strcpy(token, "()");
            return tokentype = PARENS;
        }else{
            ungetch(c);
            return tokentype = '(';
        }
    }else if(c == '['){
        for(*p ++ = c; ((*p++ ) = getch()) != ']';); 
        *p = '\0';
        return tokentype = BRACKETS;
    }else if(isalpha(c)){
        for(*p++ = c; isalnum(c=getch()); )
            *p ++ = c;

        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    }else
        return tokentype = c;

}

static int buffer[CAPACITY], sp = 0;

int getch(void){

	return ((sp == 0) ? getchar() : buffer[--sp]);

}

void ungetch(int c){

	if(sp == CAPACITY)
		printf("Buffer Overflow\n");
	else buffer[sp ++] = c;

}
