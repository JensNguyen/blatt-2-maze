#pragma once

#include "../model/maze.h"
#include <QThread>

/**
 * @brief The MazeAlgorithm class Baseclass have to be derived by all maze solve algorithm classes
 *        contains the datastructures for the maze such as methods to redrow
 */
class MazeSolveAlgorithm: public QThread
{
    Q_OBJECT
public:
    MazeSolveAlgorithm(Maze *maze);
    Maze *m_maze;

    int m_steps; //steps to solve the maze
    double m_elapsedTime; //elapsed time to solve the maze
    bool m_solved; //is true if the maze can be solved

    //getter and setter
    int getSteps() const;
    double getElapsedTime() const;
    bool isSolved() const;

protected:
    void run();
    virtual bool solve(int &steps) = 0;

signals:
    void redraw();
    void signalLCDDisplays();

};

