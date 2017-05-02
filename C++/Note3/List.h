//
// Created by Alexandru Brisan on 5/2/17.
//

#ifndef TEST_BUILD_LIST_H
#define TEST_BUILD_LIST_H

#include <iostream>
#include "../General.h"

namespace Inf2B{

    template<typename T>
    struct node{
        T content;
        struct node *next;
        struct node *previous;
    };

    template<typename T>
    class List{
        int length;
        struct node<T> *first_node;
        struct node<T> *last_node;
    public:
        List();
        ~List();
        T element(struct node<T> *p);
        struct node<T> *first();
        bool isEmpty();
        struct node<T> *next(struct node<T> *p);
        bool isLast(struct node<T> *p);
        void replace(struct node<T> *p, T e);
        void insertFirst(T e);
        void insertAfer(struct node<T> *p, T e);
        void remove(struct node<T> *p);
        void display_list();

    };


    template<typename T>
    List<T>::List(){
        first_node = nullptr;
        last_node = nullptr;
        length = 0;
    }

    template<typename T>
    List<T>::~List(){
        if(first_node == nullptr)
            return;
        if(first_node->next == nullptr)
            delete first_node;
        while(first_node->next){
            first_node = first_node->next;
            delete first_node->previous;
        }
    }

    template<typename T>
    T List<T>::element(struct node<T> *p) {
        return p->content;
    }

    template<typename T>
    struct node<T> * List<T>::first() {
        return first_node;
    }

    template<typename T>
    bool List<T>::isLast(struct node<T> *p) {
        return p->next==nullptr;
    }

    template<typename T>
    void List<T>::replace(struct node<T> *p, T e) {
        p->content = e;
    }

    template<typename T>
    void List<T>::insertFirst(T e) {
        struct node<T> *q = new struct node<T>;
        q->content = e;
        if(first_node == nullptr){
            q->next=nullptr;
            q->previous = nullptr;
            first_node=q;
            last_node=q;
            return;
        }
        q->next = first_node;
        first_node->previous = q;
        first_node = q;
        ++length;
    }

    template<typename T>
    void List<T>::insertAfer(struct node<T> *p, T e) {
        struct node<T> *q = new struct node<T>;
        q->content = e;
        q->next = p->next;
        q->previous = p;
        p->next = q;
        q->next->previous = q;
        ++length;
    }

    template<typename T>
    void List<T>::remove(struct node<T> *p) {
        p->previous->next = p->next;
        p->next->previous = p->previous;
        delete p;
        --length;
    }

    template<typename T>
    void List<T>::display_list() {
        struct node<T> *cop;
        cop = first_node;
        if(cop == nullptr){
            std::cout << "Empty list" << std::endl;
        }else{
            while(cop){
                std::cout << cop->content << " ";
                cop = cop->next;
            }
            std::cout << std::endl;
        }

    }

}


#endif //TEST_BUILD_LIST_H
