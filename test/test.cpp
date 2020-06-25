#include "pch.h"
#include <gtest/gtest.h>
#include "../weighted_graph.h"
#include <stdlib.h>

TEST(setEdgeTest, test) {
    Graph testGraph(5);
    testGraph.setEdge(0, 1, 3);
    int weight1 = testGraph.weight(0, 1);
    EXPECT_EQ(3, weight1);
}

TEST(firstTest, test) {
    Graph myGraph(5);
    myGraph.setEdge(0, 1, 3);
    myGraph.setEdge(0, 3, 7);
    myGraph.setEdge(0, 4, 8);
    myGraph.setEdge(1, 2, 1);
    myGraph.setEdge(1, 3, 4);
    myGraph.setEdge(3, 2, 2);
    myGraph.setEdge(4, 3, 3);
    int actual = myGraph.first(0);
    EXPECT_EQ(1, actual);
}

TEST(nextTest, test) {
    Graph myGraph(5);
    myGraph.setEdge(0, 1, 3);
    myGraph.setEdge(0, 3, 7);
    myGraph.setEdge(0, 4, 8);
    myGraph.setEdge(1, 2, 1);
    myGraph.setEdge(1, 3, 4);
    myGraph.setEdge(3, 2, 2);
    myGraph.setEdge(4, 3, 3);
    int actual = myGraph.next(0, 1);
    EXPECT_EQ(3, actual);
}

TEST(allVisitedTest, test) {
    Graph myGraph(5);
    myGraph.setEdge(0, 1, 3);
    myGraph.setEdge(0, 3, 7);
    myGraph.setEdge(0, 4, 8);
    myGraph.setEdge(1, 2, 1);
    myGraph.setEdge(1, 3, 4);
    myGraph.setEdge(3, 2, 2);
    myGraph.setEdge(4, 3, 3);
    myGraph.setMark(3, 1);
    for (int i = 0; i < 5; i++)
        myGraph.setMark(i, 1);
    int actual = myGraph.allVisited();
    EXPECT_EQ(1, actual);
}

TEST(dijkstraTest, test) {
    Graph myGraph(5);
    myGraph.setEdge(0, 1, 3);
    myGraph.setEdge(0, 3, 7);
    myGraph.setEdge(0, 4, 8);
    myGraph.setEdge(1, 2, 1);
    myGraph.setEdge(1, 3, 4);
    myGraph.setEdge(3, 2, 2);
    myGraph.setEdge(4, 3, 3);
    int temp[5];
    myGraph.shortestPath(0, temp);
    EXPECT_EQ(0, *temp);
    EXPECT_EQ(3, temp[1]);
    EXPECT_EQ(4, temp[2]);
    EXPECT_EQ(7, temp[3]);
    EXPECT_EQ(8, temp[4]);

}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
}