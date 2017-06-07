//
// Created by rudi on 13.05.2017.
//
#include <iostream>
#include "Position.h"
#include "BreadthFirstSearchLib.h"
#include "../../../model/maze.h"
#include <stdexcept>

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

int BreadthFirstSearchLib::getField(const int COLUMNS, const int ROWS,
                                    int matrix[], const int column,
                                    const int row){
    if(!(0 <= column && column < COLUMNS
         && 0 <= row && row < ROWS))
        throw invalid_argument( "Row or column out of bounds!" );
    return matrix[(row) * COLUMNS + column];
}


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