//
// Created by Alexandru Brisan on 5/2/17.
//

#ifndef TEST_BUILD_DYNAMICARRAY_H
#define TEST_BUILD_DYNAMICARRAY_H

#include <iostream>

namespace Inf2B{

    template<typename T>
    class DynamicArray{
        T *arr;
        int N;
        int currpos;
    public:
        DynamicArray();
        ~DynamicArray();
        T elemAtRank(int r);
        void replaceAtRank(int r, T e);
        void insertLast(T e);
        void printArray();
    };

    template<typename T>
    DynamicArray<T>::DynamicArray() {
        arr = new T[1];
        currpos = 0;
        N = 1;
    }

    template<typename T>
    DynamicArray<T>::~DynamicArray() {
        delete[] arr;
    }

    template<typename T>
    T DynamicArray<T>::elemAtRank(int r) {
        return arr[r];
    }

    template<typename T>
    void DynamicArray<T>::replaceAtRank(int r, T e) {
        arr[r] = e;
    }

    template<typename T>
    void DynamicArray<T>::insertLast(T e) {
        if(currpos < N){
            arr[currpos] = e;
            ++currpos;
            return;
        }
        N = 2*N+1;
        T *new_arr = new T[N];
        for(int i = 0 ; i < currpos ; ++i){
            new_arr[i] = arr[i];
        }
        new_arr[currpos] = e;
        ++currpos;
        delete[] arr;
        arr = new_arr;
    }

    template<typename T>
    void DynamicArray<T>::printArray() {
        for(int i = 0 ; i < currpos ; ++i){
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

}


#endif //TEST_BUILD_DYNAMICARRAY_H
