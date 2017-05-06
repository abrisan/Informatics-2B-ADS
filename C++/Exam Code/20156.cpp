//
// Created by Alexandru Brisan on 5/4/17.
//
#include <iostream>
#include <vector>
#include <queue>
#include "../General.h"


using namespace std;
using namespace Inf2B;

class graph{
    vector<int> *g;
    int N;
public:
    graph(int N);
    ~graph();
    void add_edge(int source, int dest);
    bool two_colorable();
};

graph::graph(int N) {
    g = new vector<int>[N];
    for(int i = 0 ; i < N ; ++i){
        g[i] = vector<int>();
    }
    this->N = N;
}

graph::~graph(){
    delete[] g;
}

void graph::add_edge(int source, int dest) {
    g[source].push_back(dest);
}

bool graph::two_colorable(){

    bool visited[N];

    bool color[N];

    for(int i = 0 ; i < N ; ++i){
        visited[i] = false;
        color[i] = false;
    }

    queue<int> q;

    visited[0] = true;

    q.push(0);

    for(auto &x : g[0]){
        q.push(x);
    }

    bool clr = false;

    while(q.size()!=0){

        int elem = q.front();
        q.pop();

        cout << elem << endl;
        cout << visited[elem] << endl;
        cout << color[elem] << endl;
        cout << clr << endl;

        cout << endl << endl << endl;

        if(!visited[elem]){
            visited[elem] = true;
            color[elem] =  clr;
            clr = !clr;
            for(auto &x : g[elem]){
                if(!visited[x])
                    q.push(x);
            }
        }else{
            if(clr != color[elem]){
                return false;
            }
        }
    }

    return true;
}



int main(){

    graph g(4);

    g.add_edge(0,2);
    g.add_edge(0,3);
    g.add_edge(1,2);
    g.add_edge(1,3);

    auto res = g.two_colorable();

    cout << res << endl;

    return 0;

}
