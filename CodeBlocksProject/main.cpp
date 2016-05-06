#include <iostream>
#include "bruteForceMedian.hpp"

using namespace std;

int bruteForceMedian(int inputArray[], int arrayLength);

int main()
{
    cout << "Expected Output" << endl;
    cout << "5" << endl;
    cout << "Actual Output" << endl;
    int myArray[10] = {1,2,3,4,5,6,7,8,9,10};
    int output = bruteForceMedian(myArray, 10);
    cout << output << endl;

    return 0;
}
