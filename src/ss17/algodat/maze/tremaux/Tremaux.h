//
// Created by Emir Tola on 10.05.17.
//

#ifndef MAZE_TREMAUX_H
#define MAZE_TREMAUX_H


class Tremaux {

    char maze[];
    const int ROWS;
    const int COLUMNS;

public:
    Tremaux(char maze[], int rows, int columns) : maze(maze), ROWS(rows), COLUMNS(columns) {};
    int solve();

};


#endif //MAZE_TREMAUX_H
