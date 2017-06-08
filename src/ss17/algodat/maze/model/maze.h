#pragma once
#include <mutex>
/**
 * @brief The Maze class contains the model of the maze with functions to set an get fields of the maze
 */
class Maze
{
public:
    Maze(const int width,const int height);
    ~Maze();

    //Symbols of the maze array
    enum MazeSymbols{Wall=0, Way, Start, End, Result};

    void setMazeField(const int &posWidth,const int &posHeight, MazeSymbols value);
    void reset();
    int getMazeField(const int &posWidth, const int &posHeight);
    int getWidth() const;
    int getHeight() const;


 private:
    std::mutex m_setGetLock;
    int *m_mazeArray;
    const int m_width;
    const int m_height;
};
