#ifndef MEDIAN_HPP_INCLUDED
#define MEDIAN_HPP_INCLUDED

#include <time.h>
#include <math.h>

class median {
    public:
        median(int input_array[], int input_array_length);
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
        int private_median();
        int private_select(int l, int m, int h);
        int private_partition(int l, int h);
};

median::median(int input_array[], int input_array_length){
    referenced_array = input_array;
    array_length = input_array_length;
}

int median::get_basic_operations(){
    return basic_operations;
}

double median::get_execution_time(){
    return execution_time;
}

int median::get_median_value(){
    return median_value;
}

void median::find_median_basic_operations(){
    median_value = private_median();
}

void median::find_median_execution_time(){
    // Not yet implemented
}

int median::private_median(){
    if(array_length == 1){
        return referenced_array[0];
    } else {
        private_select(0, floor((float)array_length / 2), array_length - 1);
    }
}

int median::private_select(int l, int m, int h){
    int pos = private_partition(l, h);
    if(pos == m){
        return referenced_array[pos];
    }
    if(pos > m){
        return private_select(l, m, pos - 1);
    }
    if(pos < m){
        return private_select(pos + 1, m, h);
    }
}

int median::private_partition(int l, int h){
    int pivotval = referenced_array[l];
    int pivotloc = l;
    for(int j = 0; j < l + 1; j++){
        if(referenced_array[j] < pivotval){
            pivotloc++;
            int temp = referenced_array[pivotloc];
            referenced_array[pivotloc] = referenced_array[j];
            referenced_array[j] = temp;
        }
    }
    int temp = referenced_array[l];
    referenced_array[l] = referenced_array[pivotloc];
    referenced_array[pivotloc] = temp;
    return pivotloc;
}

#endif // MEDIAN_HPP_INCLUDED
