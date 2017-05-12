#include "mazealgorithm.h"

/**
 * @brief MazeSolveAlgorithm::MazeSolveAlgorithm sets the maze and initializes all variables
 * @param maze
 * @param width
 * @param height
 */
MazeSolveAlgorithm::MazeSolveAlgorithm(Maze *maze)
{
    m_maze = maze;

    m_steps = 0;
    m_elapsedTime = 0;
    m_solved = 0;
}

/**
 * @brief MazeAlgorithm::run run method starts the solving algorithm such as the time measurement, signals the gui to display the values
 */
void MazeSolveAlgorithm::run()
{
    struct timespec startTimeSpec, stopTimeSpec;
    int getClockRet = clock_gettime(CLOCK_REALTIME, &startTimeSpec);
    m_solved = solve(m_steps);
    getClockRet = clock_gettime(CLOCK_REALTIME, &stopTimeSpec);
    //Calculates elapsed time in millis
    m_elapsedTime = ((stopTimeSpec.tv_sec-startTimeSpec.tv_sec)*1E3)
                    +((stopTimeSpec.tv_nsec-startTimeSpec.tv_nsec)/1E6);
    signalLCDDisplays(); //signals the gui
}

/**
 * @brief MazeSolveAlgorithm::getSteps getter for m_steps
 * @return nr of steps
 */
int MazeSolveAlgorithm::getSteps()const
{
    return m_steps;
}

/**
 * @brief MazeSolveAlgorithm::getElapsedTime getter for m_elapsedTime
 * @return elapsed time
 */
double MazeSolveAlgorithm::getElapsedTime() const
{
    return m_elapsedTime;
}

/**
 * @brief MazeSolveAlgorithm::isSolved getter for m_isSolved
 * @return solved flag
 */
bool MazeSolveAlgorithm::isSolved() const
{
    return m_solved;
}
