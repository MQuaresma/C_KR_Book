#include <stdio.h>
#include <ctype.h>

/* Sensible printing: prints arbitrary input, breaking long lines (20+ chars) and printing non-graphic chars in hex or octal */
main(){

    int c, lineCur = 0;

    while((c = getchar()) != EOF){
        if(lineCur >= 20 || c == '\n') printf("\n"), lineCur = 0;
        
        if(isalpha(c) || isdigit(c) || isspace(c)){ 
            printf("%c", c);
            lineCur ++;
        }else if(c != '\n'){
            printf("%x", c);    //print in hex
            printf("%o", c);    //print in octal
            lineCur ++;
        }
    }

    return 0;
}
