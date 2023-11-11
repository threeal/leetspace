#include <catch2/catch_test_macros.hpp>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#include "solution.cpp"

TEST_CASE("2642. Design Graph With Shortest Path Calculator (cpp)") {
  SECTION("Example 1") {
    vector<vector<int>> edges = {{0, 2, 5}, {0, 1, 2}, {1, 2, 1}, {3, 0, 3}};
    Graph graph(4, edges);

    REQUIRE(graph.shortestPath(3, 2) == 6);
    REQUIRE(graph.shortestPath(0, 3) == -1);
    graph.addEdge({1, 3, 4});
    REQUIRE(graph.shortestPath(0, 3) == 6);
  }
}
