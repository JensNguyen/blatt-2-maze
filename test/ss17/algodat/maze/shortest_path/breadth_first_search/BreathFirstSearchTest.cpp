#include "gtest/gtest.h"
#include "../../../../../../src/ss17/algodat/maze/control/shortest_path/breadth_first_search/BreathFirstSearch.h"

TEST(Dummy, foobar)
{
    BreathFirstSearch *bsf = new BreathFirstSearch();
    EXPECT_EQ("Hello breath-first search!", bsf->getHello());
}
