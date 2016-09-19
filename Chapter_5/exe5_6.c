#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define NUMBER 1
#define MAX 100

/* Past functions/programs written using pointers more explicitely and as an alternative to array subscripts */


void getLine(char *s, int max){

    char c;

    while((c = getchar()) != EOF && c != '\n' && --max) (*s ++) = c;

    *s = '\0';

}


int getop(char *s){

    char c;

    while(isspace(c = getchar()) && c != '\t');

    if(!isdigit(c) && c != '-' && c != '.') return c;

    if(isdigit(c = getchar())){
            *s ++ = '-';
            do{
                *s ++ = c;
            }while(isdigit(c = getchar()));
    }
    else return '-';

    if(c == '.'){
        do{
           *s ++ = c; 
        }while(isdigit(c = getchar()));
    }

    *s = '\0';
    return NUMBER;
}


int atoi(char *s){

    int value = 0.0;

    while(isspace(*s) && (*s) ++ == '\t');

    

    while(isdigit(*s)){
        value = value * 10 + (*s - '0');
        s ++;
    }

    return value;
}

/* reverse: reverse using pointers */
void reverse(char *s){
    
    int i , j;
    char c;


    for(j = 0, i = strlen(s) - 1; j <= i; i --, j ++){
        c = s[i];
        *(s + i)= *(s+j);
        *(s + j)= c;
    }
}

/* reverseP: reverse using pointers in a more advanced way */
void reverseP(char *s){

    char *r = s + strlen(s), c;

    while(s < -- r){
        c = *s;
        *s ++ = *r;
        *r = c;
    }

}

void itoa(int n, char *s){

   do{
        *s = n%10 +'0';
        s ++;
   }while(n/=10);
    
    *s = '\0';

}

int strindexP(char *s, char *t){

    char *sA, *sI = s, *tI = t; 

    while(*s){
        sA = s;
        while(*t && *s ++ == *t ++);
        if(!(*t)) return sA - sI;
        t = tI;
    }
    return -1;
} 

int main(){

    char s[] = "Miguel", t[] = "iguel";


    printf("%d\n", strindexP(s,t));

}
