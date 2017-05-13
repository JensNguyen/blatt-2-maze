//
// Created by rudi on 04.05.2017.
//

#ifndef MAZE_BREATH_FIRST_H
#define MAZE_BREATH_FIRST_H

#include <queue>
#include <string.h>
#include "Position.h"
#include <cstring>

using namespace std;

class BreathFirstSearch{
private:
    const int ROWS;
    const int COLUMNS;
    char *maze;
    int *solution;
    queue<Position> *positionQueue;
    Position *lastStep;

    void pushFreeAdjacentFields(Position *position);
    void consumePosition();
    void plotSolution(Position *position);
    void consumeField(Position *position, const int columnOffset,
                      const int rowOffset);
    Position *searchForNextFieldOnShortestPath(Position *position, int steps);

public:
    static const char START = 'S';
    static const char GOAL = 'G';
    static const char OPEN = '.';
    static const char PATH = '+';
    static const char BLOCKED = '#';

    BreathFirstSearch(const int COLUMNS, const int ROWS, char *maze);
    ~BreathFirstSearch();
    void solve();
    char *getSolution();
};

#endif //MAZE_BREATH_FIRST_H
