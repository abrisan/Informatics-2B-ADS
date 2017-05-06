//
// Created by Alexandru Brisan on 5/3/17.
//

#ifndef INF2B_BINARYSEARCHTREE_H
#define INF2B_BINARYSEARCHTREE_H

namespace Inf2B{
    template<typename T>
    class BinarySearchTree{
        T information;
        BinarySearchTree<T> *left;
        BinarySearchTree<T> *right;
    public:
        T findElement(T k);

    };
}

#endif //INF2B_BINARYSEARCHTREE_H
