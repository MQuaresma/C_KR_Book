#include <stdio.h>
#include <time.h>

/*C Book binary search function in a sorted array*/
int binsearch(int x, int v[], int n){

    int low, high, mid;
    low = 0;
    high = n-1;
    while(low<=high){
        mid = (low+high) / 2;
        if(x < v[mid])
            high = mid - 1;
        else if(x > v[mid])
            low = mid + 1;
        else /*found match*/
            return mid;
    }
    return -1; /*no match*/
}

/*Optimized version of the C Book binary search function in an ordered array*/
int binsearchOp(int x, int v[], int n){

    int low, high, mid;
    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while(low <= high && x != v[mid]){
        if(x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
        mid = (low + high) / 2;
    }
    if(low > high) return -1;
    else return mid;
}