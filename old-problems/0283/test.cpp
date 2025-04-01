// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

TEST_CASE("283. Move Zeroes") {
  SECTION("Example 1") {
    std::vector<int> nums{0, 1, 0, 3, 12};
    Solution{}.moveZeroes(nums);
    REQUIRE(nums == std::vector<int>{1, 3, 12, 0, 0});
  }

  SECTION("Example 3") {
    std::vector<int> nums{0};
    Solution{}.moveZeroes(nums);
    REQUIRE(nums == std::vector<int>{0});
  }
}
