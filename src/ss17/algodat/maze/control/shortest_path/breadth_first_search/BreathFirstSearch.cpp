//
// Created by rudi on 04.05.2017.
//

#include <string>
#include <queue>
#include "BreathFirstSearch.h"
#include "BreathFirstSearchLib.h"

BreathFirstSearch::BreathFirstSearch(const int COLUMNS, const int ROWS, char maze[]) :
        ROWS(ROWS), COLUMNS(COLUMNS){
    this->solution = new int[COLUMNS * ROWS]{};
    this->maze = new char[COLUMNS * ROWS]{};
    strcpy(this->maze, maze);
    this->positionQueue = new queue<Position>();
    this->lastStep = nullptr;
};

BreathFirstSearch::~BreathFirstSearch(){
    delete positionQueue;
    delete lastStep;
}

/**
 * Solve the maze. You can access the sulution via getSolution.
 * @return  Length of shortest path through maze. 
 */
int BreathFirstSearch::solve() {
    int result = -1;
    pushFreeAdjacentFields(BreathFirstSearchLib::getStartPos(COLUMNS, ROWS, maze, START));
    while (!positionQueue->empty() && lastStep == nullptr) {
        consumePosition();
    }

    if (lastStep != nullptr) {
        result = BreathFirstSearchLib::getField(COLUMNS, ROWS, solution, lastStep->getColumn(), lastStep->getRow());
        plotSolution(*lastStep);
    }
    return result;
}

/**
 * Given maze plus solution-path.
 * @return  The original maze upgraded by the solution-path.
 */
char *BreathFirstSearch::getSolution(){
    return maze;
}

/**
 * Pushes unvisited, open fields reachable from given position into queue.
 * @param position Actual position in maze.
 */
void BreathFirstSearch::pushFreeAdjacentFields(Position *position) {
    // consume right field
    consumeField(*position, 1, 0);
    // consume left field
    if(lastStep == nullptr)
        consumeField(*position, -1, 0);
    // consume upper field
    if(lastStep == nullptr)
        consumeField(*position, 0, 1);
    // consume lower field
    if(lastStep == nullptr)
        consumeField(*position, 0, -1);
}

/**
 * Takes a position from queue and analyses all adjacent fields.
 */
void BreathFirstSearch::consumePosition(){
    Position position = positionQueue->front();
    pushFreeAdjacentFields(&position);
    positionQueue->pop();

}

/**
 * Plots the shortest way from position to start into maze.
 * @param position    Runner to plot the shortest way from start to.
 */
void BreathFirstSearch::plotSolution(Position position) {
    BreathFirstSearchLib::setField(COLUMNS, ROWS, maze, position.getColumn(), position.getRow(), new char(PATH), OPEN);
    int steps = BreathFirstSearchLib::getField(COLUMNS, ROWS, solution, position.getColumn(), position.getRow());
    int newSteps = steps - 1;
    if(newSteps != 0)
        plotSolution(*searchForNextFieldOnShortestPath(position, newSteps));
}

/**
 * A field given via position plus offset is checked for being open or the
 * goal. If the field is open it will be added to the queue and the number
 * of steps required to reach it will be wrote to it. If it is the goal this
 * will be communicated by returning true;
 * @param position          Base position.
 * @param columnOffset      Adding this offset to the column-index of position
 *                          will give the column-index of the field to check.
 * @param rowOffset         Adding this offset to the row-index of position
 *                          will give the row-index of the field to check.
 * @return                  True if the specified field is the goal.
 */
void BreathFirstSearch::consumeField(Position position,
                                             const int columnOffset,
                                             const int rowOffset){
    Position fieldToBeConsumed = Position(position.getColumn() + columnOffset,
                                          position.getRow() + rowOffset);

    if(fieldToBeConsumed.getRow() >=0
       && fieldToBeConsumed.getRow() < ROWS
       && fieldToBeConsumed.getColumn() >=0
       && fieldToBeConsumed.getColumn() < COLUMNS){
        char mazeField = BreathFirstSearchLib::getField(COLUMNS, ROWS, maze,
                                   fieldToBeConsumed.getColumn(),
                                   fieldToBeConsumed.getRow());
        int solutionField = BreathFirstSearchLib::getField(COLUMNS, ROWS,
                                                            solution,
                                                            fieldToBeConsumed.getColumn(),
                                                            fieldToBeConsumed.getRow());
        if (mazeField == OPEN && solutionField == 0) {
            positionQueue->push(fieldToBeConsumed);
            int *newStepCount = new int(BreathFirstSearchLib::getField(
                    COLUMNS, ROWS, solution, position.getColumn(),
                    position.getRow()));
            *newStepCount += 1;
            BreathFirstSearchLib::setField(COLUMNS, ROWS, solution,
                                           fieldToBeConsumed.getColumn(),
                                           fieldToBeConsumed.getRow(),
                                           newStepCount);
        }else if (mazeField == GOAL) {
            this->lastStep = new Position(position.getColumn(), position.getRow());
        }
    }
}

/**
 * Searches the positions next to the given position for the number of steps
 * given.
 * @param position  Base position.
 * @param steps     Number of steps to search for.
 * @return          Positions adjacent field with number of steps equal to
 *                  steps.
 */
Position *BreathFirstSearch::searchForNextFieldOnShortestPath(
        Position position, int steps) {
    int result = BreathFirstSearchLib::getField(COLUMNS, ROWS, solution,
                                                 position.getColumn(),
                                                 position.getRow() - 1);
    if(result == steps)
        return new Position(position.getColumn(), position.getRow() - 1);

    result = BreathFirstSearchLib::getField(COLUMNS, ROWS, solution,
                                            position.getColumn() + 1,
                                            position.getRow());
    if(result == steps)
        return new Position(position.getColumn() + 1, position.getRow());

    result = BreathFirstSearchLib::getField(COLUMNS, ROWS, solution,
                                            position.getColumn(),
                                            position.getRow() + 1);
    if(result == steps)
        return new Position(position.getColumn(), position.getRow() + 1);

    result = BreathFirstSearchLib::getField(COLUMNS, ROWS, solution,
                                            position.getColumn() - 1,
                                            position.getRow());
    if(result == steps)
        return new Position(position.getColumn() - 1, position.getRow());

    return nullptr;
}
