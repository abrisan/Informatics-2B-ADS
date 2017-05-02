//
// Created by Alexandru Brisan on 5/2/17.
//
#include <iostream>
#include "Note2.h"
#include "../General.h"


using namespace std;
using namespace Inf2B;
using namespace std::chrono;

int main(){

    int N, max_size;
    cout << "Please specify array size" << endl;

    cin >> N;

    cout << "Please specify upper bound on array element" << endl;
    cin >> max_size;

    int *arr = new int[N];
    int *arr2 = new int[N];

    for(int i = 0 ; i < N ; ++i){
        arr[i] = rand() % max_size + 1;
        arr2[i] = arr[i];
    }

    cout << "Executing insertion sort" << endl;

    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    insertion_sort(arr, &integer_comparator, N);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    cout << "Executing max sort" << endl << endl;


    high_resolution_clock::time_point t3 = high_resolution_clock::now();
    max_sort(arr, &integer_comparator, N);
    high_resolution_clock::time_point t4 = high_resolution_clock::now();

    auto runtime_insertion_sort = duration_cast<microseconds>(t2-t1).count();
    auto runtime_max_sort = duration_cast<microseconds>(t4-t3).count();

    cout << "Insertion sort runtime : " << runtime_insertion_sort << " microseconds" << endl;
    cout << "Max sort runtime       : " << runtime_max_sort << " microseconds" << endl << endl;

    cout << "Max sort is " << (double) runtime_max_sort/runtime_insertion_sort << " slower than insertion sort" << endl;

    delete[] arr;
    delete[] arr2;

    return 0;

}
