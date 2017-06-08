#include "gtest/gtest.h"
#include "../../../../../../src/ss17/algodat/maze/control/shortest_path/breadth_first_search/BreadthFirstSearch.h"

TEST(BreadthFirstSearchTest, getIntField0)
{
	int matrix[] = {1, 2, 3,
					4, 5, 6,
					7, 8, 9};
	int result = BreadthFirstSearch::getField(3, 3, matrix, 1, 1);
	EXPECT_EQ(5, result);
}

TEST(BreadthFirstSearchTest, getIntField1)
{
	int matrix[] = {1, 2, 3,
					4, 5, 6,
					7, 8, 9};
	int result = BreadthFirstSearch::getField(3, 3, matrix, 2, 0);
	EXPECT_EQ(3, result);
}

TEST(BreadthFirstSearchTest, getIntField2)
{
	int matrix[] = {1, 2, 3,
					4, 5, 6,
					7, 8, 9};
	int result = BreadthFirstSearch::getField(3, 3, matrix, 0, 2);
	EXPECT_EQ(7, result);
}

TEST(BreadthFirstSearchTest, getStartPos0)
{
	Maze *matrix = new Maze(3, 3);
	matrix->setMazeField(0, 0, Maze::Wall);
	matrix->setMazeField(1, 0, Maze::Way);
	matrix->setMazeField(2, 0, Maze::Result);

	matrix->setMazeField(0, 1, Maze::End);
	matrix->setMazeField(1, 1, Maze::Way);
	matrix->setMazeField(2, 1, Maze::Start);

	matrix->setMazeField(0, 2, Maze::Wall);
	matrix->setMazeField(1, 2, Maze::Way);
	matrix->setMazeField(2, 2, Maze::Result);

	Position *result = BreadthFirstSearch::getStartPos(3, 3, matrix, Maze::Start);
	EXPECT_EQ(2, result->getColumn());
	EXPECT_EQ(1, result->getRow());
}

TEST(BreadthFirstSearchTest, getStartPos1)
{
	Maze *matrix = new Maze(3, 3);
	matrix->setMazeField(0, 0, Maze::Wall);
	matrix->setMazeField(1, 0, Maze::Start);
	matrix->setMazeField(2, 0, Maze::Result);

	matrix->setMazeField(0, 1, Maze::End);
	matrix->setMazeField(1, 1, Maze::Way);
	matrix->setMazeField(2, 1, Maze::Way);

	matrix->setMazeField(0, 2, Maze::Wall);
	matrix->setMazeField(1, 2, Maze::Way);
	matrix->setMazeField(2, 2, Maze::Result);

	Position *result = BreadthFirstSearch::getStartPos(3, 3, matrix, Maze::Start);
	EXPECT_EQ(1, result->getColumn());
	EXPECT_EQ(0, result->getRow());
}

TEST(BreadthFirstSearchTest, getStartPos2)
{
	Maze *matrix = new Maze(3, 3);
	matrix->setMazeField(0, 0, Maze::Wall);
	matrix->setMazeField(1, 0, Maze::Wall);
	matrix->setMazeField(2, 0, Maze::Result);

	matrix->setMazeField(0, 1, Maze::End);
	matrix->setMazeField(1, 1, Maze::Way);
	matrix->setMazeField(2, 1, Maze::Way);

	matrix->setMazeField(0, 2, Maze::Start);
	matrix->setMazeField(1, 2, Maze::Way);
	matrix->setMazeField(2, 2, Maze::Result);

	Position *result = BreadthFirstSearch::getStartPos(3, 3, matrix, Maze::Start);
	EXPECT_EQ(0, result->getColumn());
	EXPECT_EQ(2, result->getRow());
}

TEST(BreadthFirstSearchTest, getStartPos3)
{
	Maze *matrix = new Maze(3, 3);
	matrix->setMazeField(0, 0, Maze::Wall);
	matrix->setMazeField(1, 0, Maze::Wall);
	matrix->setMazeField(2, 0, Maze::Result);

	matrix->setMazeField(0, 1, Maze::End);
	matrix->setMazeField(1, 1, Maze::Way);
	matrix->setMazeField(2, 1, Maze::Way);

	matrix->setMazeField(0, 2, Maze::Way);
	matrix->setMazeField(1, 2, Maze::Way);
	matrix->setMazeField(2, 2, Maze::Result);

	EXPECT_TRUE(nullptr == BreadthFirstSearch::getStartPos(3, 3, matrix, Maze::Start));
}

TEST(BreadthFirstSearchTest, setIntField0)
{
	int matrix[] = {0, 0, 0,
					0, 0, 0,
					0, 0, 0};
	BreadthFirstSearch::setField(3, 3, matrix, 1, 1, new int(1));
	int result = BreadthFirstSearch::getField(3, 3, matrix, 1, 1);
	EXPECT_EQ(1, result);
}

TEST(BreadthFirstSearchTest, setIntField1)
{
	int matrix[] = {0, 0, 0,
					0, 0, 0,
					0, 0, 0};
	BreadthFirstSearch::setField(3, 3, matrix, 2, 0, new int(1));
	int result = BreadthFirstSearch::getField(3, 3, matrix, 2, 0);
	EXPECT_EQ(1, result);
}

TEST(BreadthFirstSearchTest, settIntField2)
{
	int matrix[] = {0, 0, 0,
					0, 0, 0,
					0, 0, 0};
	BreadthFirstSearch::setField(3, 3, matrix, 0, 2, new int(1));
	int result = BreadthFirstSearch::getField(3, 3, matrix, 0, 2);
	EXPECT_EQ(1, result);
}

