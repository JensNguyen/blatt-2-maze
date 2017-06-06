//
// Created by rudi on 04.05.2017.
//

#include <string>
#include <queue>
#include "BreadthFirstSearch.h"
#include "BreadthFirstSearchLib.h"

BreadthFirstSearch::BreadthFirstSearch(Maze *maze) :
        MazeSolveAlgorithm(maze) {
    this->solution = new int[maze->getWidth() * maze->getHeight()]{};
    this->positionQueue = new queue<Position>();
    this->lastStep = nullptr;
};

BreadthFirstSearch::~BreadthFirstSearch(){
    delete positionQueue;
    delete lastStep;
}

bool BreadthFirstSearch::solve(int &steps){
    //TODO: param steps??
    return solve() != -1;
}

/**
 * Solve the maze. You can access the sulution via getSolution.
 * @return  Length of shortest path through maze. 
 */
int BreadthFirstSearch::solve() {
    int result = -1;
    pushFreeAdjacentFields(BreadthFirstSearchLib::getStartPos(
            m_maze->getWidth(), m_maze->getHeight(), m_maze, Maze::Start));
    while (!positionQueue->empty() && lastStep == nullptr) {
        consumePosition();
    }

    if (lastStep != nullptr) {
        result = BreadthFirstSearchLib::getField(m_maze->getWidth(),
            m_maze->getHeight(), solution, lastStep->getColumn(), lastStep->getRow());
        plotSolution(*lastStep);
    }
    return result;
}

/**
 * Pushes unvisited, open fields reachable from given position into queue.
 * @param position Actual position in maze.
 */
void BreadthFirstSearch::pushFreeAdjacentFields(Position *position) {
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
void BreadthFirstSearch::consumePosition(){
    Position position = positionQueue->front();
    pushFreeAdjacentFields(&position);
    positionQueue->pop();

}

/**
 * Plots the shortest way from position to start into maze.
 * @param position    Runner to plot the shortest way from start to.
 */
void BreadthFirstSearch::plotSolution(Position position) {
    m_maze->setMazeField(position.getColumn(), position.getRow(), Maze::Result);
    int steps = BreadthFirstSearchLib::getField(m_maze->getWidth(),
       m_maze->getHeight(), solution, position.getColumn(), position.getRow());
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
void BreadthFirstSearch::consumeField(Position position,
                                             const int columnOffset,
                                             const int rowOffset){
    Position fieldToBeConsumed = Position(position.getColumn() + columnOffset,
                                          position.getRow() + rowOffset);

    if(fieldToBeConsumed.getRow() >=0
       && fieldToBeConsumed.getRow() < m_maze->getHeight()
       && fieldToBeConsumed.getColumn() >=0
       && fieldToBeConsumed.getColumn() < m_maze->getWidth()){
        int mazeField = m_maze->getMazeField(fieldToBeConsumed.getColumn(),
            fieldToBeConsumed.getRow());
        int solutionField = BreadthFirstSearchLib::getField(m_maze->getWidth(), m_maze->getHeight(),
                                                            solution,
                                                            fieldToBeConsumed.getColumn(),
                                                            fieldToBeConsumed.getRow());
        if (mazeField == Maze::Way && solutionField == 0) {
            positionQueue->push(fieldToBeConsumed);
            int *newStepCount = new int(BreadthFirstSearchLib::getField(
                    m_maze->getWidth(), m_maze->getHeight(), solution,
                    position.getColumn(), position.getRow()));
            *newStepCount += 1;
            BreadthFirstSearchLib::setField(m_maze->getWidth(), m_maze->getHeight(), solution,
                                           fieldToBeConsumed.getColumn(),
                                           fieldToBeConsumed.getRow(),
                                           newStepCount);
        }else if (mazeField == Maze::End) {
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
Position *BreadthFirstSearch::searchForNextFieldOnShortestPath(
        Position position, int steps) {
    int result = BreadthFirstSearchLib::getField(m_maze->getWidth(),
                                                m_maze->getHeight(), solution,
                                                 position.getColumn(),
                                                 position.getRow() - 1);
    if(result == steps)
        return new Position(position.getColumn(), position.getRow() - 1);

    result = BreadthFirstSearchLib::getField(m_maze->getWidth(), m_maze->getHeight(), solution,
                                            position.getColumn() + 1,
                                            position.getRow());
    if(result == steps)
        return new Position(position.getColumn() + 1, position.getRow());

    result = BreadthFirstSearchLib::getField(m_maze->getWidth(), m_maze->getHeight(), solution,
                                            position.getColumn(),
                                            position.getRow() + 1);
    if(result == steps)
        return new Position(position.getColumn(), position.getRow() + 1);

    result = BreadthFirstSearchLib::getField(m_maze->getWidth(), m_maze->getHeight(), solution,
                                            position.getColumn() - 1,
                                            position.getRow());
    if(result == steps)
        return new Position(position.getColumn() - 1, position.getRow());

    return nullptr;
}
