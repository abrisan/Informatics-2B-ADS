#include <iostream>
#include <cmath>
#include <chrono>
#include "Note1.h"

using namespace std;
using namespace Inf2B;
using namespace std::chrono;

int comp(int n1, int n2){
    return n1-n2;
}


int main(){

    cout << "Please indicate size of array" << endl;

    int N;

    cin >> N;

    cout << "Please indicate approx position of target element" << endl;

    int approx_target;

    cin >> approx_target;

    int target = approx_target + (int) ceil((rand() % (N/1000)));

    cout << "Target is at index : " << target << endl;

    int *arr = new int[N];

    for(int i = 0 ; i < N ; ++i){
        arr[i] = i;
    }

    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    int lin_search_result = lin_search(arr, target, &comp, N);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    high_resolution_clock::time_point t3 = high_resolution_clock::now();
    int bin_search_result = bin_search(arr, target, &comp, 0, N);
    high_resolution_clock::time_point t4 = high_resolution_clock::now();

    auto duration_lin_search = duration_cast<microseconds>(t2-t1).count();
    auto duration_bin_search = duration_cast<microseconds>(t4-t3).count();

    cout << "LinSearch Yields : " << lin_search_result << " in " << duration_lin_search << " microseconds" << endl;
    cout << "BinSearch Yields : " << bin_search_result << " in " << duration_bin_search << " microseconds" << endl;

    delete[] arr;

}