TEST(BreadthFirstSearchTest, pushFreeAdjacentFields)
{
	Maze *matrix = new Maze(3, 3);
	matrix->setMazeField(0, 0, Maze::Wall);
	matrix->setMazeField(1, 0, Maze::Wall);
	matrix->setMazeField(2, 0, Maze::Wall);
	matrix->setMazeField(2, 0, Maze::Wall);

	matrix->setMazeField(0, 1, Maze::Start);
	matrix->setMazeField(1, 1, Maze::Way);
	matrix->setMazeField(2, 1, Maze::Way);
	matrix->setMazeField(2, 1, Maze::Wall);

	matrix->setMazeField(0, 2, Maze::Wall);
	matrix->setMazeField(1, 2, Maze::Way);
	matrix->setMazeField(2, 2, Maze::Way);
	matrix->setMazeField(2, 2, Maze::Wall);

	matrix->setMazeField(0, 2, Maze::Wall);
	matrix->setMazeField(1, 2, Maze::Wall);
	matrix->setMazeField(2, 2, Maze::Wall);
	matrix->setMazeField(2, 2, Maze::Wall);

	BreadthFirstSearch bfs = BreadthFirstSearch(matrix);

	Position *startPos = bfs.getStartPos(matrix->getWidth(), matrix->getHeight(), matrix, Maze::Start);

	bfs.pushFreeAdjacentFields(startPos);

	EXPECT_EQ(1, bfs.getPositionQueue()->size());
	EXPECT_EQ(Position(1, 1), bfs.getPositionQueue()->front());
}

TEST(BreadthFirstSearchTest, pushFreeAdjacentFields1)
{
	Maze *matrix = new Maze(4, 4);
	matrix->setMazeField(0, 0, Maze::Wall);
	matrix->setMazeField(1, 0, Maze::Wall);
	matrix->setMazeField(2, 0, Maze::Wall);
	matrix->setMazeField(3, 0, Maze::Wall);

	matrix->setMazeField(0, 1, Maze::Start);
	matrix->setMazeField(1, 1, Maze::Way);
	matrix->setMazeField(2, 1, Maze::Way);
	matrix->setMazeField(3, 1, Maze::Wall);

	matrix->setMazeField(0, 2, Maze::Wall);
	matrix->setMazeField(1, 2, Maze::Way);
	matrix->setMazeField(2, 2, Maze::Way);
	matrix->setMazeField(3, 2, Maze::Wall);

	matrix->setMazeField(0, 3, Maze::Wall);
	matrix->setMazeField(1, 3, Maze::Wall);
	matrix->setMazeField(2, 3, Maze::Wall);
	matrix->setMazeField(3, 3, Maze::Wall);

	BreadthFirstSearch bfs = BreadthFirstSearch(matrix);

	Position *startPos = new Position(1, 1);

	bfs.pushFreeAdjacentFields(startPos);

	EXPECT_EQ(2, bfs.getPositionQueue()->size());

	Position first = bfs.getPositionQueue()->front();
	bfs.getPositionQueue()->pop();
	Position second = bfs.getPositionQueue()->front();

	EXPECT_TRUE((first == Position(1, 2) && second == Position(2, 1))
					|| (first == Position(2, 1) && second == Position(1, 2)));
}

TEST(BreadthFirstSearchTest, pushFreeAdjacentFields2)
{
	Maze *matrix = new Maze(4, 4);
	matrix->setMazeField(0, 0, Maze::Wall);
	matrix->setMazeField(1, 0, Maze::Wall);
	matrix->setMazeField(2, 0, Maze::Wall);
	matrix->setMazeField(3, 0, Maze::Wall);

	matrix->setMazeField(0, 1, Maze::Start);
	matrix->setMazeField(1, 1, Maze::Way);
	matrix->setMazeField(2, 1, Maze::Way);
	matrix->setMazeField(3, 1, Maze::Wall);

	matrix->setMazeField(0, 2, Maze::Wall);
	matrix->setMazeField(1, 2, Maze::Way);
	matrix->setMazeField(2, 2, Maze::Way);
	matrix->setMazeField(3, 2, Maze::Wall);

	matrix->setMazeField(0, 3, Maze::Wall);
	matrix->setMazeField(1, 3, Maze::Wall);
	matrix->setMazeField(2, 3, Maze::Wall);
	matrix->setMazeField(3, 3, Maze::Wall);

	BreadthFirstSearch bfs = BreadthFirstSearch(matrix);

	Position *startPos = new Position(2, 2);

	bfs.pushFreeAdjacentFields(startPos);

	EXPECT_EQ(2, bfs.getPositionQueue()->size());

	Position first = bfs.getPositionQueue()->front();
	bfs.getPositionQueue()->pop();
	Position second = bfs.getPositionQueue()->front();

	EXPECT_TRUE((first == Position(2, 1) && second == Position(1, 2))
					|| (first == Position(1, 2) && second == Position(2, 1)));
}

