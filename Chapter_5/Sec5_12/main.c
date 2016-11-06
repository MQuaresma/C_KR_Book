#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);

int gettoken(void);         
int tokentype;              /* type of last token */
char token[MAXTOKEN];       /* last token string */
char name[MAXTOKEN];        /* identifier name */
char datatype[MAXTOKEN];    /* data type = char, int, etc. */
char out[1000];             /* output string */


main(){

    while(gettoken != EOF){
        strcpy(datatype, token);
        out[0] = '\0';
        dcl();                  /* parse the rest of the line */
        if(tokentype != '\n')
            printf("Syntax error");
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}
