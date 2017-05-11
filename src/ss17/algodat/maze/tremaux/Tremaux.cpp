//
// Created by Emir Tola on 10.05.17.
//

#include "Tremaux.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int Tremaux::solve() {
    // Find starting point and direction
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (maze[i * COLUMNS + j] == 'S') {
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
    
    // Save start position
    startPositionX = positionX;
    startPositionY = positionY;
//    maze[positionY * COLUMNS + positionX] = 'X';
    
    // Go initial step.
    positionX += directionX;
    positionY += directionY;
    
    // Solve the maze
    // NOTE: 'N' means visited once, 'X' means visited twice 

    int counter = 0;
    
    bool notSolved = true;

    while (notSolved) {
        if (counter == 61 || counter == 106)
            cout << " ";
        
        char front = getFront(directionX, directionY);
        char back = getBack(directionX, directionY);
        char left = getLeft(directionX, directionY);
        char right = getRight(directionX, directionY);
        
        if (foundGoal(directionX, directionY, front, left, right)) {
            setBack(directionX, directionY, 'X');
            
            if (front == 'G') {
                // Nothing here.
            } else if (left == 'G') {
                turnLeft();
            } else if (right == 'G') {
                turnRight();
            }
            
            notSolved = false;
        } else if (hasMarchedIntoDeadend(directionX, directionY, front, left, right)) {
            turnAround();
            startRetracing();
        } else if (foundJunction(directionX, directionY, front, left, right)) {
            if (!isRetracing) {
                if (hasMarchedIntoNewJunction(directionX, directionY, front, left, right)) {
                    setBack(directionX, directionY, 'X');
                    if (front == '.') {
                        setFront(directionX, directionY, 'N');
                    } else if (left == '.') {
                        setLeft(directionX, directionY, 'N');
                        turnLeft();
                    } else {
                        setRight(directionX, directionY, 'N');
                        turnRight();
                    }
                } else if (hasMarchedIntoOldJunction(directionX, directionY, front, left, right)) {
                    setBack(directionX, directionY, 'N');
                    turnAround();
                    startRetracing();
                } 
            } else {
                if (hasRetracedIntoSomeUnlabeled(directionX, directionY, front, left, right)) {
                    if (front == '.') {
                        setFront(directionX, directionY, 'N');
                    } else if (left == '.') {
                        setLeft(directionX, directionY, 'N');
                        turnLeft();
                    } else if (right == '.') {
                        setRight(directionX, directionY, 'N');
                        turnRight();
                    }
                    stopRetracing();
                } else if (hasRetracedIntoNoUnlabeled(directionX, directionY, front, left, right)) {
                    if (front == 'X') {
                        // Nothing here.
                    } else if (left == 'X') {
                        turnLeft();
                    } else if (right == 'X') {
                        turnRight();
                    }
                }
            }
            
        }
        
        // Move
        positionX += directionX;
        positionY += directionY;
        
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        
        
        cout << "(" << counter++ << ") " << "x: \t" << positionX << "\t y: " << positionY << endl;
//        cout << "(" << counter++ << ") " << endl;
        printSolvedMaze();
        cout << endl;
        
    }

    return 0;
}


bool Tremaux::foundJunction(int currDirX, int currDirY, char front, char left, char right) {
    return left != '#' || right != '#';
}

bool Tremaux::foundGoal(int currDirX, int currDirY, char front, char left, char right) {
    return left == 'G' || right == 'G' || front == 'G'; 
}



bool Tremaux::hasMarchedIntoNewJunction(int currDirX, int currDirY, char front, char left, char right) {
    // A possible deadend and goal will already have been checked, so no worries!
    return ((left != 'N' && left != 'X') || left == '#') &&
            ((right != 'N' && right != 'X') || right == '#') &&
            ((front != 'N' && front != 'X') || front == '#');
}

bool Tremaux::hasMarchedIntoOldJunction(int currDirX, int currDirY, char front, char left, char right) {
    return ((left == 'N' || left == 'X') && left != '#') ||
            ((right == 'N' || right == 'X') && right != '#') ||
            ((front == 'N' || front == 'X') && front != '#');
}

bool Tremaux::hasMarchedIntoDeadend(int currDirX, int currDirY, char front, char left, char right) {
    return front == '#' && left == '#' && right == '#';
}

bool Tremaux::hasRetracedIntoSomeUnlabeled(int currDirX, int currDirY, char front, char left, char right) {
//    return (left != 'N' && left != 'X' && left != '#') || 
//            (right != 'N' && right != 'X' && right != '#') || 
//            (front != 'N' && front != 'X' && front != '#');
    return left == '.' || right == '.' || front == '.';
}

bool Tremaux::hasRetracedIntoNoUnlabeled(int currDirX, int currDirY, char front, char left, char right) {
    return (left == 'N' || left == 'X' || left == '#') && 
            (right == 'N' || right == 'X' || right == '#') && 
            (front == 'N' || front == 'X' || front == '#');
}


char Tremaux::getLeft(int currDirX, int currDirY) {
    // counterclockwise rotation: (x', y') == (-y, x); 
    // y direction is logically inverted, so final direction: (x', y') == (-y, -x)
//    positionX = 2;
//    positionY = 2;
//    currDirX = 1;
//    currDirY = 0;
//    int idx = (positionY - currDirX) * COLUMNS + positionX + currDirY;
    return maze[(positionY - currDirX) * COLUMNS + positionX + currDirY];
    
//    return maze[(positionY - currDirX) * COLUMNS + positionX - currDirY];
}

char Tremaux::getRight(int currDirX, int currDirY) {
    // clockwise rotation: (x', y') == (y, -x);
    // y direction is logically inverted, so final direction: (x', y') == (y, x)
//    positionX = 2;
//    positionY = 2;
//    currDirX = 1;
//    currDirY = 0;
//    int idx = (positionY + currDirX) * COLUMNS + positionX - currDirY;
    return maze[(positionY + currDirX) * COLUMNS + positionX - currDirY];

//    return maze[(positionY + currDirX) * COLUMNS + positionX + currDirY];
}

char Tremaux::getFront(int currDirX, int currDirY) {
//    positionX = 2;
//    positionY = 2;
//    currDirX = 1;
//    currDirY = 0;
//    int idx = (positionY + currDirY) * COLUMNS + positionX + currDirX;
    return maze[(positionY + currDirY) * COLUMNS + positionX + currDirX];
}

char Tremaux::getBack(int currDirX, int currDirY) {
    return maze[(positionY - currDirY) * COLUMNS + positionX - currDirX];
}



void Tremaux::setLeft(int currDirX, int currDirY, char newValue) {
    maze[(positionY - currDirX) * COLUMNS + positionX + currDirY] = newValue;
//    maze[(positionY - currDirX) * COLUMNS + positionX - currDirY] = newValue;
}

void Tremaux::setRight(int currDirX, int currDirY, char newValue) {
    maze[(positionY + currDirX) * COLUMNS + positionX - currDirY] = newValue;
//    maze[(positionY + currDirX) * COLUMNS + positionX + currDirY] = newValue;
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
    int newDirX = directionY;
    int newDirY = -directionX;
    directionX = newDirX;
    directionY = newDirY;
}

void Tremaux::turnRight() {
    int newDirX = -directionY;
    int newDirY = directionX;
    directionX = newDirX;
    directionY = newDirY;
}

void Tremaux::startRetracing() {
    isRetracing = true;
}

void Tremaux::stopRetracing() {
    isRetracing = false;
}

void Tremaux::printSolvedMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            cout << maze[i * COLUMNS + j];
            cout << ',';
        }
        cout << endl;
    }
}