TEST(BreadthFirstSearchTest, consumePosition)
{
	Maze *matrix = new Maze(4, 4);
	matrix->setMazeField(0, 0, Maze::Wall);
	matrix->setMazeField(1, 0, Maze::Wall);
	matrix->setMazeField(2, 0, Maze::Wall);
	matrix->setMazeField(3, 0, Maze::Wall);

	matrix->setMazeField(0, 1, Maze::Start);
	matrix->setMazeField(1, 1, Maze::Way);
	matrix->setMazeField(2, 1, Maze::Way);
	matrix->setMazeField(3, 1, Maze::Wall);

	matrix->setMazeField(0, 2, Maze::Wall);
	matrix->setMazeField(1, 2, Maze::Way);
	matrix->setMazeField(2, 2, Maze::Way);
	matrix->setMazeField(3, 2, Maze::Wall);

	matrix->setMazeField(0, 3, Maze::Wall);
	matrix->setMazeField(1, 3, Maze::Wall);
	matrix->setMazeField(2, 3, Maze::Wall);
	matrix->setMazeField(3, 3, Maze::Wall);

	BreadthFirstSearch bfs = BreadthFirstSearch(matrix);

	Position *startPos = bfs.getStartPos(matrix->getWidth(), matrix->getHeight(), matrix, Maze::Start);

	bfs.pushFreeAdjacentFields(startPos);

	bfs.consumePosition();

	EXPECT_EQ(2, bfs.getPositionQueue()->size());

	Position first = bfs.getPositionQueue()->front();
	bfs.getPositionQueue()->pop();
	Position second = bfs.getPositionQueue()->front();

	EXPECT_TRUE((first == Position(1, 2) && second == Position(2, 1))
					|| (first == Position(2, 1) && second == Position(1, 2)));
}

TEST(BreadthFirstSearchTest, consumeField)
{
	Maze *matrix = new Maze(4, 4);
	matrix->setMazeField(0, 0, Maze::Wall);
	matrix->setMazeField(1, 0, Maze::Wall);
	matrix->setMazeField(2, 0, Maze::Wall);
	matrix->setMazeField(3, 0, Maze::Wall);

	matrix->setMazeField(0, 1, Maze::Start);
	matrix->setMazeField(1, 1, Maze::Way);
	matrix->setMazeField(2, 1, Maze::Way);
	matrix->setMazeField(3, 1, Maze::Wall);

	matrix->setMazeField(0, 2, Maze::Wall);
	matrix->setMazeField(1, 2, Maze::Way);
	matrix->setMazeField(2, 2, Maze::Way);
	matrix->setMazeField(3, 2, Maze::Wall);

	matrix->setMazeField(0, 3, Maze::Wall);
	matrix->setMazeField(1, 3, Maze::Wall);
	matrix->setMazeField(2, 3, Maze::End);
	matrix->setMazeField(3, 3, Maze::Wall);

	BreadthFirstSearch bfs = BreadthFirstSearch(matrix);

	Position startPos = Position(2, 2);

	bfs.consumeField(startPos, 0, -1);

	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 0, 0));
	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 1, 0));
	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 2, 0));
	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 3, 0));

	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 0, 1));
	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 1, 1));
	EXPECT_EQ(1, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 2, 1));
	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 3, 1));

	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 0, 2));
	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 1, 2));
	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 2, 2));
	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 3, 2));

	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 0, 3));
	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 1, 3));
	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 2, 3));
	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 3, 3));

	EXPECT_TRUE(bfs.getLastField() == nullptr);
}

TEST(BreadthFirstSearchTest, consumeField1)
{
	Maze *matrix = new Maze(4, 4);
	matrix->setMazeField(0, 0, Maze::Wall);
	matrix->setMazeField(1, 0, Maze::Wall);
	matrix->setMazeField(2, 0, Maze::Wall);
	matrix->setMazeField(3, 0, Maze::Wall);

	matrix->setMazeField(0, 1, Maze::Start);
	matrix->setMazeField(1, 1, Maze::Way);
	matrix->setMazeField(2, 1, Maze::Way);
	matrix->setMazeField(3, 1, Maze::Wall);

	matrix->setMazeField(0, 2, Maze::Wall);
	matrix->setMazeField(1, 2, Maze::Way);
	matrix->setMazeField(2, 2, Maze::Way);
	matrix->setMazeField(3, 2, Maze::End);

	matrix->setMazeField(0, 3, Maze::Wall);
	matrix->setMazeField(1, 3, Maze::Wall);
	matrix->setMazeField(2, 3, Maze::Wall);
	matrix->setMazeField(3, 3, Maze::Wall);

	BreadthFirstSearch bfs = BreadthFirstSearch(matrix);

	Position startPos = Position(2, 2);

	bfs.consumeField(startPos, 1, 0);

	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 0, 0));
	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 1, 0));
	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 2, 0));
	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 3, 0));

	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 0, 1));
	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 1, 1));
	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 2, 1));
	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 3, 1));

	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 0, 2));
	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 1, 2));
	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 2, 2));
	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 3, 2));

	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 0, 3));
	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 1, 3));
	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 2, 3));
	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 3, 3));

	EXPECT_TRUE(*bfs.getLastField() == Position(2, 2));
}

TEST(BreadthFirstSearchTest, consumeField2)
{
	Maze *matrix = new Maze(4, 4);
	matrix->setMazeField(0, 0, Maze::Wall);
	matrix->setMazeField(1, 0, Maze::Wall);
	matrix->setMazeField(2, 0, Maze::Wall);
	matrix->setMazeField(3, 0, Maze::Wall);

	matrix->setMazeField(0, 1, Maze::Start);
	matrix->setMazeField(1, 1, Maze::Way);
	matrix->setMazeField(2, 1, Maze::Way);
	matrix->setMazeField(3, 1, Maze::Wall);

	matrix->setMazeField(0, 2, Maze::Wall);
	matrix->setMazeField(1, 2, Maze::Way);
	matrix->setMazeField(2, 2, Maze::Way);
	matrix->setMazeField(3, 2, Maze::End);

	matrix->setMazeField(0, 3, Maze::Wall);
	matrix->setMazeField(1, 3, Maze::Wall);
	matrix->setMazeField(2, 3, Maze::Wall);
	matrix->setMazeField(3, 3, Maze::Wall);

	BreadthFirstSearch bfs = BreadthFirstSearch(matrix);

	Position startPos = Position(2, 2);

	bfs.consumeField(startPos, 0, 1);

	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 0, 0));
	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 1, 0));
	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 2, 0));
	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 3, 0));

	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 0, 1));
	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 1, 1));
	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 2, 1));
	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 3, 1));

	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 0, 2));
	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 1, 2));
	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 2, 2));
	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 3, 2));

	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 0, 3));
	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 1, 3));
	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 2, 3));
	EXPECT_EQ(0, bfs.getField(matrix->getWidth(), matrix->getHeight(), bfs.getSolution(), 3, 3));

	EXPECT_TRUE(bfs.getLastField() == nullptr);
}

