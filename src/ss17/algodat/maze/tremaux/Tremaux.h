//
// Created by Emir Tola on 10.05.17.
//

#ifndef MAZE_TREMAUX_H
#define MAZE_TREMAUX_H


class Tremaux {

    char* maze;
    const int ROWS;
    const int COLUMNS;
    
    /** Always contains current x position. */
    int positionX;
    /** Always contains current y position. */
    int positionY;
    
    int directionX;
    int directionY;
    
    bool atJunction(int currDirX, int currDirY, char front, char left, char right);
    
    char getLeft(int currDirX, int currDirY);
    char getRight(int currDirX, int currDirY);
    char getFront(int currDirX, int currDirY);
    char getBack(int currDirX, int currDirY);

    void setLeft(int currDirX, int currDirY, char newValue);
    void setRight(int currDirX, int currDirY, char newValue);
    void setFront(int currDirX, int currDirY, char newValue);
    void setBack(int currDirX, int currDirY, char newValue);
    
    void turnAround();
    void turnLeft();
    void turnRight();


public:
    Tremaux(char maze[], int rows, int columns) : maze(maze), ROWS(rows), COLUMNS(columns), 
                                                  positionX(0), positionY(0), 
                                                  directionX(0), directionY(0) {};
    int solve();

};


#endif //MAZE_TREMAUX_H
