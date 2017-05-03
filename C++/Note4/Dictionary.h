//
// Created by Alexandru Brisan on 5/2/17.
//

#ifndef INF2B_DICTIONARY_H
#define INF2B_DICTIONARY_H

#include "../Note3/List.h"
#include <utility>
#include <iostream>


namespace Inf2B{

    using namespace std;

    template<typename K, typename T>
    class Dictionary{
        List<pair<K,T>> *hash_table;
        int (*hash)(K);
        bool (*comp)(K,K);
        int N;
    private:
        bool eq(pair<K,T> p1,pair<K,T> p2);
    public:
        Dictionary(bool (*comp)(K,K),int (*hash)(K) , int N);
        ~Dictionary();
        T find_element(K key);
        void insert_item(K key, T item);
        T remove_item(K key);
        void display_dictionary(string (*to_string)(pair<K,T>));
    };

    template<typename K, typename T>
    Dictionary<K,T>::Dictionary(bool (*comp)(K,K), int (*hash)(K), int N) {
        this->comp = comp;
        this->hash = hash;
        this->N = N;
        hash_table = new List<pair<K,T>>[N];
    }

    template<typename K, typename T>
    Dictionary<K,T>::~Dictionary() {
        delete[] hash_table;
    }

    template<typename K, typename T>
    bool Dictionary<K,T>::eq(pair<K, T> p1, pair<K, T> p2) {
        return comp(p1.first,p2.first);
    }

    template<typename K, typename T>
    T Dictionary<K,T>::find_element(K key) {
        List<pair<K,T>> bucket = hash_table[hash(key)];
        pair<K,T> search_result = bucket.findElement(&eq, make_pair(key,nullptr));
        if(search_result==NO_SUCH_KEY)
            return NO_SUCH_KEY;
        return search_result.second;
    }

    template<typename K, typename T>
    void Dictionary<K,T>::insert_item(K key, T item) {
        hash_table[hash(key)].insertFirst(make_pair(key,item));
    }

    template<typename K, typename T>
    T Dictionary<K,T>::remove_item(K key) {
        List<pair<K,T>> bucket = hash_table[hash(key)];
        pair<K,T> remove_result = bucket.removeElement(&eq, make_pair(key,nullptr));
        if(remove_result == NO_SUCH_KEY)
            return NO_SUCH_KEY;
        return remove_result.second;
    }


    template<typename K, typename T>
    void Dictionary<K,T>::display_dictionary(string (*to_string)(pair<K,T>)) {
        cout << "{";
        for(int i = 0 ; i < N-1 ; ++i){
            cout << i << ":" ;
            hash_table[i].display_list_pred(to_string);
            cout<<"; ";
        }
        hash_table[N-1].display_list_pred(to_string);
        cout<<"}"<<endl;
    }

}

#endif //INF2B_DICTIONARY_H
