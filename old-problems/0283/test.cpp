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

  SECTION("Test Case 19") {
    std::vector<int> nums{73348, 66106, -85359, 53996, 18849, -6590, -53381, -86613, -41065, 83457, 0};
    Solution{}.moveZeroes(nums);
    REQUIRE(nums == std::vector<int>{73348, 66106, -85359, 53996, 18849, -6590, -53381, -86613, -41065, 83457, 0});
  }
}
