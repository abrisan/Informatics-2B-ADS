//
// Created by Alexandru Brisan on 5/3/17.
//

#ifndef INF2B_NOTE7_H
#define INF2B_NOTE7_H

#include <cmath>
#include "../General.h"
#include "../Note3/DynamicArray.h"

namespace Inf2B{

    template<typename T>
    class Heap{
        T *arr;
        int capacity;
        int insert_at;
        int (*comp)(T,T);
    public:
        Heap(int init_size, int (*comp)(T,T));
        ~Heap();
        void insertItem(T t);
        T maxElement();
        T removeMaxElement();
        bool isEmpty();
        void displayHeap();
    };


    template<typename T>
    Heap<T>::Heap(int init_size, int (*cmp)(T, T)) {
        comp = cmp;
        arr = new T[init_size];
        insert_at = 0;
        capacity = init_size;
    }

    template<typename T>
    Heap<T>::~Heap(){
        delete[] arr;
    }

    template<typename T>
    void heapify(T *arr, int N, int v,int (*comp)(T,T)){
        int s;
        if(2*v+2 < N){
            if(comp(arr[2*v+1],arr[v]) > 0){
                s = 2*v+1;
            }else{
                s = v;
            }
            if(comp(arr[2*v+2],arr[s]) > 0){
                s = 2*v+2;
            }
        }else if(2*v+1 < N){
            if(comp(arr[2*v+1],arr[v]) > 0){
                s = 2*v+1;
            }
        }else{
            return;
        }
        if(comp(arr[s],arr[v])!=0){
            T cop = arr[s];
            arr[s] = arr[v];
            arr[v] = cop;
            heapify(arr, N, s, comp);
        }
    }


    template<typename T>
    void build_heap(T *arr, int N, int (*comp)(T,T)){
        for(int v = (int) floor((N-2)/2) ; v >= 0 ; --v){
            heapify(arr, N, comp);
        }
    }


    template<typename T>
    void Heap<T>::insertItem(T t) {
        if(insert_at < capacity){
            arr[insert_at] = t;
            ++insert_at;
        }else{
            capacity = capacity * 2 + 1;
            T *new_arr = new T[capacity];
            for(int i = 0 ; i < insert_at ; ++i){
                new_arr[i] = arr[i];
            }
            new_arr[insert_at] = t;
            ++insert_at;
            delete[] arr;
            arr = new_arr;
        }
        int j = insert_at - 1;
        while(j > 0){
            int cop = j;
            j = (j-1)/2;
            if(arr[cop] > arr[j]){
                T cop1 = arr[cop];
                arr[cop] = arr[j];
                arr[j] = cop1;
            }
        }
    }

    template<typename T>
    T Heap<T>::maxElement() {
        return arr[0];
    }

    template<typename T>
    T Heap<T>::removeMaxElement() {
        T max = arr[0];
        arr[0] = arr[insert_at-1];
        --insert_at;
        heapify(arr, insert_at, 0, comp);
    }

    template<typename T>
    bool Heap<T>::isEmpty() {
        return insert_at == 0;
    }

    template<typename T>
    void Heap<T>::displayHeap(){
        for(int i = 0 ; i < insert_at ; ++i){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

}

#endif //INF2B_NOTE7_H
