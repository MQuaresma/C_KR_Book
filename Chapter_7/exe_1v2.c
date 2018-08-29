#include <stdio.h>
#include <string.h>
#include <ctype.h>


/* Transforms input according to the flag given*/
int main(int argc, char *argv[]){

    int c;

    if(argc == 2){
        if(!strcmp(*++argv, "-l"))
            while((c = getchar()) != EOF) putchar(tolower(c));
        
        else if(!strcmp(*argv, "-u"))
            while((c = getchar()) != EOF) putchar(toupper(c));

    }
    else puts("Not enough arguments");

    return 0;

}
