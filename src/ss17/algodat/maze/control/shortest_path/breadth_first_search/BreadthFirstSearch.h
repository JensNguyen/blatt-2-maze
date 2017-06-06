//
// Created by rudi on 04.05.2017.
//

#ifndef MAZE_BREATH_FIRST_H
#define MAZE_BREATH_FIRST_H
#include "../../mazealgorithm.h"

class MazeGui;

#include <queue>
#include <string.h>
#include "Position.h"
#include "../../../model/maze.h"
#include <cstring>

using namespace std;

class BreadthFirstSearch: public MazeSolveAlgorithm{
private:
    int *solution;
    queue<Position> *positionQueue;
    Position *lastStep;

    void pushFreeAdjacentFields(Position *position);
    void consumePosition();
    void plotSolution(Position position);
    void consumeField(Position position, const int columnOffset,
                      const int rowOffset);
    Position *searchForNextFieldOnShortestPath(Position position, int steps);

public:
    BreadthFirstSearch(Maze *maze);
    ~BreadthFirstSearch();
    bool solve(int &steps);
    int solve();
    char *getSolution();

    void fillMazeGui(const int COLUMNS, const int ROWS, const char *maze);
};

#endif //MAZE_BREATH_FIRST_H
