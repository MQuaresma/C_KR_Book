#include <stdio.h>

/* Run as prog < inputFile > outputFile */

int countlines(void);

/* Showcasing the propertie of feeding input from a file instead of a keyboard using the < "operator" */
main(){

    int lines = countlines();
    printf("No. of lines in file: %d\n", lines);
    return 0;

}


int countlines(void){

    int c, lines = 0;

    while((c=getchar()) != EOF)
        if(c == '\n') lines ++;
    
    return lines;

}
