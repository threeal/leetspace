// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("73. Set Matrix Zeroes") {
  SECTION("Example 1") {
    std::vector<std::vector<int>> matrix{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    Solution{}.setZeroes(matrix);
    std::vector<std::vector<int>> expected{{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
    REQUIRE(matrix == expected);
  }

  SECTION("Example 2") {
    std::vector<std::vector<int>> matrix{
        {0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    Solution{}.setZeroes(matrix);
    std::vector<std::vector<int>> expected{
        {0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}};
    REQUIRE(matrix == expected);
  }

  SECTION("Test Case 5") {
    std::vector<std::vector<int>> matrix{{0, 1}};
    Solution{}.setZeroes(matrix);
    std::vector<std::vector<int>> expected{{0, 0}};
    REQUIRE(matrix == expected);
  }
}
