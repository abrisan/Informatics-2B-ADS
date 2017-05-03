//
// Created by Alexandru Brisan on 5/3/17.
//

#include "MergeSort.h"
#include "../General.h"
#include "../Note2/Note2.h"
#include <iostream>
#include <chrono>


using namespace Inf2B;
using namespace std;
using namespace std::chrono;

int main(){

    int N;

    cout << "Please insert array dimension" << endl;

    cin >> N;

    int max_dim;

    cout << "Please insert max size of element" << endl;

    cin >> max_dim;

    int *arr = new int[N];
    int *arr2 = new int[N];

    for(int i = 0 ; i < N ; ++i){
        arr[i] = rand() % max_dim + 1;
        arr2[i] = arr[i];
    }

    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    insertion_sort(arr,&integer_comparator, N);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    high_resolution_clock::time_point t3 = high_resolution_clock::now();
    merge_sort(arr2, 0, N, &integer_comparator);
    high_resolution_clock::time_point t4 = high_resolution_clock::now();


    auto insertion_sort_length = duration_cast<microseconds>(t2-t1).count();
    auto merge_sort_length = duration_cast<microseconds>(t4-t3).count();

    cout << "Insertion sort ran in : " << insertion_sort_length << " microseconds" << endl;
    cout << "Merge sort ran in : " << merge_sort_length << " microseconds";


    delete[] arr;
    delete[] arr2;

}
