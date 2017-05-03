//
// Created by Alexandru Brisan on 5/2/17.
//

#ifndef TEST_BUILD_GENERAL_H
#define TEST_BUILD_GENERAL_H

#include <iostream>
#include <utility>

namespace Inf2B{

#ifndef NO_SUCH_KEY
#define NO_SUCH_KEY nullptr
#endif


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

    std::string to_string(std::pair<int,int> pr){
        return std::to_string(pr.second);
    }

}

#endif //TEST_BUILD_GENERAL_H
