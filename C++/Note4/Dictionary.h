//
// Created by Alexandru Brisan on 5/2/17.
//

#ifndef INF2B_DICTIONARY_H
#define INF2B_DICTIONARY_H

#import "../Note3/List.h"

namespace Inf2B{

#ifndef NO_SUCH_KEY
#define NO_SUCH_KEY nullptr
#endif

    template<typename K, typename T>
    class Dictionary{
        List<T> *hash_table;
        K (*hash)(T);
    public:
        Dictionary(K *(hash)(T));
        ~Dictionary();
        T find_element(K key);
        void insert_item(K key, T item);
        T remove_item(K key);
    };



}

#endif //INF2B_DICTIONARY_H
