//
// Created by Alexandru Brisan on 5/2/17.
//

#ifndef TEST_BUILD_NOTE2_H_H
#define TEST_BUILD_NOTE2_H_H

namespace Inf2B{

    template<typename T>
    void insertion_sort(T *arr, int (*comp)(T,T), int N){
        for(int j = 1 ; j < N ; ++j){
            T a = arr[j];
            int i = j-1;
            while(i >= 0 && comp(arr[i],a) > 0){
                arr[i+1] = arr[i];
                i--;
            }
            arr[i+1] = a;
        }
    }

    template<typename T> inline void exchange(T *arr, int i1, int i2){
        T cop = arr[i1];
        arr[i1] = arr[i2];
        arr[i2] = cop;
    }

    template<typename T>
    void max_sort(T *arr, int (*comp)(T,T), int N){
        for(int j = N-1 ; j > 0 ; --j){
            int m = 0;
            for(int i = 1 ; i < j ; ++i){
                if(comp(arr[i],arr[j+1]) > 0)
                    m = i;
            }
            exchange(arr, m, j);
        }
    }
}

#endif //TEST_BUILD_NOTE2_H_H
