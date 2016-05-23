#include <iostream>

#include "BruteForceMedian.hpp"
#include "Median.hpp"

using namespace std;

int main()
{
    int ordered_array[10] = {1,2,3,4,5,6,7,8,9,10}; // 5 for BruteForceMedian, 6 for Median
    int unordered_array[11] = {7,3,10,4,1,8,2,5,9,6,11}; // 5 for BruteForceMedian, 6 for Median

    unsigned long basic_operations = 0;

    int brute_ordered = BruteForceMedian_BasicOperations(ordered_array, 10, basic_operations);
    int brute_unordered = BruteForceMedian_BasicOperations(unordered_array, 11, basic_operations);
    int median_ordered = Median(ordered_array, 10);
    int median_unordered = Median(unordered_array, 10);

    cout << brute_ordered << endl;
    cout << basic_operations << endl;

    cout << brute_unordered << endl;
    cout << basic_operations << endl;

    cout << median_ordered << endl;
    cout << median_unordered << endl;

    return 0;
}
