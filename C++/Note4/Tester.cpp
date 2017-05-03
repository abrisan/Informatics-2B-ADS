//
// Created by Alexandru Brisan on 5/3/17.
//
#include "Dictionary.h"
#include "../General.h"

using namespace Inf2B;
using namespace std;

int hash_f(int i){
    return i%10;
}

bool comp(int i1,int i2){
    return i1==i2;
}

int main(){

    Dictionary<int,int> dict(&comp, &hash_f,10,0);

    for(int i = 0 ; i < 100 ; ++i){
        dict.insert_item(i,i);
    }

    dict.display_dictionary(&to_str);

    int i = dict.remove_item(10);

    dict.remove_item(1);

    dict.remove_item(90);

    dict.display_dictionary(&to_str);


    return 0;

}