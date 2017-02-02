#include <stdio.h>
#include <ctype.h>
#include <custom.h>

static Buffer b;
b->sp = 0;

int getword(char *dest, int size){

	int i = 0, c;

	while(isspace(c = getch()) && !isalpha(c));

	if(!alpha(c)) return c;

	for(i = 0; i < size && isalpha(c); c = getch(), i ++)
		dest[i] = c;

	ungetch(c);

	return i;
}

char getch(void){

	if(b->sp > 0)
		return b->s[-- b->sp];
	else return getchar();

}

void ungetch(char c){

	if(b->sp < b->size) b->s[b->sp ++] = c;

}