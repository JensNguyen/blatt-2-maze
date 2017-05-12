#ifndef RECURSIVEMAZESOLVEALGORITHM_H
#define RECURSIVEMAZESOLVEALGORITHM_H
#include "mazealgorithm.h"

class MazeGui;

class RecursiveMazeSolveAlgorithm: public MazeSolveAlgorithm
{
private:
    bool *m_wasHere;
    int m_StartX, m_StartY;
    bool recursiveSolveMaze(int x, int y, int &steps);

public:
    RecursiveMazeSolveAlgorithm(Maze *maze);
    bool solve(int &steps);
};

#endif // RECURSIVEMAZESOLVEALGORITHM_H
