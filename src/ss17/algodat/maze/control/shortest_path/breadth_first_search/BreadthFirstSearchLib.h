//
// Created by rudi on 13.05.2017.
//

#ifndef MAZE_BREATHFIRSTSEARCHLIB_H
#define MAZE_BREATHFIRSTSEARCHLIB_H

#include <queue>
#include "Position.h"
#include "../../../model/maze.h"

using namespace std;

/**
 * Collection of context-free library functions extracted from
 * BreathFirstSearch.
 */
class BreadthFirstSearchLib {

public:
    /**
     * Paint the matrix.
     * @param COLUMNS   Column count of matrix.
     * @param ROWS      Row count of matrix.
     * @param matrix    The matrix to be paint.
     */
    static void paintMatrix(const int COLUMNS, const int ROWS, int matrix[]);

    /**
     * Returns the value in the specified column and row at the matrix.
     *    0 1 2 3
     *  0 x x x x
     *  1 x x x x
     *  2 x x x x
     *  3 x x x x
     * @param COLUMNS   Column count of matrix.
     * @param ROWS      Row count of matrix.
     * @param matrix    Matrix the value should be extracted from.
     * @param column    Column of value to be extracted.
     * @param row       Row of value to be extracted.
     * @return          Value at matrix given by column- and rowindex.
     */
    static int getField(const int COLUMNS, const int ROWS, int *matrix,
                            const int column, const int row);

    /**
     * Looks for the position of start. The start field should be contained in the
     * boarder of the maze.
     * @param COLUMNS       Column count of matrix.
     * @param ROWS          Row count of matrix.
     * @param maze          Matrix to be checked.
     * @param START_ID      Start-ID to be searched for.
     * @return              The position of the start field, or nullptr if no start
     *                      field was found.
     */
    static Position * getStartPos(const int COLUMNS, const int ROWS,
                                  Maze *maze, const char START_ID);
    /**
     * Sets the field specified by column and row to the given content.
     * You can only edit fields which are set to zero!
     *    0 1 2 3
     *  0 x x x x
     *  1 x x x x
     *  2 x x x x
     *  3 x x x x
     * @param COLUMNS   Column count of matrix.
     * @param ROWS      Row count of matrix.
     * @param matrix    Matrix the value should be extracted from.
     * @param column    Column of field to be replaced.
     * @param row       Row of field to be replaced.
     * @param content   Content to be set.
     */
    static void setField(const int COLUMNS, const int ROWS, int *matrix,
                            const int column, const int row, int *content);
};


#endif //MAZE_BREATHFIRSTSEARCHLIB_H
