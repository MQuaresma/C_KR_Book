#include <stdio.h>
#include <stdlib.h>

/* escape: Replaces escapes with explicit escapes */
/*Unsafe version, might give seg fault errors in case not enough memory is allocated for d*/
void escape(char *s, char *d){

    int i, dI;
    
    for(i = 0, dI = 0; s[i]; i ++){
        switch(s[i]){
            case '\t': 
                d[dI++] = '\\';
                d[dI++] = 't';
                break;
            case '\n':
                d[dI++] = '\\';
                d[dI++] = 'n';
                break;
            default:
                d[dI++] = s[i];
                break;
        }
    }
    d[dI] = '\0';

}

/* safeEscape: Replaces escapes with explicit escapes */
/* Safe version which allocates the necessary amount of memory for d */
void safeEscape(char *s, char *d){

    int i = 0, blanks = 0, dI;
    
    for(i = 0; s[i]; i ++){
        switch(s[i]){
            case '\t' : case '\n': 
                blanks ++;
                break;
        }
    }
    i += blanks;
    d = (char *) malloc(i * sizeof(char) + 1); /*memory allocation for d*/
    
    for(i = 0, dI = 0; s[i]; i ++){
        switch(s[i]){
            case '\t': 
                d[dI++] = '\\';
                d[dI++] = 't';
                break;
            case '\n':
                d[dI++] = '\\';
                d[dI++] = 'n';
                break;
            default:
                d[dI++] = s[i];
                break;
        }
    }
    d[dI] = '\0';

}

/* switchChar: Replaces explicit escapes with actual escapes */
void switchChar(char *s, char *d){

    int i, dI;

    for(i = 0, dI = 0; s[i]; i ++){

        switch(s[i]){
            case '\\':
                switch(s[i+1]){
                    case 't':
                        d[dI++] = '\t';
                        i ++;
                        break;
                    case 'n':
                        d[dI++] = '\n';
                        i ++;
                        break;
                }
                break;
            default: 
                d[dI++] = s[i];  
                break;
        }
    }
    d[dI] = '\0';
}

/* countChars: scans a string from input and prints out an anylisis on the types of characters that make it up */
void countChars(void){

    int i, nwhite, nother, ndigit[10];
    char c;
    nwhite = nother = 0;

    for(i = 0; i < 10; i ++) ndigit[i] = 0;

    while((c = getchar()) != 's'){
        switch(c){
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                ndigit[c - '0'] ++;
                break;
            case ' ': case '\n': case '\t': 
                nwhite ++;
                break;
            default: 
                nother ++;
                break;    
        }
    }

    printf("digits =");
    for(i = 0; i < 10; i ++) printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n", nwhite, nother);
}



int main(){

    char *s = "Miguel Mariana\\";
    char d[100];
    switchChar(s, d);
    printf("%s\n", d);
    return 0;
}