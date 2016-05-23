#ifndef BRUTEFORCEMEDIAN_HPP_INCLUDED
#define BRUTEFORCEMEDIAN_HPP_INCLUDED

#include <math.h>

int BruteForceMedian(int A[], int n){
    int k = ceil((float)n/2);
    for(int i = 0; i <= n-1; i++){
        int numsmaller = 0;
        int numequal = 0;
        for(int j = 0; j <= n-1; j++){
            if(A[j] < A[i]){ // This is basic operation?
                numsmaller = numsmaller+1;
            } else {
                if(A[j] == A[i]){
                    numequal = numequal+1;
                }
            }
        }
        if(numsmaller < k && k <= (numsmaller+numequal)){
            return A[i];
        }
    }
}

int BruteForceMedian_BasicOperations(int A[], int n, unsigned long numoperations){
    numoperations++;
    int k = ceil((float)n/2);
    for(int i = 0; i <= n-1; i++){
        int numsmaller = 0;
        int numequal = 0;
        for(int j = 0; j <= n-1; j++){
            numoperations++; // Increment basic operation here.
            if(A[j] < A[i]){ // This is basic operation?
                numsmaller = numsmaller+1;
            } else {
                if(A[j] == A[i]){
                    numequal = numequal+1;
                }
            }
        }
        if(numsmaller < k && k <= (numsmaller+numequal)){
            return A[i];
        }
    }
}

#endif // BRUTEFORCEMEDIAN_HPP_INCLUDED
