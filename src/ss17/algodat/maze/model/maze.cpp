#include "maze.h"

/**
 * @brief Maze::Maze initializes the maze
 * @param width width of the maze
 * @param height height of the maze
 */
Maze::Maze(const int width,const int height):m_width(width), m_height(height)
{
    m_mazeArray = new int[width*height];
}

/**
 * @brief Maze::~Maze deletes the mazearray on the heap
 */
Maze::~Maze()
{
    delete[] m_mazeArray;
}

/**
 * @brief Maze::setMazeField sets a field of the maze
 * @param posWidth the x-position of the element
 * @param posHeight the y-position of the element
 * @param value
 */
void Maze::setMazeField(const int &posWidth,const int &posHeight, MazeSymbols value)
{
    m_setGetLock.lock();
    //TODO prüfung
    m_mazeArray[posWidth*m_width+posHeight] = value;
    m_setGetLock.unlock();
}

/**
 * @brief Maze::getMazeField returns the field on the deleivered position
 * @param posWidth the x-position
 * @param height the y-position
 * @return the value on the selected field
 */
int Maze::getMazeField(const int &posWidth, const int &height)
{
   // m_setGetLock.lock();
    return m_mazeArray[posWidth*m_width+height];
  //  m_setGetLock.unlock();
}

/**
 * @brief Maze::getWidth getter for m_width
 * @return width
 */
int Maze::getWidth() const
{
    return m_width;
}

/**
 * @brief Maze::getHeight setter for m_height
 * @return height
 */
int Maze::getHeight() const
{
    return m_height;
}
