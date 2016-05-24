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

unsigned long num_operations = 0;

int main()
{
    int num_of_arrays = 100;
    int size_of_arrays = 100;
    int number_of_steps = 1000;
    int size_of_steps = 100;

    ofstream my_file;
    my_file.open ("output.csv");

    srand(time(NULL));

    for(int k = 0; k < number_of_steps; k++){;
        int average_aray[3][num_of_arrays];
        for(int i = 0; i < num_of_arrays; i++){
            int test_array[size_of_arrays];
            for(int j = 0; j < size_of_arrays; j++){
                test_array[j] = rand()&1000;
            }
            clock_t ticks = clock();
            int median_value = BruteForceMedian_BasicOperations(test_array, size_of_arrays);
            ticks = clock() - ticks;
            // my_file << size_of_arrays << "," << num_operations << "," << ticks << "\n";
            // add to array
            average_aray[0][i] = size_of_arrays;
            average_aray[1][i] = num_operations;
            average_aray[2][i] = ticks;
        }
        // average array
        // output average to file
        for(int i = 0; i < 3; i++){
            long long total = 0;
            for(int j = 0; j < num_of_arrays; j++){
                total += average_aray[i][j];
            }
            long double average = total / num_of_arrays;
            my_file << average;
            if(i == 2){
                my_file << "\n";
            } else {
                my_file << ",";
            }
        }
        size_of_arrays += size_of_steps;
    }

    my_file.close();

//    int ordered_array[10] = {1,2,3,4,5,6,7,8,9,10}; // 5 for BruteForceMedian, 6 for Median
//    int unordered_array[10] = {7,3,10,4,1,8,2,5,9,6}; // 5 for BruteForceMedian, 6 for Median
//
//    clock_t ticks = clock();
//    int brute_ordered = BruteForceMedian_BasicOperations(ordered_array, 10);
//    ticks = clock() - ticks;
//    cout << brute_ordered << endl;
//    cout << numoperations << endl;
//    cout << ticks << endl << endl;
//
//    ticks = clock();
//    int brute_unordered = BruteForceMedian_BasicOperations(unordered_array, 10);
//    ticks = clock() - ticks;
//    cout << brute_unordered << endl;
//    cout << numoperations << endl;
//    cout << ticks << endl << endl;
//
//    ticks = clock();
//    int median_ordered = Median_BasicOperations(ordered_array, 10);
//    ticks = clock() - ticks;
//    cout << median_ordered << endl;
//    cout << numoperations << endl;
//    cout << ticks << endl << endl;
//
//    ticks = clock();
//    int median_unordered = Median_BasicOperations(unordered_array, 10);
//    ticks = clock() - ticks;
//    cout << median_unordered << endl;
//    cout << numoperations << endl;
//    cout << ticks << endl << endl;

    return 0;
}

int BruteForceMedian_BasicOperations(int A[], int n){
    num_operations = 0;
    int k = ceil((float)n/2);
    for(int i = 0; i <= n-1; i++){
        int numsmaller = 0;
        int numequal = 0;
        for(int j = 0; j <= n-1; j++){
            num_operations++; // Increment Basic Operation Count Here
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
    num_operations = 0;
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
        num_operations++; // Increment Basic Operation Count Here
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