TEST(BreadthFirstSearchTest, searchForNextFieldOnShortestPath)
{
	Maze *matrix = new Maze(4, 4);
	matrix->setMazeField(0, 0, Maze::Wall);
	matrix->setMazeField(1, 0, Maze::Wall);
	matrix->setMazeField(2, 0, Maze::Wall);
	matrix->setMazeField(3, 0, Maze::Wall);

	matrix->setMazeField(0, 1, Maze::Start);
	matrix->setMazeField(1, 1, Maze::Way);
	matrix->setMazeField(2, 1, Maze::Way);
	matrix->setMazeField(3, 1, Maze::Wall);

	matrix->setMazeField(0, 2, Maze::Wall);
	matrix->setMazeField(1, 2, Maze::Wall);
	matrix->setMazeField(2, 2, Maze::Way);
	matrix->setMazeField(3, 2, Maze::End);

	matrix->setMazeField(0, 3, Maze::Wall);
	matrix->setMazeField(1, 3, Maze::Wall);
	matrix->setMazeField(2, 3, Maze::Wall);
	matrix->setMazeField(3, 3, Maze::Wall);

	BreadthFirstSearch bfs = BreadthFirstSearch(matrix);

	bfs.pushFreeAdjacentFields(bfs.getStartPos(matrix->getWidth(), matrix->getHeight(), matrix, Maze::Start));

	bfs.consumePosition();
	bfs.consumePosition();
	bfs.consumePosition();

	Position *result = bfs.searchForNextFieldOnShortestPath(*bfs.getLastField(), 2);

	EXPECT_TRUE(*result == Position(2, 1));
}

TEST(BreadthFirstSearchTest, searchForNextFieldOnShortestPath1)
{
	Maze *matrix = new Maze(4, 4);
	matrix->setMazeField(0, 0, Maze::Wall);
	matrix->setMazeField(1, 0, Maze::Wall);
	matrix->setMazeField(2, 0, Maze::Wall);
	matrix->setMazeField(3, 0, Maze::Wall);

	matrix->setMazeField(0, 1, Maze::Start);
	matrix->setMazeField(1, 1, Maze::Way);
	matrix->setMazeField(2, 1, Maze::Wall);
	matrix->setMazeField(3, 1, Maze::Wall);

	matrix->setMazeField(0, 2, Maze::Wall);
	matrix->setMazeField(1, 2, Maze::Way);
	matrix->setMazeField(2, 2, Maze::Way);
	matrix->setMazeField(3, 2, Maze::End);

	matrix->setMazeField(0, 3, Maze::Wall);
	matrix->setMazeField(1, 3, Maze::Wall);
	matrix->setMazeField(2, 3, Maze::Wall);
	matrix->setMazeField(3, 3, Maze::Wall);

	BreadthFirstSearch bfs = BreadthFirstSearch(matrix);

	bfs.pushFreeAdjacentFields(bfs.getStartPos(matrix->getWidth(), matrix->getHeight(), matrix, Maze::Start));

	bfs.consumePosition();
	bfs.consumePosition();
	bfs.consumePosition();

	Position *result = bfs.searchForNextFieldOnShortestPath(*bfs.getLastField(), 2);

	EXPECT_TRUE(*result == Position(1, 2));
}

TEST(BreadthFirstSearchTest, searchForNextFieldOnShortestPath2)
{
	Maze *matrix = new Maze(4, 4);
	matrix->setMazeField(0, 0, Maze::Wall);
	matrix->setMazeField(1, 0, Maze::Wall);
	matrix->setMazeField(2, 0, Maze::Wall);
	matrix->setMazeField(3, 0, Maze::Wall);

	matrix->setMazeField(0, 1, Maze::End);
	matrix->setMazeField(1, 1, Maze::Way);
	matrix->setMazeField(2, 1, Maze::Wall);
	matrix->setMazeField(3, 1, Maze::Wall);

	matrix->setMazeField(0, 2, Maze::Wall);
	matrix->setMazeField(1, 2, Maze::Way);
	matrix->setMazeField(2, 2, Maze::Way);
	matrix->setMazeField(3, 2, Maze::Start);

	matrix->setMazeField(0, 3, Maze::Wall);
	matrix->setMazeField(1, 3, Maze::Wall);
	matrix->setMazeField(2, 3, Maze::Wall);
	matrix->setMazeField(3, 3, Maze::Wall);

	BreadthFirstSearch bfs = BreadthFirstSearch(matrix);

	bfs.pushFreeAdjacentFields(bfs.getStartPos(matrix->getWidth(), matrix->getHeight(), matrix, Maze::Start));

	bfs.consumePosition();
	bfs.consumePosition();
	bfs.consumePosition();

	Position *result = bfs.searchForNextFieldOnShortestPath(*bfs.getLastField(), 2);

	EXPECT_TRUE(*result == Position(1, 2));
}

