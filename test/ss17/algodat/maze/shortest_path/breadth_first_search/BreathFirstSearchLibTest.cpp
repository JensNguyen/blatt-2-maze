#include "gtest/gtest.h"
#include "../../../../../../src/ss17/algodat/maze/control/shortest_path/breadth_first_search/BreadthFirstSearchLib.h"

TEST(BreadthFirstSearchLibTest, getIntField0){
    int matrix[] = {1, 2, 3,
                     4, 5, 6,
                     7, 8, 9};
    int result = BreadthFirstSearchLib::getField(3, 3, matrix, 1, 1);
    EXPECT_EQ(5, result);
}

TEST(BreadthFirstSearchLibTest, getIntField1){
    int matrix[] = {1, 2, 3,
                     4, 5, 6,
                     7, 8, 9};
    int result = BreadthFirstSearchLib::getField(3, 3, matrix, 2, 0);
    EXPECT_EQ(3, result);
}

TEST(BreadthFirstSearchLibTest, getIntField2){
    int matrix[] = {1, 2, 3,
                     4, 5, 6,
                     7, 8, 9};
    int result = BreadthFirstSearchLib::getField(3, 3, matrix, 0, 2);
    EXPECT_EQ(7, result);
}

TEST(BreadthFirstSearchLibTest, getStartPos0){
    Maze *matrix = new Maze(3,3);
    matrix->setMazeField(0, 0, Maze::Wall);
    matrix->setMazeField(1, 0, Maze::Way);
    matrix->setMazeField(2, 0, Maze::Result);

    matrix->setMazeField(0, 1, Maze::End);
    matrix->setMazeField(1, 1, Maze::Way);
    matrix->setMazeField(2, 1, Maze::Start);

    matrix->setMazeField(0, 2, Maze::Wall);
    matrix->setMazeField(1, 2, Maze::Way);
    matrix->setMazeField(2, 2, Maze::Result);

    Position *result = BreadthFirstSearchLib::getStartPos(3, 3, matrix, Maze::Start);
    EXPECT_EQ(2, result->getColumn());
    EXPECT_EQ(1, result->getRow());
}

TEST(BreadthFirstSearchLibTest, getStartPos1){
    Maze *matrix = new Maze(3,3);
    matrix->setMazeField(0, 0, Maze::Wall);
    matrix->setMazeField(1, 0, Maze::Start);
    matrix->setMazeField(2, 0, Maze::Result);

    matrix->setMazeField(0, 1, Maze::End);
    matrix->setMazeField(1, 1, Maze::Way);
    matrix->setMazeField(2, 1, Maze::Way);

    matrix->setMazeField(0, 2, Maze::Wall);
    matrix->setMazeField(1, 2, Maze::Way);
    matrix->setMazeField(2, 2, Maze::Result);

    Position *result = BreadthFirstSearchLib::getStartPos(3, 3, matrix, Maze::Start);
    EXPECT_EQ(1, result->getColumn());
    EXPECT_EQ(0, result->getRow());
}
TEST(BreadthFirstSearchLibTest, getStartPos2){
    Maze *matrix = new Maze(3,3);
    matrix->setMazeField(0, 0, Maze::Wall);
    matrix->setMazeField(1, 0, Maze::Wall);
    matrix->setMazeField(2, 0, Maze::Result);

    matrix->setMazeField(0, 1, Maze::End);
    matrix->setMazeField(1, 1, Maze::Way);
    matrix->setMazeField(2, 1, Maze::Way);

    matrix->setMazeField(0, 2, Maze::Start);
    matrix->setMazeField(1, 2, Maze::Way);
    matrix->setMazeField(2, 2, Maze::Result);

    Position *result = BreadthFirstSearchLib::getStartPos(3, 3, matrix, Maze::Start);
    EXPECT_EQ(0, result->getColumn());
    EXPECT_EQ(2, result->getRow());
}

TEST(BreadthFirstSearchLibTest, setIntField0){
    int matrix[] = {0, 0, 0,
                     0, 0, 0,
                     0, 0, 0};
    BreadthFirstSearchLib::setField(3, 3, matrix, 1, 1, new int (1));
    int result = BreadthFirstSearchLib::getField(3, 3, matrix, 1, 1);
    EXPECT_EQ(1, result);
}

TEST(BreadthFirstSearchLibTest, setIntField1){
    int matrix[] = {0, 0, 0,
                     0, 0, 0,
                     0, 0, 0};
    BreadthFirstSearchLib::setField(3, 3, matrix, 2, 0, new int (1));
    int result = BreadthFirstSearchLib::getField(3, 3, matrix, 2, 0);
    EXPECT_EQ(1, result);
}

TEST(BreadthFirstSearchLibTest, settIntField2){
    int matrix[] = {0, 0, 0,
                     0, 0, 0,
                     0, 0, 0};
    BreadthFirstSearchLib::setField(3, 3, matrix, 0, 2, new int (1));
    int result = BreadthFirstSearchLib::getField(3, 3, matrix, 0, 2);
    EXPECT_EQ(1, result);
}