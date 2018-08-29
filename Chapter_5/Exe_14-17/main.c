#include <stdio.h>
#include <string.h>
#include "sorting.h"
#include "parameters.h"
#define MAXINPUT 5000

char *lineptr[MAXINPUT];

int readline(char *lineptr[], int nlines);
void writeline(char *lineptr[], int nlines);
int belongs(char **s1, char check, int argc);


/* sorts input strings according to the parameters passed */
main(int argc, char *argv[]){

	dictionaryArray d;
    int nlines;
    int (*func)(void *, void *); /* func is a pointer to a function which returns an integer and recieves two pointers as parameters */

	initDict(d);
	/* setting the flags for the command-line options */
    while(--argc && **++argv == '-'){
        while(*(++*argv))
			if(newParam(p, **argv, PARAMS)) printf("Invalid option\n");
    }

	/* int (*) (void *, void *) type casts the functions passed to it */
	if(checkValue(p, 's')) func = (int (*) (void *, void *)) indexSorting; 
	else if(checkValue(p, 'n')){
		if(checkValue(p, 'r'))
			func = (int (*) (void *, void *)) numcmpReverse;
		else func = (int (*) (void *, void *)) numcmp;
	}
	else if(checkValue(p, 'd')) func = (int (*) (void *, void *)) indexSorting;  
	}else if(checkValue(p, 'f')){
		if(checkValue(p, 'r')){
			
		}


	}

    if((nlines = readline(lineptr, MAXINPUT)) >= 0){
        quickSort((void **)  lineptr, 0, nlines-1, func);
        writeline(lineptr, nlines);
        return 0;
    }
    else{
        printf("Input too big to sort\n");
        return 1;
    }

}
