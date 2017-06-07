//
// Created by rudi on 04.05.2017.
//

#include <string>
#include <queue>
#include "BreadthFirstSearchGuiInteraction.h"
#include "BreadthFirstSearch.h"

bool BreadthFirstSearchGuiInteraction::solve(int &steps){
    return bfs.solve(steps, m_maze);
}


