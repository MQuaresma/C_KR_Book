#include <stdio.h>

/* echo command-line argumets; 1st version */
main(int argc, char *argv[]){

    int i;
    while(--argc > 0)
        printf("%s%s", *++argv, (1 < argc) ? " ": "");
        printf((argc>1) ? "%s " : "%s", *++argv);       /* same output as above */
    printf("\n");
    return 0;

}
