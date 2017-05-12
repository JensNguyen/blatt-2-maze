#pragma once
#include "maze.h"

class MazeGenerator
{
public:
    MazeGenerator();
    static Maze* generateMaze(const int width,const int hight);
};
