

#ifndef MAZE_BREATH_FIRST_H
#define MAZE_BREATH_FIRST_H
#include "../../mazealgorithm.h"
#include "BreadthFirstSearch.h"

class MazeGui;

#include <queue>
#include <string.h>
#include "Position.h"
#include "../../../model/maze.h"
#include <cstring>

using namespace std;

/**
 * Wraps logic of BreathFirstSearch into class extending MazeSolveAlgorithm.
 */
class BreadthFirstSearchGuiInteraction : public MazeSolveAlgorithm
{

private:
	BreadthFirstSearch bfs;

public:
	/**
	 * Initializes both the breadth first search logic and its
	 * gui-representation.
	 * @param maze  Maze to be solved.
	 */
	BreadthFirstSearchGuiInteraction(Maze *maze)
		: MazeSolveAlgorithm(maze), bfs(BreadthFirstSearch(maze)) {};

	/**
	 * Deletes all objects associated to the algorithm and its gui
	 * representation from the heap.
	 */
	~BreadthFirstSearchGuiInteraction() {};

	/**
	 * Starts solving the maze.
	 * @param steps     Fields visited till termination of the algorithm.
	 * @return          True if the maze have been solved. False if not.
	 */
	bool
	solve(int &steps);
};

#endif //MAZE_BREATH_FIRST_H
