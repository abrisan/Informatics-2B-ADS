//
// Created by Alexandru Brisan on 5/6/17.
//

#ifndef INF2B_SORT_H
#define INF2B_SORT_H

#include <iostream>

namespace Inf2B{

    using namespace std;

    template<typename T>
    int partition(T *arr, int i, int j, int (*comp)(T,T)){
        T pivot = arr[i];
        int p = i-1;
        int q = j+1;
        while(true){
            do {q--;} while(comp(arr[q],pivot) > 0);
            do {p++;} while(comp(arr[p],pivot) < 0);
            if(p < q){
                T tmp = arr[p];
                arr[p] = arr[q];
                arr[q] = tmp;
            } else{
                return q;
            }

        }
    }


    template<typename T>
    void quick_sort(T *arr, int i, int j,int (*comp)(T,T)){
        if(i<j){
            int split = partition(arr,i,j,comp);
            quick_sort(arr,i,split-1,comp);
            quick_sort(arr,split+1,j,comp);
        }
    }
}


#endif //INF2B_SORT_H
