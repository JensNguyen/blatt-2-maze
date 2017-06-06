#include "gtest/gtest.h"
#include "../../../../../../src/ss17/algodat/maze/control/shortest_path/breadth_first_search/BreadthFirstSearchLib.h"
#include "../../../../../../src/ss17/algodat/maze/control/shortest_path/breadth_first_search/BreadthFirstSearch.h"

TEST(BreathFirstSearchLibTest, getIntField0){
    int matrix[] = {1, 2, 3,
                     4, 5, 6,
                     7, 8, 9};
    int result = BreadthFirstSearchLib::getField(3, 3, matrix, 1, 1);
    EXPECT_EQ(5, result);
}

TEST(BreathFirstSearchLibTest, getIntField1){
    int matrix[] = {1, 2, 3,
                     4, 5, 6,
                     7, 8, 9};
    int result = BreadthFirstSearchLib::getField(3, 3, matrix, 2, 0);
    EXPECT_EQ(3, result);
}

TEST(BreathFirstSearchLibTest, getIntField2){
    int matrix[] = {1, 2, 3,
                     4, 5, 6,
                     7, 8, 9};
    int result = BreadthFirstSearchLib::getField(3, 3, matrix, 0, 2);
    EXPECT_EQ(7, result);
}

TEST(BreathFirstSearchLibTest, getStartPos0){
    char matrix[] = {BreadthFirstSearch::BLOCKED, BreadthFirstSearch::OPEN, BreadthFirstSearch::PATH,
                      BreadthFirstSearch::GOAL, BreadthFirstSearch::OPEN, BreadthFirstSearch::START,
                      BreadthFirstSearch::BLOCKED, BreadthFirstSearch::OPEN, BreadthFirstSearch::PATH};
    Position *result = BreadthFirstSearchLib::getStartPos(3, 3, matrix, BreadthFirstSearch::START);
    EXPECT_EQ(2, result->getColumn());
    EXPECT_EQ(1, result->getRow());
}

TEST(BreathFirstSearchLibTest, getStartPos1){
    char matrix[] = {BreadthFirstSearch::BLOCKED, BreadthFirstSearch::START, BreadthFirstSearch::PATH,
                      BreadthFirstSearch::GOAL, BreadthFirstSearch::OPEN, BreadthFirstSearch::OPEN,
                      BreadthFirstSearch::BLOCKED, BreadthFirstSearch::OPEN, BreadthFirstSearch::PATH};
    Position *result = BreadthFirstSearchLib::getStartPos(3, 3, matrix, BreadthFirstSearch::START);
    EXPECT_EQ(1, result->getColumn());
    EXPECT_EQ(0, result->getRow());
}
TEST(BreathFirstSearchLibTest, getStartPos2){
    char matrix[] = {BreadthFirstSearch::BLOCKED, BreadthFirstSearch::BLOCKED, BreadthFirstSearch::PATH,
                      BreadthFirstSearch::GOAL, BreadthFirstSearch::OPEN, BreadthFirstSearch::OPEN,
                      BreadthFirstSearch::START, BreadthFirstSearch::OPEN, BreadthFirstSearch::PATH};
    Position *result = BreadthFirstSearchLib::getStartPos(3, 3, matrix, BreadthFirstSearch::START);
    EXPECT_EQ(0, result->getColumn());
    EXPECT_EQ(2, result->getRow());
}

TEST(BreathFirstSearchLibTest, getCharField0){
    char matrix[] = {'a', 'b', 'c',
                      'd', 'e', 'f',
                      'g', 'h', 'i'};
    char result = BreadthFirstSearchLib::getField(3, 3, matrix, 1, 1);
    EXPECT_EQ('e', result);
}

TEST(BreathFirstSearchLibTest, getCharField1){
    char matrix[] = {'a', 'b', 'c',
                      'd', 'e', 'f',
                      'g', 'h', 'i'};
    char result = BreadthFirstSearchLib::getField(3, 3, matrix, 2, 0);
    EXPECT_EQ('c', result);
}

