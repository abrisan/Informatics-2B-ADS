//
// Created by Alexandru Brisan on 5/3/17.
//
#include "Sort.h"
#include "../General.h"
#include "../Note3/DynamicArray.h"
#include "Note7.h"
#include <iostream>
#include <chrono>
#include "../Note2/Note2.h"

#define MAX_ELEMENT_SIZE 1024

using namespace Inf2B;
using namespace std;
using namespace std::chrono;

int main(){

    int *random_arr = new int[1000];
    int *sorted_arr = new int[1000];
    int *max_sort_1 = new int[1000];

    for(int i = 0 ; i < 1000 ; ++i){
        random_arr[i] = rand() % MAX_ELEMENT_SIZE;
        sorted_arr[i] = i;
        max_sort_1[i] = i;
    }

    high_resolution_clock::time_point before_s1 = high_resolution_clock::now();
    quick_sort(random_arr, 0, 1000, &integer_comparator);
    high_resolution_clock::time_point after_s1 = high_resolution_clock::now();

    high_resolution_clock::time_point before_s2 = high_resolution_clock::now();
    quick_sort(sorted_arr,0,1000,&integer_comparator);
    high_resolution_clock::time_point after_s2 = high_resolution_clock::now();

    high_resolution_clock::time_point before_s3 = high_resolution_clock::now();
    max_sort(max_sort_1, &integer_comparator, 1000);
    high_resolution_clock::time_point after_s3 = high_resolution_clock::now();


    auto dur1 = duration_cast<microseconds>(after_s1-before_s1).count();

    auto dur2 = duration_cast<microseconds>(after_s2-before_s2).count();

    auto dur3 = duration_cast<microseconds>(after_s3-before_s3).count();

    cout << "(Quicksort) Random array took " << dur1 << " microseconds" << endl;
    cout << "(Quicksort) Sorted array took " << dur2 << " microseconds" << endl;
    cout << "(Insertion Sort) Sorted array took " << dur3 << " microseconds" << endl;

    return 0;

}

