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

    int my_array[5] = {1,2,3,4,5};
    int second_array[4] = {1,2,3,4};

    /*
    brute_force_median my_median(my_array, array_size);
    my_median.find_median_basic_operations();
    my_median.find_median_execution_time();
    int median_value = my_median.get_median_value();
    int basic_operations = my_median.get_basic_operations();
    int execution_time = my_median.get_execution_time();
    */

    for(int i = 0; i < 5; i++){
        cout << my_array[i] << " ";
    }
    cout << endl;

    median my_median(my_array, 5);
    my_median.find_median_basic_operations();
    int median_value = my_median.get_median_value();
    cout << "Array: {1,2,[3],4,5}" << endl;
    cout << "Median Value: " << median_value << endl << endl;

    for(int i = 0; i < 5; i++){
        cout << my_array[i] << " ";
    }
    cout << endl;

    //brute_force_median brute_median(my_array, 5);
    //brute_median.find_median_basic_operations();
    //median_value = brute_median.get_median_value();
    //cout << "Array: {1,2,[3],4,5}" << endl;
    //cout << "Brute Value: " << median_value << endl << endl;

    for(int i = 0; i < 4; i++){
        cout << second_array[i] << " ";
    }
    cout << endl;

    median second_median(second_array, 4);
    second_median.find_median_basic_operations();
    median_value = second_median.get_median_value();
    cout << "Array: {1,2,[3],4}" << endl;
    cout << "Median Value: " << median_value << endl << endl;

    for(int i = 0; i < 4; i++){
        cout << second_array[i] << " ";
    }
    cout << endl;

    //brute_force_median second_brute_median(second_array, 4);
    //second_brute_median.find_median_basic_operations();
    //median_value = second_brute_median.get_median_value();
    //cout << "Array: {1,[2],3,4}" << endl;
    //cout << "Brute Value: " << median_value << endl << endl;
    //cout << "Basic Operations: " << basic_operations << endl;
    //cout << "Execution Time: " << execution_time << endl;

    int third_array[10] = {1,2,3,4,5,6,7,8,9,10};

    int my_array_length = 10;
    for(int i = 0; i < my_array_length; i++){
        cout << third_array[i] << " ";
    }
    cout << endl;

    median third_median(third_array, my_array_length);
    third_median.find_median_basic_operations();
    median_value = third_median.get_median_value();
    cout << "Array: {1,2,3,4,5,[6],7,8,9,10}" << endl;
    cout << "Median Value: " << median_value << endl << endl;

    for(int i = 0; i < my_array_length; i++){
        cout << third_array[i] << " ";
    }
    cout << endl;

    return 0;
}