TEST(BreathFirstSearchLibTest, getCharField2){
    char matrix[] = {'a', 'b', 'c',
                      'd', 'e', 'f',
                      'g', 'h', 'i'};
    char result = BreadthFirstSearchLib::getField(3, 3, matrix, 0, 2);
    EXPECT_EQ('g', result);
}

TEST(BreathFirstSearchLibTest, setIntField0){
    int matrix[] = {0, 0, 0,
                     0, 0, 0,
                     0, 0, 0};
    BreadthFirstSearchLib::setField(3, 3, matrix, 1, 1, new int (1));
    int result = BreadthFirstSearchLib::getField(3, 3, matrix, 1, 1);
    EXPECT_EQ(1, result);
}

TEST(BreathFirstSearchLibTest, setIntField1){
    int matrix[] = {0, 0, 0,
                     0, 0, 0,
                     0, 0, 0};
    BreadthFirstSearchLib::setField(3, 3, matrix, 2, 0, new int (1));
    int result = BreadthFirstSearchLib::getField(3, 3, matrix, 2, 0);
    EXPECT_EQ(1, result);
}

TEST(BreathFirstSearchLibTest, settIntField2){
    int matrix[] = {0, 0, 0,
                     0, 0, 0,
                     0, 0, 0};
    BreadthFirstSearchLib::setField(3, 3, matrix, 0, 2, new int (1));
    int result = BreadthFirstSearchLib::getField(3, 3, matrix, 0, 2);
    EXPECT_EQ(1, result);
}

TEST(BreathFirstSearchLibTest, setCharField0){
    char matrix[] = {BreadthFirstSearch::OPEN, BreadthFirstSearch::OPEN, BreadthFirstSearch::OPEN,
                      BreadthFirstSearch::OPEN, BreadthFirstSearch::OPEN, BreadthFirstSearch::OPEN,
                      BreadthFirstSearch::OPEN, BreadthFirstSearch::OPEN, BreadthFirstSearch::OPEN};
    BreadthFirstSearchLib::setField(3, 3, matrix, 1, 1, new char('b'), BreadthFirstSearch::OPEN);
    char result = BreadthFirstSearchLib::getField(3, 3, matrix, 1, 1);
    EXPECT_EQ('b', result);
}

TEST(BreathFirstSearchLibTest, setCharField1){
    char matrix[] = {BreadthFirstSearch::OPEN, BreadthFirstSearch::OPEN, BreadthFirstSearch::OPEN,
                      BreadthFirstSearch::OPEN, BreadthFirstSearch::OPEN, BreadthFirstSearch::OPEN,
                      BreadthFirstSearch::OPEN, BreadthFirstSearch::OPEN, BreadthFirstSearch::OPEN};
    BreadthFirstSearchLib::setField(3, 3, matrix, 2, 0, new char ('b'), BreadthFirstSearch::OPEN);
    char result = BreadthFirstSearchLib::getField(3, 3, matrix, 2, 0);
    EXPECT_EQ('b', result);
}

TEST(BreathFirstSearchLibTest, setCharField2){
    char matrix[] = {BreadthFirstSearch::OPEN, BreadthFirstSearch::OPEN, BreadthFirstSearch::OPEN,
                      BreadthFirstSearch::OPEN, BreadthFirstSearch::OPEN, BreadthFirstSearch::OPEN,
                      BreadthFirstSearch::OPEN, BreadthFirstSearch::OPEN, BreadthFirstSearch::OPEN};
    BreadthFirstSearchLib::setField(3, 3, matrix, 0, 2, new char('b'), BreadthFirstSearch::OPEN);
    char result = BreadthFirstSearchLib::getField(3, 3, matrix, 0, 2);
    EXPECT_EQ('b', result);
}

