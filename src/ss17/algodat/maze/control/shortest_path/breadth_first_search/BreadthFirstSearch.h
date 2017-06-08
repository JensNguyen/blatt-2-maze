//
// Created by rudi on 13.05.2017.
//

#ifndef MAZE_BREATHFIRSTSEARCHLIB_H
#define MAZE_BREATHFIRSTSEARCHLIB_H

#include <queue>
#include "Position.h"
#include "../../../model/maze.h"

using namespace std;

/**
 * Algorithm to find shortest way through maze by using breadth fist search.
 */
class BreadthFirstSearch
{

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
	 * Maze to be solved.
	 */
	Maze *maze;

public:
	/**
	 * Initializes the breadth first search.
	 * @param maze  Maze to be solved.
	 */
	BreadthFirstSearch(Maze *maze);

	/**
	 * Deletes all objects associated to the algorithm from the heap.
	 */
	~BreadthFirstSearch();

	/**
	 * Starts solving the maze.
	 * @param steps     Fields visited till termination of the algorithm.
	 * @return          True if the maze have been solved. False if not.
	 */
	bool
	solve(int &steps);

	/**
	 * Pushes unvisited, open fields reachable from given position into queue.
	 * @param position  Actual position in maze.
	 * @param maze    Maze to be solved.
	 */
	void
	pushFreeAdjacentFields(Position *position);

	/**
	 * Takes a position from queue and analyses all adjacent fields.
	 * @param maze    Maze to be solved.
	 */
	void
	consumePosition();

	/**
	 * Plots the shortest way from position to start into maze.
	 * @param position    Position to plot the shortest way from start to.
	 * @param maze      Maze to be solved.
	 */
	void
	plotSolution(Position position);

	/**
	 * A field given via position plus offset is checked for being open or the
	 * goal. If the field is open it will be added to the queue and the number
	 * of steps required to reach it will be wrote to it. If it is the goal
	 * this will be communicated by setting lastField to position.
	 * @param position          Base position.
	 * @param columnOffset      Adding this offset to the column-index of
	 *                          position will give the column-index of the
	 *                          field to check.
	 * @param rowOffset         Adding this offset to the row-index of position
	 *                          will give the row-index of the field to check.
	 * @param maze            	Maze to be solved.
	 */
	void
	consumeField(Position position, const int columnOffset,
				 const int rowOffset);

	/**
	 * Searches the positions next to the given position for the number of
	 * steps given.
	 * @param position  Base position.
	 * @param steps     Number of steps to search for.
	 * @param maze    Maze to be solved.
	 * @return          Positions adjacent field with number of steps equal to
	 *                  steps.
	 */
	Position *
	searchForNextFieldOnShortestPath(Position position, int steps) const;

	/**
	 * Returns the value in the specified column and row at the matrix.
	 *    0 1 2 3
	 *  0 x x x x
	 *  1 x x x x
	 *  2 x x x x
	 *  3 x x x x
	 * @param COLUMNS   Column count of matrix.
	 * @param ROWS      Row count of matrix.
	 * @param matrix    Matrix the value should be extracted from.
	 * @param column    Column of value to be extracted.
	 * @param row       Row of value to be extracted.
	 * @return          Value at matrix given by column- and rowindex.
	 */

	static int
	getField(const int COLUMNS, const int ROWS, int *matrix,
			 const int column, const int row);

	/**
	 * Looks for the position of start. The start field should be contained in
	 * the boarder of the maze.
	 * @param COLUMNS       Column count of matrix.
	 * @param ROWS          Row count of matrix.
	 * @param maze          Matrix to be checked.
	 * @param START_ID      Start-ID to be searched for.
	 * @return              The position of the start field, or nullptr if no
	 *                      start field was found.
	 */

	static Position *
	getStartPos(const int COLUMNS, const int ROWS,
				Maze *maze, const int START_ID);

	/**
	 * Sets the field specified by column and row to the given content.
	 * You can only edit fields which are set to zero!
	 *    0 1 2 3
	 *  0 x x x x
	 *  1 x x x x
	 *  2 x x x x
	 *  3 x x x x
	 * @param COLUMNS   Column count of matrix.
	 * @param ROWS      Row count of matrix.
	 * @param matrix    Matrix the value should be extracted from.
	 * @param column    Column of field to be replaced.
	 * @param row       Row of field to be replaced.
	 * @param content   Content to be set.
	 */
	static void
	setField(const int COLUMNS, const int ROWS, int *matrix,
			 const int column, const int row, int *content);

	int *
	getSolution() const;

	queue<Position> *
	getPositionQueue() const;

	Position *
	getLastField() const;

	int
	getLengthOfShortestPath() const;
};

#endif //MAZE_BREATHFIRSTSEARCHLIB_H
