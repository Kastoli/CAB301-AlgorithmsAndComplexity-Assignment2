#ifndef BRUTE_FORCE_MEDIAN_HPP_INCLUDED
#define BRUTE_FORCE_MEDIAN_HPP_INCLUDED

#include <time.h>

class brute_force_median {
    public:
        brute_force_median(int input_array[], int input_array_length);
        int get_basic_operations();
        double get_execution_time();
        int get_median_value();
        void find_median_basic_operations();
        void find_median_execution_time();

    private:
        int * referenced_array;
        int array_length;
        int basic_operations;
        double execution_time;
        int median_value;
};

brute_force_median::brute_force_median(int input_array[], int input_array_length){
    referenced_array = input_array;
    array_length = input_array_length;
}

int brute_force_median::get_basic_operations(){
    return basic_operations;
}

double brute_force_median::get_execution_time(){
    return execution_time;
}

int brute_force_median::get_median_value(){
    return median_value;
}

void brute_force_median::find_median_basic_operations(){
    int num_basic_operations = 0;
    int k = (array_length + 1) / 2;  // k = Ceiling Half-Way Point, + 1 for Ceiling Value (Integer Divison)
    for(int i = 0; i < array_length; i++){
        int num_smaller = 0;
        int num_equal = 0;
        for(int j = 0; j < array_length; j++){
            num_basic_operations++;  // Incrememnt the basic operation here
            if(referenced_array[j] < referenced_array[i]){  // I think this is the basic operation.
                num_smaller++;
            } else if(referenced_array[j] == referenced_array[i]) {
                num_equal++;
            }
        }
        if(num_smaller < k && k <= (num_smaller + num_equal)){
            median_value = referenced_array[i];
            basic_operations = num_basic_operations;
        }
    }
}

void brute_force_median::find_median_execution_time(){
    clock_t ticks = clock();
    int k = (array_length + 1) / 2; // k = Ceiling Half-Way Point, + 1 for Ceiling Value (Integer Divison)
    for(int i = 0; i < array_length; i++){
        int num_smaller = 0;
        int num_equal = 0;
        for(int j = 0; j < array_length; j++){
            if(referenced_array[j] < referenced_array[i]){
                num_smaller++;
            } else if(referenced_array[j] == referenced_array[i]) {
                num_equal++;
            }
        }
        if(num_smaller < k && k <= (num_smaller + num_equal)){
            median_value = referenced_array[i];
        }
    }
    ticks = clock() - ticks;
    execution_time = ticks;
}

#endif // BRUTE_FORCE_MEDIAN_HPP_INCLUDED
