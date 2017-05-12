#include "recursivemazesolvealgorithm.h"

/**
 * @brief RecursiveMazeSolveAlgorithm::RecursiveMazeSolveAlgorithm Constructor sets the maze with width, height and startpos
 * @param maze the maze to solve
 * @param width width of the maze
 * @param height height of the maze
 */
RecursiveMazeSolveAlgorithm::RecursiveMazeSolveAlgorithm(Maze *maze)
    : MazeSolveAlgorithm(maze)
{
    m_wasHere = new bool[m_maze->getWidth()*m_maze->getHeight()];

    for(int i=0; i<m_maze->getWidth();i++)
    {
        for(int i2=0; i2<maze->getHeight();i2++)
        {
            if(maze->getMazeField(i,i2) == Maze::Start)
            {
                m_StartX = i;
                m_StartY = i2;
            }
            m_wasHere[i*m_maze->getWidth()+i2] = false;
        }
    }
}

/**
 * @brief RecursiveMazeSolveAlgorithm::solve Solves the delivered Maze
 * @param enable_steps flag which enables printing after everey step
 * @return flag if maze could be solved
 */
bool RecursiveMazeSolveAlgorithm::solve(int &steps)
{

    return recursiveSolveMaze(m_StartX, m_StartY, steps);
}

/**
 * @brief RecursiveMazeSolveAlgorithm::recursiveSolveMaze Recursive Functions solves the maze
 * @param x current x-position
 * @param y current y-position
 */
bool RecursiveMazeSolveAlgorithm::recursiveSolveMaze(int x, int y, int &steps)
{
    redraw();
    if(steps != -1)
        steps++;

    const int currentValue = m_maze->getMazeField(x,y);
    if(currentValue == Maze::End) return true; //returns true if maze was solved
    if(currentValue == Maze::Wall || m_wasHere[x*m_maze->getWidth()+y]) return false; //returnes false if maze couldn't be solved

    m_wasHere[x*m_maze->getWidth()+y] = true;

    if(x != 0) //Checks left edge
    {
        if(recursiveSolveMaze(x-1, y, steps))
        {
            m_maze->setMazeField(x,y,Maze::Result);
            return true;
        }
    }
    if(x != m_maze->getWidth()-1) //Checks right edge
    {
        if(recursiveSolveMaze(x+1, y, steps))
        {
            m_maze->setMazeField(x,y,Maze::Result);
            return true;
        }
    }
    if(y != 0)
    {
        if(recursiveSolveMaze(x, y-1, steps)) //Checks on top edge
        {
            m_maze->setMazeField(x,y,Maze::Result);
            return true;
        }
    }
    if(y != m_maze->getHeight()-1) //Checks on bottom edge
    {
        if(recursiveSolveMaze(x, y+1, steps))
        {
            m_maze->setMazeField(x,y,Maze::Result);
            return true;
        }
    }
    return false;
}
