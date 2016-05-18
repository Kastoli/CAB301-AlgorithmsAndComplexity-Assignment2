#include <iostream>
#include <cstdlib>
#include "brute_force_median.hpp"
#include "median.hpp"

using namespace std;

int main()
{
    /*
    time_t seconds;
    time(&seconds);
    srand((unsigned int) seconds);
    int array_size = 10000;
    int my_array[array_size];
    for(int i = 0; i < array_size; i++){
        my_array[i] = rand();
    }
    */

    int my_array[4] = {1,2,3,4};

    /*
    brute_force_median my_median(my_array, array_size);
    my_median.find_median_basic_operations();
    my_median.find_median_execution_time();
    int median_value = my_median.get_median_value();
    int basic_operations = my_median.get_basic_operations();
    int execution_time = my_median.get_execution_time();
    */

    median my_median(my_array, 4);
    my_median.find_median_basic_operations();
    int median_value = my_median.get_median_value();

    cout << "Median Value: " << median_value << endl;

    brute_force_median brute_median(my_array, 4);
    brute_median.find_median_basic_operations();
    median_value = brute_median.get_median_value();

    cout << "Median Value: " << median_value << endl;
    //cout << "Basic Operations: " << basic_operations << endl;
    //cout << "Execution Time: " << execution_time << endl;

    return 0;
}
