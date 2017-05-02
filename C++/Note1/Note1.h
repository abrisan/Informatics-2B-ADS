//
// Created by Alexandru Brisan on 5/2/17.
//

#ifndef INFORMATICS_2B_ADS_NOTE1_H
#define INFORMATICS_2B_ADS_NOTE1_H

namespace Inf2B {

    template<typename T>
    int lin_search(T *arr, T target, int (*comp)(T, T), int N) {
        for (int i = 0; i < N; ++i) {
            if (!comp(arr[i], target))
                return i;
        }
        return -1;
    }

    template<typename T>
    int bin_search(T *arr, T target, int (*comp)(T,T), int i1, int i2){
        if(i2 < i1)
            return -1;
        int j = (i1+i2)/2;
        int comparison = comp(target, arr[j]);
        if(comparison == 0)
            return j;
        else if(comparison < 0)
            return bin_search(arr, target, comp, i1, j-1);
        else
            return bin_search(arr, target, comp, j+1, i2);
    }

}
#endif //INFORMATICS_2B_ADS_NOTE1_H
