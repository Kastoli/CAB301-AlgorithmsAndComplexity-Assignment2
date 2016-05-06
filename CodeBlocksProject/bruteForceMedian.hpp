#ifndef BRUTEFORCEMEDIAN_HPP_INCLUDED
#define BRUTEFORCEMEDIAN_HPP_INCLUDED

int bruteForceMedian(int inputArray[], int arrayLength){
    int k = (arrayLength + 1) / 2; // +1 for Ceiling Value, Integer Division
    for(int i = 0; i < arrayLength; i++){
        int numSmaller = 0;
        int numEqual = 0;
        for(int j = 0; j < arrayLength; j++){
            if(inputArray[j] < inputArray[i]){
                numSmaller++;
            }else if(inputArray[j] == inputArray[i]){
                numEqual++;
            }
        }
        if(numSmaller < k && k <= (numSmaller + numEqual)){
            return inputArray[i];
        }
    }
}

#endif // BRUTEFORCEMEDIAN_HPP_INCLUDED