#include <iostream>
#include "bruteForceMedian.hpp"

using namespace std;

int bruteForceMedian(int inputArray[], int arrayLength);

int bruteForceMedianTesting();

int main()
{
    bruteForceMedianTesting();

    return 0;
}

int bruteForceMedianTesting(){
    cout << "Expected Output: ";
    cout << "8" << endl;
    cout << "Actual Output: ";
    int myArray[9] = {4,1,10,9,7,12,8,2,15};
    int output = bruteForceMedian(myArray, 9);
    cout << output << endl;

    cout << "Expected Output: ";
    cout << "5" << endl;
    cout << "Actual Output: ";
    int myArrayTwo[9] = {1,2,3,4,5,6,7,8,9};
    output = bruteForceMedian(myArrayTwo, 9);
    cout << output << endl;

    cout << "Expected Output: ";
    cout << "9" << endl;
    cout << "Actual Output: ";
    int myArrayThree[9] = {2,7,11,15,26,3,2,9,15};
    output = bruteForceMedian(myArrayThree, 9);
    cout << output << endl;

    return 0;
}
