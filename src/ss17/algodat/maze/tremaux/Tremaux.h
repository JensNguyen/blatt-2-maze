//
// Created by Emir Tola on 10.05.17.
//

#ifndef MAZE_TREMAUX_H
#define MAZE_TREMAUX_H


class Tremaux {

    char* maze;
    const int ROWS;
    const int COLUMNS;
    
    int startPositionX;
    int startPositionY;
    
    /** Always contains current x position. */
    int positionX;
    /** Always contains current y position. */
    int positionY;
    
    int directionX;
    int directionY;
    
    bool isRetracing;
    
    bool foundJunction(int currDirX, int currDirY, char front, char left, char right);
    
    bool foundGoal(int currDirX, int currDirY, char front, char left, char right);
    
    /**
     * Marching FORWARD into a NEW junction.
     * - Mark the exit of current passage with an 'X'.
     * - Select a NEW passage.
     * - Mark the entrance of NEW passage with an 'N'.
     * - March FORWARD.
     * 
     * @param currDirX 
     * @param currDirY 
     * @param front 
     * @param left 
     * @param right 
     * @return 
     */
    bool hasMarchedIntoNewJunction(int currDirX, int currDirY, char front, char left, char right);
    
    /**
     * Marching FORWARD into an OLD junction.
     * - Mark the exit of current passage with an 'N'.
     * - Turn around.
     * - Retrace BACKWARD along the current passage.
     * 
     * @param currDirX 
     * @param currDirY 
     * @param front 
     * @param left 
     * @param right 
     * @return 
     */
    bool hasMarchedIntoOldJunction(int currDirX, int currDirY, char front, char left, char right);
    
    /**
     * Marching FORWARD into a dead end.
     * - Turn around.
     * - Retrace BACKWARD.
     * 
     * @param currDirX 
     * @param currDirY 
     * @param front 
     * @param left 
     * @param right 
     * @return 
     */
    bool hasMarchedIntoDeadend(int currDirX, int currDirY, char front, char left, char right);
    
    /**
     * Retracing BACKWARD into a junction with SOME unlabled passages.
     * - Select an unlabeled passage.
     * - Mark the entrance of the NEW passage with 'N'.
     * - March FORWARD.
     * 
     * @param currDirX 
     * @param currDirY 
     * @param front 
     * @param left 
     * @param right 
     * @return 
     */
    bool hasRetracedIntoSomeUnlabeled(int currDirX, int currDirY, char front, char left, char right);
    
    /**
     * Retracing BACKWARD into a junction with NO unlabled passages.
     * - Select the passage with the 'X'. There will be only one.
     * - Continue retracing BACKWARD.
     * 
     * @param currDirX 
     * @param currDirY 
     * @param front 
     * @param left 
     * @param right 
     * @return 
     */
    bool hasRetracedIntoNoUnlabeled(int currDirX, int currDirY, char front, char left, char right);
    
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
    
    void startRetracing();
    void stopRetracing();


public:
    Tremaux(char maze[], int rows, int columns) : maze(maze), ROWS(rows), COLUMNS(columns), 
                                                  startPositionX(0), startPositionY(0),
                                                  positionX(0), positionY(0), 
                                                  directionX(0), directionY(0), 
                                                  isRetracing(false) {};
    int solve();
    void printSolvedMaze();
    
};


#endif //MAZE_TREMAUX_H
