#ifndef BRUTEFORCEMEDIAN_HPP_INCLUDED
#define BRUTEFORCEMEDIAN_HPP_INCLUDED

#include <math.h>

int BruteForceMedian(int A[], int n){
    int k = ceil((float)n/2);
    for(int i = 0; i <= n-1; i++){
        int numsmaller = 0;
        int numequal = 0;
        for(int j = 0; j <= n-1; j++){
            if(A[j] < A[i]){
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
