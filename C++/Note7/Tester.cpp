//
// Created by Alexandru Brisan on 5/3/17.
//
#include "Sort.h"
#include "../General.h"
#include "../Note3/DynamicArray.h"
#include <iostream>

using namespace Inf2B;

int main(){

    int arr[] = {1,2,3,4,5};

    quick_sort(arr,0,4,&integer_comparator);

    display_array(arr, 5);

    return 0;

}

