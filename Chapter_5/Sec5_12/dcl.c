#include "header.h"


/* convert declartions to words */
main(){

    while(gettoken() != EOF){
        strcpy(datatype, token);
        out[0] = '\0';
        dcl();                  /* parse the rest of the line */
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}
