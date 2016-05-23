#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>

#include "BruteForceMedian.hpp"
#include "Median.hpp"

using namespace std;

int BruteForceMedian_BasicOperations(int A[], int n);
int Median_BasicOperations(int A[], int n);
int Select_BasicOperations(int A[], int l, int m, int h);
int Partition_BasicOperations(int A[], int l, int h);

unsigned long numoperations = 0;

int main()
{
    ofstream myfile;
    myfile.open ("output.csv");
    srand(time(NULL));
    for(int i = 0; i < 10; i++){
        int test_array[10000];
        for(int j = 0; j < 10000; j++){
            test_array[j] = rand()%1000;
        }
        clock_t ticks = clock();
        int median_value = BruteForceMedian_BasicOperations(test_array, 10000);
        ticks = clock() - ticks;
        myfile << "10000" << "," << numoperations << "," << ticks << "\n";
    }
    myfile.close();

    /*
    int ordered_array[10] = {1,2,3,4,5,6,7,8,9,10}; // 5 for BruteForceMedian, 6 for Median
    int unordered_array[10] = {7,3,10,4,1,8,2,5,9,6}; // 5 for BruteForceMedian, 6 for Median

    clock_t ticks = clock();
    int brute_ordered = BruteForceMedian_BasicOperations(ordered_array, 10);
    ticks = clock() - ticks;
    cout << brute_ordered << endl;
    cout << numoperations << endl;
    cout << ticks << endl << endl;

    ticks = clock();
    int brute_unordered = BruteForceMedian_BasicOperations(unordered_array, 10);
    ticks = clock() - ticks;
    cout << brute_unordered << endl;
    cout << numoperations << endl;
    cout << ticks << endl << endl;

    ticks = clock();
    int median_ordered = Median_BasicOperations(ordered_array, 10);
    ticks = clock() - ticks;
    cout << median_ordered << endl;
    cout << numoperations << endl;
    cout << ticks << endl << endl;

    ticks = clock();
    int median_unordered = Median_BasicOperations(unordered_array, 10);
    ticks = clock() - ticks;
    cout << median_unordered << endl;
    cout << numoperations << endl;
    cout << ticks << endl << endl;
    */

    return 0;
}

int BruteForceMedian_BasicOperations(int A[], int n){
    numoperations = 0;
    int k = ceil((float)n/2);
    for(int i = 0; i <= n-1; i++){
        int numsmaller = 0;
        int numequal = 0;
        for(int j = 0; j <= n-1; j++){
            numoperations++; // Increment Basic Operation Count Here
            if(A[j] < A[i]){ // This is the Basic Operation
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

int Median_BasicOperations(int A[], int n){
    numoperations = 0;
    if(n == 1){
        return A[0];
    } else {
        Select_BasicOperations(A, 0, floor((float)n/2), n-1);
    }
}

int Select_BasicOperations(int A[], int l, int m, int h){
    int pos = Partition_BasicOperations(A, l, h);
    if(pos == m){
        return A[pos];
    }
    if(pos > m){
        return Select_BasicOperations(A, l, m, pos-1);
    }
    if(pos < m){
        return Select_BasicOperations(A, pos+1, m, h);
    }
}

int Partition_BasicOperations(int A[], int l, int h){
    int pivotval = A[l];
    int pivotloc = l;
    for(int j = l+1; j <= h; j++){
        numoperations++; // Increment Basic Operation Count Here
        if(A[j] < pivotval){ // This is the Basic Operation
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
