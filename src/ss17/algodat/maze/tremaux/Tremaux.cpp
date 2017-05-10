//
// Created by Emir Tola on 10.05.17.
//

#include "Tremaux.h"
#include <iostream>


int Tremaux::solve() {
    // Find starting point and direction
    for (int i = 0; i < ROWS; i++) {
        std::cout << "row: " << i << std::endl;
        for (int j = 0; j < COLUMNS; j++) {
            if (maze[i*COLUMNS + j] == 'S') {
                // Start position
                positionX = j;
                positionY = i;
                
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
    
    // Go initial step manually
    positionX += directionX;
    positionY += directionY;
    
    std::cout << "dirX: " << directionX << ", dirY: " << directionY << std::endl;

    // ###### Test rotation ######
//    {
//        int cX = 1;
//        int cY = 1;
//        int dX = -1;
//        int dY = 0;
//        
//        char curr = maze[cY * COLUMNS + cX];
//        char left = getLeft(dX, dY);
//        char right = getRight(dX, dY);
//        char front = getFront(dX, dY);
//        char back = getBack(dX, dY);
//
//        std::cout << "x: " << positionX << ", y: " << positionY
//                << ", curr: " << curr
//                << ", front: " << front
//                << ", back: " << back
//                << ", left: " << left
//                << ", right: " << right
//                << std::endl;
//    }
    // #################
    
    // Solve the maze
    // NOTE: 'O' means visited once, 'X' means visited twice 

    bool notSolved = true;

    while (notSolved) {
        char front = getFront(directionX, directionY);
        char back = getBack(directionX, directionY);
        char left = getLeft(directionX, directionY);
        char right = getRight(directionX, directionY);
        
        if (!(left == '#' || left == 'X' || left == 'S')) {
            
        }
        
        if (left == '.') {
            // Mark back slot and left slot as visited once. Keep going in left direction.
            if (back != 'X' && back != 'S')
                setBack(directionX, directionY, 'O');
            setLeft(directionX, directionY, 'O');
            turnLeft();
        } else if (right == '.') {
            // Mark back slot and right slot as visited once. Keep going in right direction.
            if (back != 'X' && back != 'S')
                setBack(directionX, directionY, 'O');
            setRight(directionX, directionY, 'O');
            turnRight();
        } else if (front == '.') {
            // Mark back slot and front slot as visited once. Keep going in forward.
            if (back != 'X' && back != 'S')
                setBack(directionX, directionY, 'O');
            setFront(directionX, directionY, 'O');
        } else if (left == 'O') {
            
        } else if (right == 'O') {
            
        } else if (front == 'O') {
            
        } else if (left == 'X') {

        } else if (right == 'X') {

        } else if (front == 'X') {

        } else if (left == 'S') {

        } else if (right == 'S') {

        } else if (front == 'S') {

        } else if (left == 'G') {
            notSolved = false;
        } else if (right == 'G') {
            notSolved = false;
        } else if (front == 'G') {
            notSolved = false;
        }
        
        
        positionX += directionX;
        positionY += directionY;
    }

    return -1;
}


bool Tremaux::foundJunction(int currDirX, int currDirY, char front, char left, char right) {
    return left != '#' && left != 'S' && right != '#' && right != 'S';
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



void Tremaux::turnAround() {
    directionX *= -1;
    directionY *= -1;
}

void Tremaux::turnLeft() {
    int newDirX = -directionY;
    int newDirY = -directionX;
    directionX = newDirX;
    directionY = newDirY;
}

void Tremaux::turnRight() {
    int newDirX = directionY;
    int newDirY = directionX;
    directionX = newDirX;
    directionY = newDirY;
}


