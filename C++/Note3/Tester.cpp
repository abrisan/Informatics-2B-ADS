//
// Created by Alexandru Brisan on 5/2/17.
//
#include "Vector.h"
#include "List.h"
#include "DynamicArray.h"

using namespace Inf2B;

int main(){


    DynamicArray<int> arr;

    for(int i = 0 ; i < 2000 ; ++i){
        arr.insertLast(i);
        // arr.printArray();
    }
    return 0;
}

