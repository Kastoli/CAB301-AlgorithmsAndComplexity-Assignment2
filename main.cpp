#include <iostream>
#include <cstdlib>
#include "brute_force_median.hpp"

using namespace std;

int main()
{
    time_t seconds;
    time(&seconds);
    srand((unsigned int) seconds);
    int my_array[10000];
    for(int i = 0; i < 10000; i++){
        my_array[i] = rand();
    }

    brute_force_median my_median(my_array, 10000);
    my_median.find_median_basic_operations();
    my_median.find_median_execution_time();
    int median_value = my_median.get_median_value();
    int basic_operations = my_median.get_basic_operations();
    int execution_time = my_median.get_execution_time();

    cout << "Median Value: " << median_value << endl;
    cout << "Basic Operations: " << basic_operations << endl;
    cout << "Execution Time: " << execution_time << endl;
    return 0;
}
