//
// Created by rudi on 04.05.2017.
//

#include <iostream>
#include "shortest_path/breadth_first_search/BreathFirstSearch.h"

int main(){
    BreathFirstSearch *bfs = new BreathFirstSearch();
    std::cout<<bfs->getHello()<<std::endl;
    return 0;
}