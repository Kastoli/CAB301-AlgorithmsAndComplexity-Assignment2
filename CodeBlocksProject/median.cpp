#include <iostream>
#include <tgmath.h>
using namespace std;

int Partition(int *A, int N,int l, int h) {
int pivotval = A[l];
int pivotloc = l;
for(int j=l+1; j<=h;j++){
    if(A[j]<pivotval){
        pivotloc = pivotloc++;
        swap(A[pivotloc],A[j]);
    }
}
swap(A[l], A[pivotloc]);
}


int Select(int *A, int N, int l,int m, int h) {
int pos = Partition(*A, N, l, h);
if(pos==m){
    return *A[pos];
}
else if(pos>m){
    return Select(*A,l,m,pos-1);
} else{
    return Select(*A,pos+1,m,h);
}
}

int Median(int *A, int N) {
    if(N==1){
        return A[0];
    }else{
    Select(A*, N, 0, floor(N/2), N-1);
    }
}

int main()
{
    int testDataAmount = 500;

    for(int run = 1; run<=1;run++){
        //Dataset setup
        int testData[testDataAmount];
        for(int i = 0; i<testDataAmount;i++){
            testData[i] = i;
        }
        fisher_yates_shuffle(testData,testDataAmount);
        if(is_sorted(testData, testData+testDataAmount)){return -1;}


    return 0;
}
