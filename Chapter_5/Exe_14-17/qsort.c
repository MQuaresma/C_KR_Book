#include "sorting.h"

void quickSort(void *v[], int left, int right, int (*comp)(void *, void *)){

    int last, i;
    void swap(void *v[], int i, int j);

    if(left >= right)
        return;
    swap(v, left, (left+right)>>1);
    last = left;
    for(i = left+1; i <= right; i ++)
        if(((*comp)(v[left], v[i])) > 0)
            swap(v, ++last, i);
    swap(v,left, last);
    quickSort(v, left, last-1, comp);
    quickSort(v, last+1, right, comp);

}


void swap(void *v[], int i, int j){

    void *temp = v[i];

    v[i] = v[j];
    v[j] = temp;

}
