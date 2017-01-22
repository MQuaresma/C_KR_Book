#include <ctype.h>
#include <stdio.h>
#define MAX 100

/* atof: convert string s to double */
double atof(char s[]){

    double val, power;
    int i, sign;

    for(i = 0; isspace(s[i]); i ++);

    sign = (s[i] == '-') ? -1 : 1;
    if(s[i] == '+' || s[i] == '-') i ++;

    for(val = 0.0; isdigit(s[i]); i ++)
        val = 10.0 * val + (s[i] - '0');
    if(s[i] == '.') i ++;

    for(power = 1.0; isdigit(s[i]); i ++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    return sign * val / power;
}


int getLine(char s[], int max){

    int i;
    char c;

    for(i = 0; --max > 0 && ((c = getchar()) != EOF && c != '\n'); i ++)
        s[i] = c;

    s[i] = '\0';
    return i;
}

/* rudimentary calculator */
int main(){

    double sum, atof(char s[]);
    char line[MAX];
    int getLine(char line[], int max);

    sum = 0;
    while(getLine(line, MAX) > 0)
        printf("\t%g\n", sum += atof(line));

    return 0;

}