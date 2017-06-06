//
// Created by rudi on 13.05.2017.
//
#include <iostream>
#include "Position.h"
#include "BreadthFirstSearchLib.h"
#include "../../../model/maze.h"
#include <stdexcept>

/**
 * Paint the matrix.
 * @param COLUMNS   Column count of matrix.
 * @param ROWS      Row count of matrix.
 * @param matrix    The matrix to be paint.
 */
void BreadthFirstSearchLib::paintMatrix(const int COLUMNS, const int ROWS,
                                         int matrix[]){
    int x;
    for(int row = 0; row < ROWS; row++){
        for(int column = 0; column < COLUMNS; column++){
            x = matrix[row*COLUMNS + column];
            cout<<x;
        }
        cout<<endl;
    }
    cout<<endl;
}

/**
 * Paint the matrix.
 * @param COLUMNS   Column count of matrix.
 * @param ROWS      Row count of matrix.
 * @param matrix    The matrix to be paint.
 */
void BreadthFirstSearchLib::paintMatrix(const int COLUMNS, const int ROWS,
                                       char matrix[]){
    for(int row = 0; row < ROWS; row++){
        for(int column = 0; column < COLUMNS; column++){
            cout<<matrix[row*COLUMNS + column];
        }
        cout<<endl;
    }
    cout<<endl;
}

/**
 * Looks for the position of start. The start field should be contained in the
 * boarder of the maze.
 * @param COLUMNS       Column count of matrix.
 * @param ROWS          Row count of matrix.
 * @param maze        Matrix to be checked.
 * @param START_ID      ID to be searched for.
 * @return              The position of the start field, or NULL if no start
 *                      field was found.
 */
Position *BreadthFirstSearchLib::getStartPos(const int COLUMNS, const int ROWS,
                                           Maze *maze, const char START_ID){
    // upper row
    int index = 0;
    while(index < COLUMNS){
        if(maze->getMazeField(index, 0) == Maze::Start)
            return new Position(index, 0);
        index++;
    }

    // lower row
    index = 0;
    while(index < COLUMNS){
        if(maze->getMazeField(index, ROWS - 1) == Maze::Start)
            return new Position(index , ROWS - 1);
        index++;
    }

    // left column
    index = 0;
    while(index < ROWS){
        if(maze->getMazeField(0, index) == Maze::Start)
            return new Position(0, index);
        index++;
    }

    // right column
    index = 0;
    while(index < ROWS){
        if(maze->getMazeField(COLUMNS - 1, index) == Maze::Start)
            return new Position(COLUMNS - 1, index);
        index++;
    }
    return nullptr;
}

/**
 * Returns the value in the specified column in the given row at the matrix.
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
 * @return          Value of matrix given by column and row.
 */
int BreadthFirstSearchLib::getField(const int COLUMNS, const int ROWS,
                                    int matrix[], const int column,
                                    const int row){
    if(!(0 <= column && column < COLUMNS
         && 0 <= row && row < ROWS))
        throw invalid_argument( "Row or column out of bounds!" );
    return matrix[(row) * COLUMNS + column];
}


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
void BreadthFirstSearchLib::setField(const int COLUMNS, const int ROWS,
                                 int matrix[], const int column,
                                 const int row, int *content){
    if(!(0 <= column && column < COLUMNS
            && 0 <= row && row < ROWS))
        throw invalid_argument( "Row or column out of bounds!" );
    const int index = row*COLUMNS + column;
    if(!matrix[index] == 0)
        throw invalid_argument( "You can only edit fields which are set "
                                             "to zero!" );
    matrix[index] = *content;
}