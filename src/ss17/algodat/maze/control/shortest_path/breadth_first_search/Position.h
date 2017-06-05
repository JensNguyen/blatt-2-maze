//
// Created by rudi on 11.05.2017.
//

#ifndef MAZE_POSITION_H
#define MAZE_POSITION_H

#include <string>

using namespace std;

class Position {
private:
    const int xPos;
    const int yPos;
public:
    Position(const int xPos, const int yPos) : xPos(xPos), yPos(yPos) {};
    ~Position(){};
    int getColumn();
    int getRow();
};


#endif //MAZE_POSITION_H
