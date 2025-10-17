// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("3242. Design Neighbor Sum Service") {
  SECTION("Example 1") {
    std::vector<std::vector<int>> grid{{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
    NeighborSum sum(grid);
    REQUIRE(sum.adjacentSum(1) == 6);
    REQUIRE(sum.adjacentSum(4) == 16);
    REQUIRE(sum.diagonalSum(4) == 16);
    REQUIRE(sum.diagonalSum(8) == 4);
  }

  SECTION("Example 2") {
    std::vector<std::vector<int>> grid{
        {1, 2, 0, 3}, {4, 7, 15, 6}, {8, 9, 10, 11}, {12, 13, 14, 5}};

    NeighborSum sum(grid);
    REQUIRE(sum.adjacentSum(15) == 23);
    REQUIRE(sum.diagonalSum(9) == 45);
  }
}
