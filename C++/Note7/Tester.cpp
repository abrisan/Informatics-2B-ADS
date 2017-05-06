//
// Created by Alexandru Brisan on 5/3/17.
//
#include "Sort.h"
#include "../General.h"
#include "../Note3/DynamicArray.h"
#include "Note7.h"
#include <iostream>

using namespace Inf2B;

int main(){
    Heap<int> hp(10, &integer_comparator);

    for(int i = 0 ; i < 12 ; ++i){
        hp.insertItem(i);
    }

    hp.displayHeap();

    return 0;

}

