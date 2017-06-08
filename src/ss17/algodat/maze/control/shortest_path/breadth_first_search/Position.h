//
// Created by rudi on 11.05.2017.
//

#ifndef MAZE_POSITION_H
#define MAZE_POSITION_H

#include <string>

using namespace std;

/**
 * Structure allowing to exchange positions with two dimensions.
 */
class Position
{
private:
	/**
	 * Absolute position in x-dimension.
	 */
	const int xPos;

	/**
	 * Absolute position in y-dimension.
	 */
	const int yPos;

public:
	/**
	 * Init position.
	 * @param xPos  Absolute x-position.
	 * @param yPos  Absolute y-position.
	 */
	Position(const int xPos, const int yPos) : xPos(xPos), yPos(yPos) {};

	/**
	 * Get absolute x-position.
	 * @return  Absolute x-position.
	 */
	int
	getColumn();

	/**
	 * Get absolute y-position.
	 * @return  Absolute y-position.
	 */
	int
	getRow();

	bool operator==(const Position& other) const;
};

#endif //MAZE_POSITION_H
