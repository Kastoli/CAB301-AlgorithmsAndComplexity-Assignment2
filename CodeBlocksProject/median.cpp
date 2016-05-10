#include <iostream>
#include <tgmath.h>
#include <algorithm>
#include <time.h>

using namespace std;

 void fisher_yates_shuffle(int *testData, int testDataSize) {
    srand (time(NULL));
    for(int i=testDataSize-1; i>0; i--) {
    int randI = (rand() % (i+1));
    swap(testData[randI], testData[i]);
    }
 }

int Partition(int *A,int l, int h) {
int pivotval = A[l];
int pivotloc = l;
for(int j=l+1; j<=h;j++){
    if(A[j]<pivotval){
        pivotloc++;
        swap(A[pivotloc],A[j]);
    }
}
swap(A[l], A[pivotloc]);
return pivotloc;
}


int Select(int *A, int l,int m, int h) {
int pos = Partition(A, l, h);
if(pos==m){
    return A[pos];
}
else if(pos>m){
    return Select(A,l,m,pos-1);
} else{
    return Select(A,pos+1,m,h);
}
}

int Median(int *A, int N) {
    if(N==1){
        return A[0];
    }else{
    Select(A, 0, floor(N/2), N-1);
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

        Median(testData,sizeof(testData));
    }

    return 0;
}
