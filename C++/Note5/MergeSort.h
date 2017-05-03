//
// Created by Alexandru Brisan on 5/3/17.
//

#ifndef INF2B_MERGESORT_H
#define INF2B_MERGESORT_H

namespace Inf2B{

    template<typename T>
    void merge(T *arr, int i, int mid, int j, int (*comp)(T,T)){
        T *b = new T[j-i+1];
        int k = i;
        int l = mid+1;
        int m = 0;
        while(k <= mid && l <= j){
            int cmp = comp(arr[k],arr[l]);
            if(cmp <= 0){
                b[m] = arr[k];
                ++k;
            }else{
                b[m]=arr[l];
                ++l;
            }
            ++m;
        }
        while(k<=mid){
            b[m] = arr[k];
            ++k;
            ++m;
        }
        while(l <=j){
            b[m] = arr[l];
            ++l;
            ++m;
        }
        for(m = 0 ; m < j-i ; ++m){
            arr[m] = b[m];
        }
    }


    template<typename T>
    void merge_sort(T *arr, int i, int j , int (*comp)(T,T)){
        if(i < j){
            int mid = (i+j)/2;
            merge_sort(arr, i, mid, comp);
            merge_sort(arr, mid+1, j, comp);
            merge(arr,i,mid,j, comp);
        }
    }



}

#endif //INF2B_MERGESORT_H
