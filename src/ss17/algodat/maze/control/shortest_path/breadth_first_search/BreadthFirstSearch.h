

#ifndef MAZE_BREATH_FIRST_H
#define MAZE_BREATH_FIRST_H
#include "../../mazealgorithm.h"

class MazeGui;

#include <queue>
#include <string.h>
#include "Position.h"
#include "../../../model/maze.h"
#include <cstring>

using namespace std;

/**
 * Algorithm to find shortest way through maze by using breadth fist search.
 */
class BreadthFirstSearch: public MazeSolveAlgorithm{

private:
    /**
     * For each field at the maze, there is a field in solution. This field
     * holds the number of steps which is needed to reach the field from start.
     * The index of a position in the solution is calculated by:
     * index = xPos + (yPos * <width of maze>)
     */
    int *solution;

    /**
     * Each position of a free field which is reachable from the actual field
     * is pushed to the positionQueue.
     */
    queue<Position> *positionQueue;

    /**
     * If end is reachable from the actual field the actual field will be set
     * as lastField.
     */
    Position *lastField;

    /**
     * Length of shortest path through maze.
     */
    int lengthOfShortestPath;

    /**
     * Pushes unvisited, open fields reachable from given position into queue.
     * @param position Actual position in maze.
     */
    void pushFreeAdjacentFields(Position *position);

    /**
     * Takes a position from queue and analyses all adjacent fields.
     */
    void consumePosition();

    /**
     * Plots the shortest way from position to start into maze.
     * @param position    Position to plot the shortest way from start to.
     */
    void plotSolution(Position position);

    /**
     * A field given via position plus offset is checked for being open or the
     * goal. If the field is open it will be added to the queue and the number
     * of steps required to reach it will be wrote to it. If it is the goal this
     * will be communicated by setting lastField to position.
     * @param position          Base position.
     * @param columnOffset      Adding this offset to the column-index of position
     *                          will give the column-index of the field to check.
     * @param rowOffset         Adding this offset to the row-index of position
     *                          will give the row-index of the field to check.
     */
    void consumeField(Position position, const int columnOffset,
                      const int rowOffset);

    /**
     * Searches the positions next to the given position for the number of steps
     * given.
     * @param position  Base position.
     * @param steps     Number of steps to search for.
     * @return          Positions adjacent field with number of steps equal to
     *                  steps.
     */
    Position *searchForNextFieldOnShortestPath(Position position, int steps);

public:
    /**
     * Initializes the breadth first search.
     * @param maze  Maze to be solved.
     */
    BreadthFirstSearch(Maze *maze);

    /**
     * All objects associated to the algorithm on the heap.
     */
    ~BreadthFirstSearch();

    /**
     * Starts solving the maze.
     * @param steps     Fields visited till termination of the algorithm.
     * @return          True if the maze have been solved. False if not.
     */
    bool solve(int &steps);
};

#endif //MAZE_BREATH_FIRST_H
