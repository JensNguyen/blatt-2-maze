#include "gtest/gtest.h"
#include "../../../../../../src/ss17/algodat/maze/control/shortest_path/breadth_first_search/BreathFirstSearchLib.h"
#include "../../../../../../src/ss17/algodat/maze/control/shortest_path/breadth_first_search/BreathFirstSearch.h"

TEST(BreathFirstSearchLibTest, getIntField0){
    int matrix[] = {1, 2, 3,
                     4, 5, 6,
                     7, 8, 9};
    int result = BreathFirstSearchLib::getField(3, 3, matrix, 1, 1);
    EXPECT_EQ(5, result);
}

TEST(BreathFirstSearchLibTest, getIntField1){
    int matrix[] = {1, 2, 3,
                     4, 5, 6,
                     7, 8, 9};
    int result = BreathFirstSearchLib::getField(3, 3, matrix, 2, 0);
    EXPECT_EQ(3, result);
}

TEST(BreathFirstSearchLibTest, getIntField2){
    int matrix[] = {1, 2, 3,
                     4, 5, 6,
                     7, 8, 9};
    int result = BreathFirstSearchLib::getField(3, 3, matrix, 0, 2);
    EXPECT_EQ(7, result);
}

TEST(BreathFirstSearchLibTest, getStartPos0){
    char matrix[] = {BreathFirstSearch::BLOCKED, BreathFirstSearch::OPEN, BreathFirstSearch::PATH,
                      BreathFirstSearch::GOAL, BreathFirstSearch::OPEN, BreathFirstSearch::START,
                      BreathFirstSearch::BLOCKED, BreathFirstSearch::OPEN, BreathFirstSearch::PATH};
    Position *result = BreathFirstSearchLib::getStartPos(3, 3, matrix, BreathFirstSearch::START);
    EXPECT_EQ(2, result->getColumn());
    EXPECT_EQ(1, result->getRow());
}

TEST(BreathFirstSearchLibTest, getStartPos1){
    char matrix[] = {BreathFirstSearch::BLOCKED, BreathFirstSearch::START, BreathFirstSearch::PATH,
                      BreathFirstSearch::GOAL, BreathFirstSearch::OPEN, BreathFirstSearch::OPEN,
                      BreathFirstSearch::BLOCKED, BreathFirstSearch::OPEN, BreathFirstSearch::PATH};
    Position *result = BreathFirstSearchLib::getStartPos(3, 3, matrix, BreathFirstSearch::START);
    EXPECT_EQ(1, result->getColumn());
    EXPECT_EQ(0, result->getRow());
}
TEST(BreathFirstSearchLibTest, getStartPos2){
    char matrix[] = {BreathFirstSearch::BLOCKED, BreathFirstSearch::BLOCKED, BreathFirstSearch::PATH,
                      BreathFirstSearch::GOAL, BreathFirstSearch::OPEN, BreathFirstSearch::OPEN,
                      BreathFirstSearch::START, BreathFirstSearch::OPEN, BreathFirstSearch::PATH};
    Position *result = BreathFirstSearchLib::getStartPos(3, 3, matrix, BreathFirstSearch::START);
    EXPECT_EQ(0, result->getColumn());
    EXPECT_EQ(2, result->getRow());
}

TEST(BreathFirstSearchLibTest, getCharField0){
    char matrix[] = {'a', 'b', 'c',
                      'd', 'e', 'f',
                      'g', 'h', 'i'};
    char result = BreathFirstSearchLib::getField(3, 3, matrix, 1, 1);
    EXPECT_EQ('e', result);
}

TEST(BreathFirstSearchLibTest, getCharField1){
    char matrix[] = {'a', 'b', 'c',
                      'd', 'e', 'f',
                      'g', 'h', 'i'};
    char result = BreathFirstSearchLib::getField(3, 3, matrix, 2, 0);
    EXPECT_EQ('c', result);
}

TEST(BreathFirstSearchLibTest, getCharField2){
    char matrix[] = {'a', 'b', 'c',
                      'd', 'e', 'f',
                      'g', 'h', 'i'};
    char result = BreathFirstSearchLib::getField(3, 3, matrix, 0, 2);
    EXPECT_EQ('g', result);
}

TEST(BreathFirstSearchLibTest, setIntField0){
    int matrix[] = {0, 0, 0,
                     0, 0, 0,
                     0, 0, 0};
    BreathFirstSearchLib::setField(3, 3, matrix, 1, 1, new int (1));
    int result = BreathFirstSearchLib::getField(3, 3, matrix, 1, 1);
    EXPECT_EQ(1, result);
}

TEST(BreathFirstSearchLibTest, setIntField1){
    int matrix[] = {0, 0, 0,
                     0, 0, 0,
                     0, 0, 0};
    BreathFirstSearchLib::setField(3, 3, matrix, 2, 0, new int (1));
    int result = BreathFirstSearchLib::getField(3, 3, matrix, 2, 0);
    EXPECT_EQ(1, result);
}

TEST(BreathFirstSearchLibTest, settIntField2){
    int matrix[] = {0, 0, 0,
                     0, 0, 0,
                     0, 0, 0};
    BreathFirstSearchLib::setField(3, 3, matrix, 0, 2, new int (1));
    int result = BreathFirstSearchLib::getField(3, 3, matrix, 0, 2);
    EXPECT_EQ(1, result);
}

TEST(BreathFirstSearchLibTest, setCharField0){
    char matrix[] = {BreathFirstSearch::OPEN, BreathFirstSearch::OPEN, BreathFirstSearch::OPEN,
                      BreathFirstSearch::OPEN, BreathFirstSearch::OPEN, BreathFirstSearch::OPEN,
                      BreathFirstSearch::OPEN, BreathFirstSearch::OPEN, BreathFirstSearch::OPEN};
    BreathFirstSearchLib::setField(3, 3, matrix, 1, 1, new char('b'), BreathFirstSearch::OPEN);
    char result = BreathFirstSearchLib::getField(3, 3, matrix, 1, 1);
    EXPECT_EQ('b', result);
}

TEST(BreathFirstSearchLibTest, setCharField1){
    char matrix[] = {BreathFirstSearch::OPEN, BreathFirstSearch::OPEN, BreathFirstSearch::OPEN,
                      BreathFirstSearch::OPEN, BreathFirstSearch::OPEN, BreathFirstSearch::OPEN,
                      BreathFirstSearch::OPEN, BreathFirstSearch::OPEN, BreathFirstSearch::OPEN};
    BreathFirstSearchLib::setField(3, 3, matrix, 2, 0, new char ('b'), BreathFirstSearch::OPEN);
    char result = BreathFirstSearchLib::getField(3, 3, matrix, 2, 0);
    EXPECT_EQ('b', result);
}

TEST(BreathFirstSearchLibTest, setCharField2){
    char matrix[] = {BreathFirstSearch::OPEN, BreathFirstSearch::OPEN, BreathFirstSearch::OPEN,
                      BreathFirstSearch::OPEN, BreathFirstSearch::OPEN, BreathFirstSearch::OPEN,
                      BreathFirstSearch::OPEN, BreathFirstSearch::OPEN, BreathFirstSearch::OPEN};
    BreathFirstSearchLib::setField(3, 3, matrix, 0, 2, new char('b'), BreathFirstSearch::OPEN);
    char result = BreathFirstSearchLib::getField(3, 3, matrix, 0, 2);
    EXPECT_EQ('b', result);
}

