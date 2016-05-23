#ifndef MEDIAN_HPP_INCLUDED
#define MEDIAN_HPP_INCLUDED

#include <math.h>

int Median(int A[], int n);
int Select(int A[], int l, int m, int h);
int Partition(int A[], int l, int h);

int Median(int A[], int n){
    if(n == 1){
        return A[0];
    } else {
        Select(A, 0, floor((float)n/2), n-1);
    }
}

int Select(int A[], int l, int m, int h){
    int pos = Partition(A, l, h);
    if(pos == m){
        return A[pos];
    }
    if(pos > m){
        return Select(A, l, m, pos-1);
    }
    if(pos < m){
        return Select(A, pos+1, m, h);
    }
}

int Partition(int A[], int l, int h){
    int pivotval = A[l];
    int pivotloc = l;
    for(int j = l+1; j <= h; j++){
        if(A[j] < pivotval){ // This is basic operation?
            pivotloc = pivotloc+1;
            int temp = A[pivotloc];
            A[pivotloc] = A[j];
            A[j] = temp;
        }
    }
    int temp = A[l];
    A[l] = A[pivotloc];
    A[pivotloc] = temp;
    return pivotloc;
}

#endif // MEDIAN_HPP_INCLUDED