TEST(BreadthFirstSearchTest, searchForNextFieldOnShortestPath3)
{
	Maze *matrix = new Maze(4, 4);
	matrix->setMazeField(0, 0, Maze::Wall);
	matrix->setMazeField(1, 0, Maze::Wall);
	matrix->setMazeField(2, 0, Maze::Wall);
	matrix->setMazeField(3, 0, Maze::Wall);

	matrix->setMazeField(0, 1, Maze::End);
	matrix->setMazeField(1, 1, Maze::Way);
	matrix->setMazeField(2, 1, Maze::Way);
	matrix->setMazeField(3, 1, Maze::Wall);

	matrix->setMazeField(0, 2, Maze::Wall);
	matrix->setMazeField(1, 2, Maze::Wall);
	matrix->setMazeField(2, 2, Maze::Way);
	matrix->setMazeField(3, 2, Maze::Start);

	matrix->setMazeField(0, 3, Maze::Wall);
	matrix->setMazeField(1, 3, Maze::Wall);
	matrix->setMazeField(2, 3, Maze::Wall);
	matrix->setMazeField(3, 3, Maze::Wall);

	BreadthFirstSearch bfs = BreadthFirstSearch(matrix);

	bfs.pushFreeAdjacentFields(bfs.getStartPos(matrix->getWidth(), matrix->getHeight(), matrix, Maze::Start));

	bfs.consumePosition();
	bfs.consumePosition();
	bfs.consumePosition();

	Position *result = bfs.searchForNextFieldOnShortestPath(*bfs.getLastField(), 2);

	EXPECT_TRUE(*result == Position(2, 1));
}

TEST(BreadthFirstSearchTest, plotSolution)
{
	Maze *matrix = new Maze(4, 4);
	matrix->setMazeField(0, 0, Maze::Wall);
	matrix->setMazeField(1, 0, Maze::Wall);
	matrix->setMazeField(2, 0, Maze::Wall);
	matrix->setMazeField(3, 0, Maze::Wall);

	matrix->setMazeField(0, 1, Maze::Start);
	matrix->setMazeField(1, 1, Maze::Way);
	matrix->setMazeField(2, 1, Maze::Way);
	matrix->setMazeField(3, 1, Maze::Wall);

	matrix->setMazeField(0, 2, Maze::Wall);
	matrix->setMazeField(1, 2, Maze::Wall);
	matrix->setMazeField(2, 2, Maze::Way);
	matrix->setMazeField(3, 2, Maze::End);

	matrix->setMazeField(0, 3, Maze::Wall);
	matrix->setMazeField(1, 3, Maze::Wall);
	matrix->setMazeField(2, 3, Maze::Wall);
	matrix->setMazeField(3, 3, Maze::Wall);

	BreadthFirstSearch bfs = BreadthFirstSearch(matrix);

	bfs.pushFreeAdjacentFields(bfs.getStartPos(matrix->getWidth(), matrix->getHeight(), matrix, Maze::Start));

	bfs.consumePosition();
	bfs.consumePosition();
	bfs.consumePosition();

	bfs.plotSolution(*bfs.getLastField());

	EXPECT_TRUE(Maze::Wall == matrix->getMazeField(0, 0));
	EXPECT_TRUE(Maze::Wall == matrix->getMazeField(1, 0));
	EXPECT_TRUE(Maze::Wall == matrix->getMazeField(2, 0));
	EXPECT_TRUE(Maze::Wall == matrix->getMazeField(3, 0));

	EXPECT_TRUE(Maze::Start == matrix->getMazeField(0, 1));
	EXPECT_TRUE(Maze::Result == matrix->getMazeField(1, 1));
	EXPECT_TRUE(Maze::Result == matrix->getMazeField(2, 1));
	EXPECT_TRUE(Maze::Wall == matrix->getMazeField(3, 1));

	EXPECT_TRUE(Maze::Wall == matrix->getMazeField(0, 2));
	EXPECT_TRUE(Maze::Wall == matrix->getMazeField(1, 2));
	EXPECT_TRUE(Maze::Result == matrix->getMazeField(2, 2));
	EXPECT_TRUE(Maze::End == matrix->getMazeField(3, 2));

	EXPECT_TRUE(Maze::Wall == matrix->getMazeField(0, 3));
	EXPECT_TRUE(Maze::Wall == matrix->getMazeField(1, 3));
	EXPECT_TRUE(Maze::Wall == matrix->getMazeField(2, 3));
	EXPECT_TRUE(Maze::Wall == matrix->getMazeField(3, 3));
}

TEST(BreadthFirstSearchTest, solve)
{
	Maze *matrix = new Maze(4, 4);
	matrix->setMazeField(0, 0, Maze::Wall);
	matrix->setMazeField(1, 0, Maze::Wall);
	matrix->setMazeField(2, 0, Maze::Wall);
	matrix->setMazeField(3, 0, Maze::Wall);

	matrix->setMazeField(0, 1, Maze::Start);
	matrix->setMazeField(1, 1, Maze::Way);
	matrix->setMazeField(2, 1, Maze::Way);
	matrix->setMazeField(3, 1, Maze::Wall);

	matrix->setMazeField(0, 2, Maze::Wall);
	matrix->setMazeField(1, 2, Maze::Wall);
	matrix->setMazeField(2, 2, Maze::Way);
	matrix->setMazeField(3, 2, Maze::End);

	matrix->setMazeField(0, 3, Maze::Wall);
	matrix->setMazeField(1, 3, Maze::Wall);
	matrix->setMazeField(2, 3, Maze::Wall);
	matrix->setMazeField(3, 3, Maze::Wall);

	BreadthFirstSearch bfs = BreadthFirstSearch(matrix);

	int steps = -1;

	EXPECT_TRUE(bfs.solve(steps));
	EXPECT_EQ(2, steps);
}

