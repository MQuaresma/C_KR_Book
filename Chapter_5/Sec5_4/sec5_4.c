#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE];    /* buffer */
static char *allocp = allocbuf;     /* pointer to next free position in allocbuf */


char *alloc(int n){

    if(allocbuf+ALLOCSIZE - allocp >= n){
        allocp += n;
        return allocp-n;
    }
    else return 0; 

}


void afree(char *p){

    if(p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;

}
