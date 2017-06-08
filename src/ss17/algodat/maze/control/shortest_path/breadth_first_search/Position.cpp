//
// Created by rudi on 11.05.2017.
//

#include "Position.h"

using namespace std;

int
Position::getColumn()
{
	return this->xPos;
}

int
Position::getRow()
{
	return this->yPos;
}

bool Position::operator==(const Position& other) const {
	return this->xPos == other.xPos
		&& this->yPos == other.yPos;
}