TEST(BreadthFirstSearchTest, solve1)
{
	Maze *matrix = new Maze(4, 4);
	matrix->setMazeField(0, 0, Maze::Wall);
	matrix->setMazeField(1, 0, Maze::Wall);
	matrix->setMazeField(2, 0, Maze::Wall);
	matrix->setMazeField(3, 0, Maze::Wall);

	matrix->setMazeField(0, 1, Maze::Start);
	matrix->setMazeField(1, 1, Maze::Way);
	matrix->setMazeField(2, 1, Maze::Way);
	matrix->setMazeField(3, 1, Maze::Wall);

	matrix->setMazeField(0, 2, Maze::Wall);
	matrix->setMazeField(1, 2, Maze::Way);
	matrix->setMazeField(2, 2, Maze::Wall);
	matrix->setMazeField(3, 2, Maze::End);

	matrix->setMazeField(0, 3, Maze::Wall);
	matrix->setMazeField(1, 3, Maze::Wall);
	matrix->setMazeField(2, 3, Maze::Wall);
	matrix->setMazeField(3, 3, Maze::Wall);

	BreadthFirstSearch bfs = BreadthFirstSearch(matrix);

	int steps = -1;

	EXPECT_FALSE(bfs.solve(steps));
	EXPECT_EQ(2, steps);
}

TEST(BreadthFirstSearchTest, lengthOfShortestPath)
{
	Maze *matrix = new Maze(4, 4);
	matrix->setMazeField(0, 0, Maze::Wall);
	matrix->setMazeField(1, 0, Maze::Wall);
	matrix->setMazeField(2, 0, Maze::Wall);
	matrix->setMazeField(3, 0, Maze::Wall);

	matrix->setMazeField(0, 1, Maze::Start);
	matrix->setMazeField(1, 1, Maze::Way);
	matrix->setMazeField(2, 1, Maze::Way);
	matrix->setMazeField(3, 1, Maze::Wall);

	matrix->setMazeField(0, 2, Maze::Wall);
	matrix->setMazeField(1, 2, Maze::Way);
	matrix->setMazeField(2, 2, Maze::Wall);
	matrix->setMazeField(3, 2, Maze::End);

	matrix->setMazeField(0, 3, Maze::Wall);
	matrix->setMazeField(1, 3, Maze::Wall);
	matrix->setMazeField(2, 3, Maze::Wall);
	matrix->setMazeField(3, 3, Maze::Wall);

	BreadthFirstSearch bfs = BreadthFirstSearch(matrix);

	int steps = -1;

	bfs.solve(steps);
	EXPECT_EQ(-1, bfs.getLengthOfShortestPath());
}

TEST(BreadthFirstSearchTest, lengthOfShortestPath1)
{
	Maze *matrix = new Maze(4, 4);
	matrix->setMazeField(0, 0, Maze::Wall);
	matrix->setMazeField(1, 0, Maze::Wall);
	matrix->setMazeField(2, 0, Maze::Wall);
	matrix->setMazeField(3, 0, Maze::Wall);

	matrix->setMazeField(0, 1, Maze::Start);
	matrix->setMazeField(1, 1, Maze::Way);
	matrix->setMazeField(2, 1, Maze::Way);
	matrix->setMazeField(3, 1, Maze::Wall);

	matrix->setMazeField(0, 2, Maze::Wall);
	matrix->setMazeField(1, 2, Maze::Way);
	matrix->setMazeField(2, 2, Maze::Way);
	matrix->setMazeField(3, 2, Maze::End);

	matrix->setMazeField(0, 3, Maze::Wall);
	matrix->setMazeField(1, 3, Maze::Wall);
	matrix->setMazeField(2, 3, Maze::Wall);
	matrix->setMazeField(3, 3, Maze::Wall);

	BreadthFirstSearch bfs = BreadthFirstSearch(matrix);

	int steps = -1;

	bfs.solve(steps);
	EXPECT_EQ(3, bfs.getLengthOfShortestPath());
}

TEST(BreadthFirstSearchTest, getField)
{
	Maze *matrix = new Maze(4, 4);
	matrix->setMazeField(0, 0, Maze::Wall);
	matrix->setMazeField(1, 0, Maze::Wall);
	matrix->setMazeField(2, 0, Maze::Wall);
	matrix->setMazeField(3, 0, Maze::Wall);

	matrix->setMazeField(0, 1, Maze::Start);
	matrix->setMazeField(1, 1, Maze::Way);
	matrix->setMazeField(2, 1, Maze::Way);
	matrix->setMazeField(3, 1, Maze::Wall);

	matrix->setMazeField(0, 2, Maze::Wall);
	matrix->setMazeField(1, 2, Maze::Way);
	matrix->setMazeField(2, 2, Maze::Way);
	matrix->setMazeField(3, 2, Maze::End);

	matrix->setMazeField(0, 3, Maze::Wall);
	matrix->setMazeField(1, 3, Maze::Wall);
	matrix->setMazeField(2, 3, Maze::Wall);
	matrix->setMazeField(3, 3, Maze::Wall);

	int *solution = new int[3 * 3]{};

	BreadthFirstSearch bfs = BreadthFirstSearch(matrix);

	try
	{
		bfs.getField(3, 3, solution, -1, 2);
		FAIL();
	}
	catch( const invalid_argument& err )
	{
		// check exception
		ASSERT_STREQ( "Row or column out of bounds!", err.what() );
	}
}

