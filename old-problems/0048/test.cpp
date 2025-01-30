// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

TEST_CASE("48. Rotate Image") {
  SECTION("Example 1") {
    std::vector<std::vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution{}.rotate(matrix);

    static const std::vector<std::vector<int>> expected{
        {7, 4, 1}, {8, 5, 2}, {9, 6, 3}};
    REQUIRE(matrix == expected);
  }

  SECTION("Example 2") {
    std::vector<std::vector<int>> matrix{
        {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    Solution{}.rotate(matrix);

    static const std::vector<std::vector<int>> expected{
        {15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}};
    REQUIRE(matrix == expected);
  }
}
