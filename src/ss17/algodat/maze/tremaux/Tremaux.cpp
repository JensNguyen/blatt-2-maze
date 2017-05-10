//
// Created by Emir Tola on 10.05.17.
//

#include "Tremaux.h"
#include <iostream>


int Tremaux::solve() {
    // Find starting point and direction
    int currX = 0;
    int currY = 0;

    int directionX = 0;
    int directionY = 0;

    for (int i = 0; i < ROWS; i++) {
        std::cout << "row: " << i << std::endl;
        for (int j = 0; j < COLUMNS; j++) {
            if (maze[i*COLUMNS + j] == 'S') {
                currX = i;
                currY = j;

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


    // Solve the maze

    bool notSolved = true;

//    while (notSolved) {
//
//    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {

        }
    }

    return -1;
}