TEST(BreadthFirstSearchTest, getField1)
{
	Maze *matrix = new Maze(4, 4);
	matrix->setMazeField(0, 0, Maze::Wall);
	matrix->setMazeField(1, 0, Maze::Wall);
	matrix->setMazeField(2, 0, Maze::Wall);
	matrix->setMazeField(3, 0, Maze::Wall);

	matrix->setMazeField(0, 1, Maze::Start);
	matrix->setMazeField(1, 1, Maze::Way);
	matrix->setMazeField(2, 1, Maze::Way);
	matrix->setMazeField(3, 1, Maze::Wall);

	matrix->setMazeField(0, 2, Maze::Wall);
	matrix->setMazeField(1, 2, Maze::Way);
	matrix->setMazeField(2, 2, Maze::Way);
	matrix->setMazeField(3, 2, Maze::End);

	matrix->setMazeField(0, 3, Maze::Wall);
	matrix->setMazeField(1, 3, Maze::Wall);
	matrix->setMazeField(2, 3, Maze::Wall);
	matrix->setMazeField(3, 3, Maze::Wall);

	int *solution = new int[3 * 3]{};

	BreadthFirstSearch bfs = BreadthFirstSearch(matrix);

	try
	{
		bfs.getField(3, 3, solution, 1, 3);
		FAIL();
	}
	catch( const invalid_argument& err )
	{
		// check exception
		ASSERT_STREQ( "Row or column out of bounds!", err.what() );
	}
}

TEST(BreadthFirstSearchTest, getField2)
{
	Maze *matrix = new Maze(4, 4);
	matrix->setMazeField(0, 0, Maze::Wall);
	matrix->setMazeField(1, 0, Maze::Wall);
	matrix->setMazeField(2, 0, Maze::Wall);
	matrix->setMazeField(3, 0, Maze::Wall);

	matrix->setMazeField(0, 1, Maze::Start);
	matrix->setMazeField(1, 1, Maze::Way);
	matrix->setMazeField(2, 1, Maze::Way);
	matrix->setMazeField(3, 1, Maze::Wall);

	matrix->setMazeField(0, 2, Maze::Wall);
	matrix->setMazeField(1, 2, Maze::Way);
	matrix->setMazeField(2, 2, Maze::Way);
	matrix->setMazeField(3, 2, Maze::End);

	matrix->setMazeField(0, 3, Maze::Wall);
	matrix->setMazeField(1, 3, Maze::Wall);
	matrix->setMazeField(2, 3, Maze::Wall);
	matrix->setMazeField(3, 3, Maze::Wall);

	int *solution = new int[3 * 3]{};

	BreadthFirstSearch bfs = BreadthFirstSearch(matrix);

	try
	{
		bfs.getField(3, 3, solution, 2, -1);
		FAIL();
	}
	catch( const invalid_argument& err )
	{
		// check exception
		ASSERT_STREQ( "Row or column out of bounds!", err.what() );
	}
}

TEST(BreadthFirstSearchTest, getField3)
{
	Maze *matrix = new Maze(4, 4);
	matrix->setMazeField(0, 0, Maze::Wall);
	matrix->setMazeField(1, 0, Maze::Wall);
	matrix->setMazeField(2, 0, Maze::Wall);
	matrix->setMazeField(3, 0, Maze::Wall);

	matrix->setMazeField(0, 1, Maze::Start);
	matrix->setMazeField(1, 1, Maze::Way);
	matrix->setMazeField(2, 1, Maze::Way);
	matrix->setMazeField(3, 1, Maze::Wall);

	matrix->setMazeField(0, 2, Maze::Wall);
	matrix->setMazeField(1, 2, Maze::Way);
	matrix->setMazeField(2, 2, Maze::Way);
	matrix->setMazeField(3, 2, Maze::End);

	matrix->setMazeField(0, 3, Maze::Wall);
	matrix->setMazeField(1, 3, Maze::Wall);
	matrix->setMazeField(2, 3, Maze::Wall);
	matrix->setMazeField(3, 3, Maze::Wall);

	int *solution = new int[3 * 3]{};

	BreadthFirstSearch bfs = BreadthFirstSearch(matrix);

	try
	{
		bfs.getField(3, 3, solution, 3, 1);
		FAIL();
	}
	catch( const invalid_argument& err )
	{
		// check exception
		ASSERT_STREQ( "Row or column out of bounds!", err.what() );
	}
}

TEST(BreadthFirstSearchTest, setField)
{
	Maze *matrix = new Maze(4, 4);
	matrix->setMazeField(0, 0, Maze::Wall);
	matrix->setMazeField(1, 0, Maze::Wall);
	matrix->setMazeField(2, 0, Maze::Wall);
	matrix->setMazeField(3, 0, Maze::Wall);

	matrix->setMazeField(0, 1, Maze::Start);
	matrix->setMazeField(1, 1, Maze::Way);
	matrix->setMazeField(2, 1, Maze::Way);
	matrix->setMazeField(3, 1, Maze::Wall);

	matrix->setMazeField(0, 2, Maze::Wall);
	matrix->setMazeField(1, 2, Maze::Way);
	matrix->setMazeField(2, 2, Maze::Way);
	matrix->setMazeField(3, 2, Maze::End);

	matrix->setMazeField(0, 3, Maze::Wall);
	matrix->setMazeField(1, 3, Maze::Wall);
	matrix->setMazeField(2, 3, Maze::Wall);
	matrix->setMazeField(3, 3, Maze::Wall);

	int *solution = new int[3 * 3]{};

	BreadthFirstSearch bfs = BreadthFirstSearch(matrix);

	try
	{
		bfs.setField(3, 3, solution, -1, 2, new int(-1));
		FAIL();
	}
	catch( const invalid_argument& err )
	{
		// check exception
		ASSERT_STREQ( "Row or column out of bounds!", err.what() );
	}
}

