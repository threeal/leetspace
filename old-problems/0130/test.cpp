// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

TEST_CASE("130. Surrounded Regions") {
  SECTION("Example 1") {
    std::vector<std::vector<char>> board{
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}};
    Solution{}.solve(board);
    std::vector<std::vector<char>> expected{
        {'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X'}};
    REQUIRE(board == expected);
  }

  SECTION("Example 2") {
    std::vector<std::vector<char>> board{{'X'}};
    Solution{}.solve(board);
    std::vector<std::vector<char>> expected{{'X'}};
    REQUIRE(board == expected);
  }
}
