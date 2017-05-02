//
// Created by Alexandru Brisan on 5/2/17.
//

#ifndef TEST_BUILD_GENERAL_H
#define TEST_BUILD_GENERAL_H

#include <iostream>

namespace Inf2B{

    int integer_comparator(int i1, int i2){
        return i1-i2;
    }

    // helper function to visualise array
    template<typename T>
    void display_array(T *arr, int N){
        for(int i = 0 ; i < N ; ++i){
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

}

#endif //TEST_BUILD_GENERAL_H
