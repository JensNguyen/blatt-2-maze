//
// Created by rudi on 13.05.2017.
//

#ifndef MAZE_BREATHFIRSTSEARCHLIB_H
#define MAZE_BREATHFIRSTSEARCHLIB_H

#include <queue>
#include "Position.h"
#include "../../../model/maze.h"

using namespace std;

class BreadthFirstSearchLib {

public:
    static void paintMatrix(const int COLUMNS, const int ROWS,
                            char matrix[]);

    static void paintMatrix(const int COLUMNS, const int ROWS, int matrix[]);

    static int getField(const int COLUMNS, const int ROWS, int *matrix,
                            const int column, const int row);

    static Position * getStartPos(const int COLUMNS, const int ROWS,
                                  Maze *maze, const char START_ID);

    static void setField(const int COLUMNS, const int ROWS, int *matrix,
                            const int column, const int row, int *content);
};


#endif //MAZE_BREATHFIRSTSEARCHLIB_H
