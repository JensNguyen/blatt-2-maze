#include "mazegenerator.h"
#include <random>


Maze* MazeGenerator::generateMaze(const int width,const int height)
{
    Maze *maze = new Maze(width, height);
    for(int i = 0; i<width; i++)
    {
        for(int i2 = 0; i2<height;i2++){
            if(i==0 || i==width-1 || i2==0 || i2 == height-1){
                maze->setMazeField(i,i2,Maze::Wall);
                if(i2==5 && i==0)
                    maze->setMazeField(i,i2,Maze::Start);
                if(i2==4 && i==width-1)
                    maze->setMazeField(i,i2,Maze::End);
            }else{
                if(rand()%3 == 2 || rand()%3)
                {
                    maze->setMazeField(i,i2,Maze::Way);
                }else{
                    maze->setMazeField(i,i2,Maze::Wall);
                }

            }

        }
    }
    return maze;
}

