#include "gtest/gtest.h"
#include "../../../../../../src/ss17/algodat/maze/shortest_path/breadth_first_search/BreathFirstSearch.h"

TEST(test, subTest0)
{
    BreathFirstSearch *bsf = new BreathFirstSearch();
    string result = bsf->getHello();
    EXPECT_EQ("Hello breath-first search!", result);
}

TEST(test, subTest1)
{
    BreathFirstSearch *bsf = new BreathFirstSearch();
    string result = bsf->getHello();
    EXPECT_EQ("Hello breath-first search!", result);
}
