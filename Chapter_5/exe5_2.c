#include <ctype.h>


int getch();
void ungetch(int);

/* getFloat: convert input stream into a float */
/* Notice that getFloat returns an int just as getInt, this is because the arguments are passed to it by reference and 
   therefore it doesn't need to return the value */
int getFloat(float *pe){
    
    int c, sign, power;

    while(isspace(c = getch()));

    if(!isdigit(c) && c != EOF && c != '+'&& c != '-' && c != '.'){
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if(c == '+' || c == '-') c = getch();


    for(*pe = 0; isdigit(c); c = getch())
        *pe = *pe * 10 + (c - '0');

    if(c == '.') c = getch();

    for(power = 10; isdigit(c); c = getch(), power *= 10)
        *pe = *pe * 10 + (c - '0');
    
    if(c != EOF){
        *pe = sign * (*pe) / power; 
        ungetch(c);
        return 1;
    }

    else return -1;

}
