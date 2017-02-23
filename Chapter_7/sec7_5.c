#include <stdio.h>
#define getchar() getc(stdin)           /* Possible definition of the macros getchar() and putchar() knowing that stdin and stdout are file pointers */
#define putchar(c) putc((c), stdout)

/* Files:
 * FILE is a structure with info about the file it points to, this structure is defined in the stdio header file
 * When a C program is started there are, at least, three file pointers involved, these are: stdin, stdout and stderr therefore
 * many file related functions can mimic their "normal" counterparts by pointing them to these "files"
 * fp = fopen(name, mode) -> name: refers to the path of the file; mode: refers to the way the file is going to be used
 */

/* Cat: implementation of the cat command-line utilitie */
int main(int argc, char *argv[]){

    FILE *fp;
    void filecopy(FILE *, FILE *);

    if(argc == 1) /* no args, copy standard input */
        filecopy(stdin, stdout);

    else
        while(--argc > 0)
            if((fp = fopen(*++argv, "r")) == NULL){
                printf("Can't open %s\n", *argv);
                return 1;
            }else{
                filecopy(fp, stdout);
                fclose(fp);
            }
    return 0;

}


void filecopy(FILE *fsrc, FILE *fdest){

    int c;

    while((c = getc(fsrc)) != EOF)
        putc(c, fdest);
    
}
