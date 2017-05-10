//
// Created by Emir Tola on 10.05.17.
//

#include "Tremaux.h"
#include <iostream>


int Tremaux::solve() {
    // Find starting point and direction
    int currX = 0;
    int currY = 0;
    for (int i = 0; i < ROWS; i++) {
        std::cout << "row: " << i << "\n";
        for (int j = 0; j < COLUMNS; j++) {
            if (maze[i*j + i] == 'S') {
                currX = i;
                currY = j;

                // Completely break out of nested loop.
                i = ROWS;
                j = COLUMNS;
                break;
            }
        }
    }



    // Solve the maze.
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {

        }
    }

    return -1;
}

