//
// Created by Alexandru Brisan on 5/2/17.
//

#ifndef TEST_BUILD_VECTOR_H
#define TEST_BUILD_VECTOR_H

#include <cstring>
#include <iostream>
#include <cstdlib>

using namespace std;

namespace Inf2B {


    template<typename T>
    class Vector {

        T *arr;
        int length;

    public:
        Vector();

        ~Vector();

        T elemAtRank(int r);

        void replaceAtRank(int r, T e);

        void insertAtRank(int r, T e);

        void removeAtRank(int r);

        int size();

        void display_vector();
    };

    template<typename T>
    Vector<T>::Vector(){
        arr = new T[16];
        length = 0;
    }

    template<typename T>
    Vector<T>::~Vector(){
        delete[] arr;
    }

    template<typename T>
    T Vector<T>::elemAtRank(int r) {
        return arr[r];
    } // Algorithm 3.3

    template<typename T>
    void Vector<T>::replaceAtRank(int r, T e) {
        // this will leak if T is a ref type
        // however in order to stick to the implementation given in the lectures
        // we shall not care
        arr[r] = e;
    } // Algorithm 3.4

    template<typename T>
    void Vector<T>::insertAtRank(int r, T e) {
        for (int i = length - 1; i > r; --i) {
            arr[i] = arr[i - 1];
        }
        arr[r] = e;
        ++length;
    } // Algorithm 3.6

    template<typename T>
    void Vector<T>::removeAtRank(int r) {
        for (int i = r; i < length - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        --length;
    }// Algorithm 3.7

    template<typename T>
    int Vector<T>::size() {
        return length;
    } // Algorithm 3.5

    template<typename T>
    void Vector<T>::display_vector() {
        if(this->length == 0) {
            std::cout << "Empty vector." << std::endl;
            return;
        }
        for (int i = 0; i < this->length; ++i) {
            std::cout << this->arr[i] << " ";
        }
        std::cout << std::endl;
    }

}
#endif //TEST_BUILD_NOTE3_H
