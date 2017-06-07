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
    this->lastField = nullptr;
    this->lengthOfShortestPath = -1;
};

BreadthFirstSearch::~BreadthFirstSearch(){
    delete positionQueue;
    delete lastField;
}

bool BreadthFirstSearch::solve(int &steps){
    bool solved = false;
    pushFreeAdjacentFields(BreadthFirstSearchLib::getStartPos(
            m_maze->getWidth(), m_maze->getHeight(), m_maze, Maze::Start));
    while (!positionQueue->empty() && lastField == nullptr) {
        consumePosition();
        steps++;
    }

    if (lastField != nullptr) {
        lengthOfShortestPath = BreadthFirstSearchLib::getField(m_maze->getWidth(),
                                                 m_maze->getHeight(), solution, lastField->getColumn(), lastField->getRow());
        plotSolution(*lastField);
        solved = true;
    }
    return solved;
}

void BreadthFirstSearch::pushFreeAdjacentFields(Position *position) {
    // consume right field
    consumeField(*position, 1, 0);
    // consume left field
    if(lastField == nullptr)
        consumeField(*position, -1, 0);
    // consume upper field
    if(lastField == nullptr)
        consumeField(*position, 0, 1);
    // consume lower field
    if(lastField == nullptr)
        consumeField(*position, 0, -1);
}

void BreadthFirstSearch::consumePosition(){
    Position position = positionQueue->front();
    pushFreeAdjacentFields(&position);
    positionQueue->pop();

}

void BreadthFirstSearch::plotSolution(Position position) {
    m_maze->setMazeField(position.getColumn(), position.getRow(), Maze::Result);
    int steps = BreadthFirstSearchLib::getField(m_maze->getWidth(),
       m_maze->getHeight(), solution, position.getColumn(), position.getRow());
    int newSteps = steps - 1;
    if(newSteps != 0)
        plotSolution(*searchForNextFieldOnShortestPath(position, newSteps));
}

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
            this->lastField = new Position(position.getColumn(), position.getRow());
        }
    }
}

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
