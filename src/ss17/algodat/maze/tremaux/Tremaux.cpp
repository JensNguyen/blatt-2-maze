//
// Created by Emir Tola on 10.05.17.
//

#include "Tremaux.h"
#include <iostream>
#include <thread>
//#include <chrono>

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
                break;
            }
        }
    }
    
    // Save start position
    startPositionX = positionX;
    startPositionY = positionY;
    
    // Go initial step.
    positionX += directionX;
    positionY += directionY;
    
    // Solve the maze
    
    int counter = 0;
    
    bool notSolved = true;

    while (notSolved) {
        if (counter == 61 || counter == 106)
            cout << " ";
        
        char front = getFront();
        char left = getLeft();
        char right = getRight();
        
        if (foundGoal(front, left, right)) {
            setBack('X');
            
            if (left == 'G') {
                turnLeft();
            } else if (right == 'G') {
                turnRight();
            }
            
            notSolved = false;
        } else if (hasMarchedIntoDeadend(front, left, right)) {
            turnAround();
            startRetracing();
        } else if (foundJunction(front, left, right)) {
            if (!isRetracing) {
                if (hasMarchedIntoNewJunction(front, left, right)) {
                    setBack('X');
                    if (front == '.') {
                        setFront('N');
                    } else if (left == '.') {
                        setLeft('N');
                        turnLeft();
                    } else {
                        setRight('N');
                        turnRight();
                    }
                } else if (hasMarchedIntoOldJunction(front, left, right)) {
                    setBack('N');
                    turnAround();
                    startRetracing();
                } 
            } else {
                if (hasRetracedIntoSomeUnlabeled(front, left, right)) {
                    if (front == '.') {
                        setFront('N');
                    } else if (left == '.') {
                        setLeft('N');
                        turnLeft();
                    } else if (right == '.') {
                        setRight('N');
                        turnRight();
                    }
                    stopRetracing();
                } else if (hasRetracedIntoNoUnlabeled(front, left, right)) {
                    if (left == 'X') {
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
        
        
//        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        
        cout << "(" << counter++ << ") " << "x: \t" << positionX << "\t y: " << positionY << endl;
        printSolvedMaze();
        cout << endl;
        
    }

    return 0;
}


bool Tremaux::foundJunction(char front, char left, char right) {
    return left != '#' || right != '#';
}

bool Tremaux::foundGoal(char front, char left, char right) {
    return left == 'G' || right == 'G' || front == 'G'; 
}



bool Tremaux::hasMarchedIntoNewJunction(char front, char left, char right) {
    // A possible deadend and goal will already have been checked, so no worries!
    return ((left != 'N' && left != 'X') || left == '#') &&
            ((right != 'N' && right != 'X') || right == '#') &&
            ((front != 'N' && front != 'X') || front == '#');
}

bool Tremaux::hasMarchedIntoOldJunction(char front, char left, char right) {
    return ((left == 'N' || left == 'X') && left != '#') ||
            ((right == 'N' || right == 'X') && right != '#') ||
            ((front == 'N' || front == 'X') && front != '#');
}

bool Tremaux::hasMarchedIntoDeadend(char front, char left, char right) {
    return front == '#' && left == '#' && right == '#';
}

bool Tremaux::hasRetracedIntoSomeUnlabeled(char front, char left, char right) {
    return left == '.' || right == '.' || front == '.';
}

bool Tremaux::hasRetracedIntoNoUnlabeled(char front, char left, char right) {
    return (left == 'N' || left == 'X' || left == '#') && 
            (right == 'N' || right == 'X' || right == '#') && 
            (front == 'N' || front == 'X' || front == '#');
}


char Tremaux::getLeft() {
    // counterclockwise rotation: (x', y') == (-y, x);
    return maze[(positionY - directionX) * COLUMNS + positionX + directionY];
}

char Tremaux::getRight() {
    // clockwise rotation: (x', y') == (y, -x);
    return maze[(positionY + directionX) * COLUMNS + positionX - directionY];
}

char Tremaux::getFront() {
    return maze[(positionY + directionY) * COLUMNS + positionX + directionX];
}

char Tremaux::getBack() {
    return maze[(positionY - directionY) * COLUMNS + positionX - directionX];
}



void Tremaux::setLeft(char newValue) {
    maze[(positionY - directionX) * COLUMNS + positionX + directionY] = newValue;
}

void Tremaux::setRight(char newValue) {
    maze[(positionY + directionX) * COLUMNS + positionX - directionY] = newValue;
}

void Tremaux::setFront(char newValue) {
    maze[(positionY + directionY) * COLUMNS + positionX + directionX] = newValue;
}

void Tremaux::setBack(char newValue) {
    maze[(positionY - directionY) * COLUMNS + positionX - directionX] = newValue;
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