TEST(BreadthFirstSearchTest, setField1)
{
	Maze *matrix = new Maze(4, 4);
	matrix->setMazeField(0, 0, Maze::Wall);
	matrix->setMazeField(1, 0, Maze::Wall);
	matrix->setMazeField(2, 0, Maze::Wall);
	matrix->setMazeField(3, 0, Maze::Wall);

	matrix->setMazeField(0, 1, Maze::Start);
	matrix->setMazeField(1, 1, Maze::Way);
	matrix->setMazeField(2, 1, Maze::Way);
	matrix->setMazeField(3, 1, Maze::Wall);

	matrix->setMazeField(0, 2, Maze::Wall);
	matrix->setMazeField(1, 2, Maze::Way);
	matrix->setMazeField(2, 2, Maze::Way);
	matrix->setMazeField(3, 2, Maze::End);

	matrix->setMazeField(0, 3, Maze::Wall);
	matrix->setMazeField(1, 3, Maze::Wall);
	matrix->setMazeField(2, 3, Maze::Wall);
	matrix->setMazeField(3, 3, Maze::Wall);

	int *solution = new int[3 * 3]{};

	BreadthFirstSearch bfs = BreadthFirstSearch(matrix);

	try
	{
		bfs.setField(3, 3, solution, 1, 3, new int(-1));
		FAIL();
	}
	catch( const invalid_argument& err )
	{
		// check exception
		ASSERT_STREQ( "Row or column out of bounds!", err.what() );
	}
}

TEST(BreadthFirstSearchTest, setField2)
{
	Maze *matrix = new Maze(4, 4);
	matrix->setMazeField(0, 0, Maze::Wall);
	matrix->setMazeField(1, 0, Maze::Wall);
	matrix->setMazeField(2, 0, Maze::Wall);
	matrix->setMazeField(3, 0, Maze::Wall);

	matrix->setMazeField(0, 1, Maze::Start);
	matrix->setMazeField(1, 1, Maze::Way);
	matrix->setMazeField(2, 1, Maze::Way);
	matrix->setMazeField(3, 1, Maze::Wall);

	matrix->setMazeField(0, 2, Maze::Wall);
	matrix->setMazeField(1, 2, Maze::Way);
	matrix->setMazeField(2, 2, Maze::Way);
	matrix->setMazeField(3, 2, Maze::End);

	matrix->setMazeField(0, 3, Maze::Wall);
	matrix->setMazeField(1, 3, Maze::Wall);
	matrix->setMazeField(2, 3, Maze::Wall);
	matrix->setMazeField(3, 3, Maze::Wall);

	int *solution = new int[3 * 3]{};

	BreadthFirstSearch bfs = BreadthFirstSearch(matrix);

	try
	{
		bfs.setField(3, 3, solution, 2, -1, new int(-1));
		FAIL();
	}
	catch( const invalid_argument& err )
	{
		// check exception
		ASSERT_STREQ( "Row or column out of bounds!", err.what() );
	}
}

TEST(BreadthFirstSearchTest, setField3)
{
	Maze *matrix = new Maze(4, 4);
	matrix->setMazeField(0, 0, Maze::Wall);
	matrix->setMazeField(1, 0, Maze::Wall);
	matrix->setMazeField(2, 0, Maze::Wall);
	matrix->setMazeField(3, 0, Maze::Wall);

	matrix->setMazeField(0, 1, Maze::Start);
	matrix->setMazeField(1, 1, Maze::Way);
	matrix->setMazeField(2, 1, Maze::Way);
	matrix->setMazeField(3, 1, Maze::Wall);

	matrix->setMazeField(0, 2, Maze::Wall);
	matrix->setMazeField(1, 2, Maze::Way);
	matrix->setMazeField(2, 2, Maze::Way);
	matrix->setMazeField(3, 2, Maze::End);

	matrix->setMazeField(0, 3, Maze::Wall);
	matrix->setMazeField(1, 3, Maze::Wall);
	matrix->setMazeField(2, 3, Maze::Wall);
	matrix->setMazeField(3, 3, Maze::Wall);

	int *solution = new int[3 * 3]{};

	BreadthFirstSearch bfs = BreadthFirstSearch(matrix);

	try
	{
		bfs.setField(3, 3, solution, 3, 1, new int(-1));
		FAIL();
	}
	catch( const invalid_argument& err )
	{
		// check exception
		ASSERT_STREQ( "Row or column out of bounds!", err.what() );
	}
}

TEST(BreadthFirstSearchTest, setField4)
{
	Maze *matrix = new Maze(4, 4);
	matrix->setMazeField(0, 0, Maze::Wall);
	matrix->setMazeField(1, 0, Maze::Wall);
	matrix->setMazeField(2, 0, Maze::Wall);
	matrix->setMazeField(3, 0, Maze::Wall);

	matrix->setMazeField(0, 1, Maze::Start);
	matrix->setMazeField(1, 1, Maze::Way);
	matrix->setMazeField(2, 1, Maze::Way);
	matrix->setMazeField(3, 1, Maze::Wall);

	matrix->setMazeField(0, 2, Maze::Wall);
	matrix->setMazeField(1, 2, Maze::Way);
	matrix->setMazeField(2, 2, Maze::Way);
	matrix->setMazeField(3, 2, Maze::End);

	matrix->setMazeField(0, 3, Maze::Wall);
	matrix->setMazeField(1, 3, Maze::Wall);
	matrix->setMazeField(2, 3, Maze::Wall);
	matrix->setMazeField(3, 3, Maze::Wall);

	int *solution = new int[3 * 3]{};

	BreadthFirstSearch bfs = BreadthFirstSearch(matrix);

	try
	{
		bfs.setField(3, 3, solution, 1, 1, new int(1));
		bfs.setField(3, 3, solution, 1, 1, new int(1));
		FAIL();
	}
	catch( const invalid_argument& err )
	{
		// check exception
		ASSERT_STREQ( "You can only edit fields which are set "
						  "to zero!", err.what() );
	}
}