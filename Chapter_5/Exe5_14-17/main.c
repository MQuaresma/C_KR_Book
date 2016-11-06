#include <stdio.h>
#include <string.h>
#define PARAMS 4
#define MAXINPUT 5000

char *lineptr[MAXINPUT];

int readline(char *lineptr[], int nlines);
void writeline(char *lineptr[], int nlines);
int belongs(char **s1, char check, int argc);

/* comp is a pointer to a function which returns an integer and recieves two pointers as parameters */
void qsort(void *v[], int left, int right, int (*comp)(void *, void*));
int numcmp(char *,char *);
int numcmpReverse(char *,char *);
int strcmpReverse(char *,char *);
int strcmpReverseLower(char *, char *);
int strCmpLower(char *, char *);

/* sorts input string either lexicographicaly or numerically and either in reverse on in-order, depending on the parameters passed */
main(int argc, char *argv[]){

    int nlines;
    int numeric = 0, reverse = 0, fold = 0, dir_order = 0;
    int (*func)(void *, void *);

    while(--argc && **++argv == '-'){
        while(*(++*argv)){
            switch(**argv){
                case 'n': 
                        numeric = 1;
                        break;
                case 'r': 
                        reverse = 1;
                        break;
                case 'f': 
                        fold = 1;
                        break;
                case 'd': 
                        dir_order = 1;
                        break;
                default:
                        printf("Invalid option\n");
                        break;
            }
        }
    }

    func = (int (*) (void *, void *)) (numeric ? (reverse ? numcmpReverse : numcmp) : (reverse ? (fold ? strcmpReverseLower : strcmpReverse) : (fold ? strCmpLower : strcmp)));

    if((nlines = readline(lineptr, MAXINPUT)) >= 0){
        /* int (*) (void *, void *) type casts the functions passed to it */
        qsort((void **)  lineptr, 0, nlines-1, func);
        writeline(lineptr, nlines);
        return 0;
    }
    else{
        printf("Input too big to sort\n");
        return 1;
    }

}
