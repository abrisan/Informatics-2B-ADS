//
// Created by Alexandru Brisan on 5/2/17.
//
#include "Vector.h"
#include "List.h"

using namespace Inf2B;

int main(){

    List<int> lst;

    lst.display_list();

    for(int i = 0 ; i < 10 ; ++i) {
        lst.insertFirst(i);
        lst.display_list();
    }

    return 0;
}

