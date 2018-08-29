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


/*undcl: convert word descriptions to declarations */
main(){
    int type;
    char temp[MAXTOKEN];

    // TODO:implement a description to declaration parser 
    while(gettoken() != EOF){
        strcpy(out, token);
        while((type = gettoken()) != '\n'){
			if(type == PARENS || type = BRACKETS)
				strcat(out, token);
			else if(type == '*'){
				sprintf(temp, "")
			}


		}
    }
    return 0;
}
