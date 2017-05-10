//
// Created by Emir Tola on 10.05.17.
//

#include "Tremaux.h"
#include <iostream>


int Tremaux::solve() {
    // Find starting point and direction
    int positionX = 0;
    int positionY = 0;

    int directionX = 0;
    int directionY = 0;

    for (int i = 0; i < ROWS; i++) {
        std::cout << "row: " << i << std::endl;
        for (int j = 0; j < COLUMNS; j++) {
            if (maze[i*COLUMNS + j] == 'S') {
                // Start position
                positionX = i;
                positionY = j;
                
                // Start direction
                if (i != ROWS-1 && maze[(i+1)*COLUMNS + j] == '.') {
                    directionY = 1;
                } else if (i != 0 && maze[(i-1)*COLUMNS + j] == '.') {
                    directionY = -1;
                } else if (j != COLUMNS-1 && maze[i*COLUMNS + j+1] == '.') {
                    directionX = 1;
                } else if (j != 0 && maze[i*COLUMNS + j-1] == '.') {
                    directionX = -1;
                }
                
                
                // Completely break out of nested loop.
                i = ROWS;
                j = COLUMNS;
                break;
            }
        }
    }
    
    std::cout << "dirX: " << directionX << ", dirY: " << directionY << std::endl;

    // ###### Test rotation ######
//    {
//        int cX = 1;
//        int cY = 1;
//        int dX = -1;
//        int dY = 0;
//        char curr = maze[cY * COLUMNS + cX];
//        char left = getLeft(dX, dY);
//        char right = getRight(dX, dY);
//        char front = getFront(dX, dY);
//        char back = getBack(dX, dY);
//
//        std::cout << "curr: " << curr
//                  << ", front: " << front
//                  << ", back: " << back
//                  << ", left: " << left
//                  << ", right: " << right
//                  << std::endl;
//    }
    // #################
    
    // Solve the maze
    // NOTE: 'O' means visited once, 'X' means visited twice 

    bool notSolved = true;

    while (notSolved) {
        char nextPosition = maze[(positionY + directionY) * COLUMNS + positionX + directionX];


        if (nextPosition == '.') {
            char left = getLeft(directionX, directionY);
            char right = getRight(directionX, directionY);
            if (left == '#' && right == '#') {
                // keep going
                positionX += directionX;
                positionY += directionY;
            } else if (left == '.') {
                // Mark back slot and left slot as visited once. Keep going in left direction.
                setBack(directionX, directionY, 'O');
                setLeft(directionX, directionY, 'O');
            } else if (right == '.') {
                // Mark back slot and right slot as visited once. Keep going in right direction.

            }
        } else if (nextPosition == '#') {

        } else if (nextPosition == 'O') {

        } else if (nextPosition == 'X') {

        } else if (nextPosition == 'S') {

        } else if (nextPosition == 'G') {
            
            
            notSolved = false;
        }
    }

    return -1;
}

char Tremaux::getLeft(int currDirX, int currDirY) {
    // counterclockwise rotation: (x', y') == (-y, x); 
    // y direction is logically inverted, so final direction: (x', y') == (-y, -x)
    return maze[(positionY - currDirX) * COLUMNS + positionX - currDirY];
}

char Tremaux::getRight(int currDirX, int currDirY) {
    // clockwise rotation: (x', y') == (y, -x);
    // y direction is logically inverted, so final direction: (x', y') == (y, x)
    return maze[(positionY + currDirX) * COLUMNS + positionX + currDirY];
}

char Tremaux::getFront(int currDirX, int currDirY) {
    return maze[(positionY + currDirY) * COLUMNS + positionX + currDirX];
}

char Tremaux::getBack(int currDirX, int currDirY) {
    return maze[(positionY - currDirY) * COLUMNS + positionX - currDirX];
}



void Tremaux::setLeft(int currDirX, int currDirY, char newValue) {
    maze[(positionY - currDirX) * COLUMNS + positionX - currDirY] = newValue;
}

void Tremaux::setRight(int currDirX, int currDirY, char newValue) {
    maze[(positionY + currDirX) * COLUMNS + positionX + currDirY] = newValue;
}

void Tremaux::setFront(int currDirX, int currDirY, char newValue) {
    maze[(positionY + currDirY) * COLUMNS + positionX + currDirX] = newValue;
}

void Tremaux::setBack(int currDirX, int currDirY, char newValue) {
    maze[(positionY - currDirY) * COLUMNS + positionX - currDirX] = newValue;
}



