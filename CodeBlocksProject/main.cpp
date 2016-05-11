#include <iostream>
#include <cstdlib>
#include <time.h>
#include "bruteForceMedian.hpp"

using namespace std;

int bruteForceMedian(int inputArray[], int arrayLength);

int bruteForceMedianTesting();
int bruteForceMedianBasicOperationsTesting();
int bruteForceMedianTestingExecutionTime();

int main()
{
    cout << "Brute Force Median - Test 1 - Does it work?" << endl;
    bruteForceMedianTesting();
    cout << "" << endl;
    cout << "Brute Force Median - Test 2 - Number of basic operations" << endl;
    bruteForceMedianBasicOperationsTesting();
    cout << "" << endl;
    cout << "Brute Force Median - Test 3 - Number of clock ticks" << endl;
    bruteForceMedianTestingExecutionTime();

    return 0;
}

int bruteForceMedianTesting(){
    cout << "Expected Output: ";
    cout << "8" << endl;
    cout << "Actual Output: ";
    int myArray[9] = {4,1,10,9,7,12,8,2,15};
    int output = bruteForceMedian(myArray, 9);
    cout << output << endl;

    return 0;
}

int bruteForceMedianBasicOperationsTesting(){
    int numBasicOperations[1];
    int output;
    cout << "Expected Output: ";
    cout << "8" << endl;
    cout << "Actual Output: ";
    int myArray[9] = {4,1,10,9,7,12,8,2,15};
    output = bruteForceMedianBasicOperations(myArray, 9, numBasicOperations);
    cout << output << endl;
    cout << "No. of Basic Operations: ";
    cout << numBasicOperations[0] << endl;

    return 0;
}

int bruteForceMedianTestingExecutionTime(){
    time_t seconds;
    time(&seconds);
    srand((unsigned int) seconds);
    int myArray[100000];
    cout << "Median Number: ";
    for(int i = 0; i < 100000; i++){
        myArray[i] = rand();
    }
    clock_t ticks = clock();
    int output = bruteForceMedian(myArray, 100000);
    ticks = clock() - ticks;
    cout << output << endl;
    cout << "No. of Clock Ticks: ";
    cout << ticks << endl;

    return 0;
}
