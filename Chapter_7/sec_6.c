#include <stdio.h>
#include <stdlib.h>


/* Cat: revised implementation of the cat command-line utilitie with better error-handling capabilities */
int main(int argc, char *argv[]){

    FILE *fp;
    void filecopy(FILE *, FILE *);
    char *prog = argv[0];

    if(argc == 1) /* no args, copy standard input */
        filecopy(stdin, stdout);

    else
        while(--argc > 0)
            if((fp = fopen(*++argv, "r")) == NULL){
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                exit(1);            // exit() is a function that ends program execution as soon as called, no matter where it was called from, the argument used signals success or failure in program execution
            }else{
                filecopy(fp, stdout);
                fclose(fp);
            }
    if(ferror(stdout)){
        fprintf(stderr, "%s: error writing to stdout \n", prog);
        exit(1);
    }

    exit(0);                

}


void filecopy(FILE *fsrc, FILE *fdest){

    int c;

    while((c = getc(fsrc)) != EOF)
        putc(c, fdest);
    
}
