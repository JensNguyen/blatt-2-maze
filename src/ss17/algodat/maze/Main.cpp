//
// Created by rudi on 04.05.2017.
//

#include <iostream>
#include "shortest_path/breadth_first_search/BreathFirstSearch.h"

using namespace std;

int main(){
    BreathFirstSearch *bfs = new BreathFirstSearch();
    cout<<bfs->getHello()<<endl;
    return 0;
}