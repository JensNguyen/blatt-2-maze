//
// Created by rudi on 13.05.2017.
//

#ifndef MAZE_BREATHFIRSTSEARCHLIB_H
#define MAZE_BREATHFIRSTSEARCHLIB_H

#include <queue>
#include "Position.h"

using namespace std;

class BreathFirstSearchLib {

public:
    static void paintMatrix(const int COLUMNS, const int ROWS,
                            char matrix[]);

    static void paintMatrix(const int COLUMNS, const int ROWS, int matrix[]);

    static char *getField(const int COLUMNS, const int ROWS, char *matrix,
                            const int column, const int row);

    static int *getField(const int COLUMNS, const int ROWS, int *matrix,
                            const int column, const int row);

    static Position *getStartPos(const int COLUMNS, const int ROWS,
                            char *matrix, const char START_ID);

    static void setField(const int COLUMNS, const int ROWS, int *matrix,
                            const int column, const int row, int *content);

    static void setField(const int COLUMNS, const int ROWS, char *matrix,
                            const int column, const int row, char *content,
                            const char OPEN_ID);
};


#endif //MAZE_BREATHFIRSTSEARCHLIB_H
