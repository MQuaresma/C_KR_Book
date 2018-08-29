#include <stdio.h>
#include <string.h>
#include <ctype.h>


/* Transforms input according to the program name i.e the binary file name */
int main(int argc, char *argv[]){

    int c;

    if(argc){
        if(!strcmp(*argv, "./toLower"))
            while((c = getchar()) != EOF) putchar(tolower(c));
        
        else if(!strcmp(*argv, "./toUpper"))
            while((c = getchar()) != EOF) putchar(toupper(c));

    }

    return 0;

}
