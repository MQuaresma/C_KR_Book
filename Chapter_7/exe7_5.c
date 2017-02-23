#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 150

int diff(char *, FILE *, FILE *);

int main(int argc, char *argv[]){

    FILE *f1, *f2;
    char *prog = *argv, *file1, *file2, lineDiff[MAX];

    if(argc != 3){
        fprintf(stderr, "%s: not enough arguments provided, check manual for usage \n", prog);
        exit(1);
    }

    file1 = *++argv;
    file2 = *++argv;

    if(!strcmp(file1, file2)){ 
        printf("The same file was specified.\n"); /* no need to compare if the same file is compared */
        exit(0);
    }
    f1 = fopen(file1, "r");
    f2 = fopen(file2, "r");

    if(!f1 || !f2) printf("%s: at least one of the paths provided wasn't found.\n", prog);
    else if(diff(lineDiff, f1, f2)) printf("First line where files differ:\n %s \n", lineDiff);
    else printf("Files don't differ in any line.\n");
    fclose(f1), fclose(f2);
    exit(0);

}

int diff(char *lineDiff, FILE *f1, FILE *f2){

    char fLine1[MAX], fLine2[MAX], *r1, *r2;
    int diff = 0;

    while((r1 = fgets(fLine1, MAX, f1)) && (r2 = fgets(fLine2, MAX, f2)) && (diff = strcmp(fLine1, fLine2)) == 0);

    if((!r1 && r2) || diff) strcpy(lineDiff, fLine2);
    else if(r1 && !r2) strcpy(lineDiff, fLine1);

    return diff;
}