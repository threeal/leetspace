// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

TEST_CASE("75. Sort Colors") {
  SECTION("Example 1") {
    std::vector<int> nums{2, 0, 2, 1, 1, 0};
    Solution{}.sortColors(nums);
    REQUIRE(nums == std::vector<int>{0, 0, 1, 1, 2, 2});
  }

  SECTION("Example 2") {
    std::vector<int> nums{2, 0, 1};
    Solution{}.sortColors(nums);
    REQUIRE(nums == std::vector<int>{0, 1, 2});
  }
}
