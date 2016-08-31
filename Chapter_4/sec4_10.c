#include <stdio.h>

/* printd: print n in decimal */
void printd(int n){

    if(n < 0){
        n = -n;
        putchar('-');
    }
    
    if(n/10)
        printd(n/10);
    putchar(n%10 + '0');

}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(int v[], int left, int right){

    int i, last;
    void swap(int v[], int, i, int j);

    if(left >= right)       /* do nothing if the array contains */
        return;             /* fewer than two elements */

    swap(v, left, (left+right)/2);  /* move partition element to v[0] */

    last = left;

    for(i = left + 1; i <= right; i ++)
        if(v[i] < v[left]) swap(v, ++last, i);

    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}


void swap(int v[], int left, int right){
    
    int temp = v[left];
    v[left] = v[right];
    v[right] = temp;

}
