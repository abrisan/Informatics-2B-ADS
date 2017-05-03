//
// Created by Alexandru Brisan on 5/2/17.
//

#ifndef TEST_BUILD_GENERAL_H
#define TEST_BUILD_GENERAL_H

#include <iostream>
#include <utility>

namespace Inf2B{

    using namespace std;

    template<typename K, typename V>
    class KVPair {
        K k;
        V v;
    public:
        KVPair();

        KVPair(K k, V v);

        bool operator==(KVPair<K, V> p2);

        K key();

        V value();
};


    template<typename K, typename V>
    KVPair<K,V>::KVPair() {}

    template<typename K, typename V>
    KVPair<K,V>::KVPair(K k1, V v1) {
        k = k1;
        v = v1;
    }

    template<typename K, typename V>
    bool KVPair<K,V>::operator==(KVPair<K, V> p2) {
        return k == p2.k;
    }

    template<typename K, typename V>
    K KVPair<K,V>::key() {
        return k;
    }

    template<typename K, typename V>
    V KVPair<K,V>::value() {
        return v;
    }

    int integer_comparator(int i1, int i2){
        return i1-i2;
    }

    // helper function to visualise array
    template<typename T>
    void display_array(T *arr, int N){
        for(int i = 0 ; i < N ; ++i){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    string to_str(KVPair<int,int> pair){
        return to_string(pair.value());
    }

}

#endif //TEST_BUILD_GENERAL_H
