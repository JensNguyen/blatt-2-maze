#include <gtest/gtest.h>
#include "../../../../../../src/ss17/algodat/maze/control/shortest_path/breadth_first_search/Position.h"

TEST(PositionTest, create0){
    Position position = Position(1, 2);

    EXPECT_EQ(1, position.getColumn());
    EXPECT_EQ(2, position.getRow());
}

