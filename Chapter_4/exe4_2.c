#include <stdio.h>
#include <ctype.h>
#define MAX 100


int powerC(int base, int exp){

    int result = 1;

    while(exp--) result *= base;

    return result;
}




/* atof: converts string s to a double, handling cases like 3.14e-27 */
double atof(char s[]){

    double value, power, result, expValue;
    int i, sign, expSign;

    for(i = 0; isspace(s[i]); i ++);

    sign = (s[i] == '-') ? -1 : 1;

    if(s[i] == '-' || s[i] == '+') i ++;

    for(value = 0.0; isdigit(s[i]); i ++)
        value = 10.0 * value + (s[i] - '0');
    
    if(s[i] == '.') i ++;

    for(power = 1.0; isdigit(s[i]); i ++){
        value = 10.0 * value + (s[i] - '0');
        power *= 10.0;
    }

    /* Handles the exponent calculation */
    if(s[i] == 'e' || s[i] == 'E') i ++;      
    expSign = (s[i] == '-') ? -1 : 1;
    if(s[i] == '+' || s[i] == '-') i ++;

    for(expValue = 0; isdigit(s[i]); i ++)  
        expValue += 10.0 * expValue + (s[i] - '0');

    result = sign * value/power;    

    
    if(expSign == -1) result /= powerC(10, expValue);
    else result *= powerC(10, expValue);

    return result;
}

/* getLine: copies input to string s */
int getLine(char s[], int max){

    int i;
    char c;

    for(i = 0; --max > 0 && (c = getchar())!= EOF && c != '\n'; i ++)
        s[i] = c;
    
    s[i] = '\n';
    
    return i;
}

int main(){

    double sum, atof(char s[]);
    int getLine(char s[], int max);
    char s[MAX];

    sum = 0.0;
    while(getLine(s, MAX) > 0){
        printf("\t %g \n", sum += atof(s));
    }

    return 0;
}