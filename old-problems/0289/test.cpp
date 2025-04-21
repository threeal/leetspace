// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

TEST_CASE("289. Game of Life") {
  SECTION("Example 1") {
    std::vector<std::vector<int>> board{{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    Solution{}.gameOfLife(board);

    static const std::vector<std::vector<int>> expected{
        {0, 0, 0}, {1, 0, 1}, {0, 1, 1}, {0, 1, 0}};

    REQUIRE(board == expected);
  }

  SECTION("Example 2") {
    std::vector<std::vector<int>> board{{1, 1}, {1, 0}};
    Solution{}.gameOfLife(board);

    static const std::vector<std::vector<int>> expected{{1, 1}, {1, 1}};
    REQUIRE(board == expected);
  }
}
