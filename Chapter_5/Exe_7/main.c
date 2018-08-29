#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /* maxlines to be sorted */
#define MAXINPUT 100000 /* max length for input lines */

char *lineptr[MAXLINES];    /* pointers to text lines */

int readlines(char *lineptr[], int nlines, char *lines, int maxinput);
void writelines(char *lineptr[], int nlines);


void qsort(char *lineptr[], int left, int right);



/* sort input lines */
main(){

    int nlines;
    char lines[MAXINPUT];

    if((nlines = readlines(lineptr, MAXLINES, lines, MAXINPUT))>= 0){
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    }
    else{
        printf("Error: buffer overflow, input too big\n");
        return 1;
    }

}
