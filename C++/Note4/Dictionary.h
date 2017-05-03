//
// Created by Alexandru Brisan on 5/2/17.
//

#ifndef INF2B_DICTIONARY_H
#define INF2B_DICTIONARY_H

#include "../Note3/List.h"
#include <utility>
#include <iostream>
#include <vector>


namespace Inf2B{

    using namespace std;
    using namespace Inf2B;

    template<typename K, typename T>
        class Dictionary{
        List<KVPair<K,T>> *hash_table;
        int (*hash)(K);
        bool (*comp)(K,K);
        int N;
            vector<bool> occupied;
            T default_elem;
    public:
        Dictionary(bool (*comp)(K,K),int (*hash)(K) , int N, T def);
        ~Dictionary();
        T find_element(K key);
        void insert_item(K key, T item);
        T remove_item(K key);
        void display_dictionary(string (*to_string)(KVPair<K,T>));
    };

    template<typename K, typename T>
    Dictionary<K,T>::Dictionary(bool (*comp)(K,K), int (*hash)(K), int N, T def) {
        this->comp = comp;
        this->hash = hash;
        this->N = N;
        occupied = vector<bool>(N, false);
        hash_table = new List<KVPair<K,T>>[N];
        default_elem = def;
    }

    template<typename K, typename T>
    Dictionary<K,T>::~Dictionary() {
        // delete[] hash_table;

    }

    template<typename K, typename T>
    T Dictionary<K,T>::find_element(K key) {
        if(!occupied[hash(key)])
            throw "DICTIONARY<K,T> : NO SUCH KEY";
        KVPair<K,T> search_result = hash_table[hash(key)].findElement(KVPair<K,T>(key, default_elem));
        return search_result.value();
    }

    template<typename K, typename T>
    void Dictionary<K,T>::insert_item(K key, T item) {
        int hashed = hash(key);
        hash_table[hashed].insertFirst(KVPair<K,T>(key,item));
        occupied[hashed] = true;
    }

    template<typename K, typename T>
    T Dictionary<K,T>::remove_item(K key) {
        if(!occupied[hash(key)])
            throw "DICTIONARY<K,T> : NO SUCH KEY";
        KVPair<K,T> remove_result = hash_table[hash(key)].removeElement(KVPair<K,T>(key, default_elem));
        if(hash_table[hash(key)].isEmpty()){
            occupied[hash(key)] = false;
        }
        return remove_result.value();
    }


    template<typename K, typename T>
    void Dictionary<K,T>::display_dictionary(string (*to_string)(KVPair<K,T>)) {
        cout << "{";
        for(int i = 0 ; i < N-1 ; ++i){
            if(!occupied[i])
                continue;
            cout << i << ":" ;
            hash_table[i].display_list_pred(to_string);
            cout<<"; ";
        }
        hash_table[N-1].display_list_pred(to_string);
        cout<<"}"<<endl;
    }

}

#endif //INF2B_DICTIONARY_H
