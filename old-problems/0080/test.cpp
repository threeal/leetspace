// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("80. Remove Duplicates from Sorted Array II") {
  SECTION("Example 1") {
    std::vector<int> nums{1, 1, 1, 2, 2, 3};
    const int size = Solution{}.removeDuplicates(nums);

    nums.resize(size);
    REQUIRE(nums == std::vector<int>{1, 1, 2, 2, 3});
  }

  SECTION("Example 1") {
    std::vector<int> nums{0, 0, 1, 1, 1, 1, 2, 3, 3};
    const int size = Solution{}.removeDuplicates(nums);

    nums.resize(size);
    REQUIRE(nums == std::vector<int>{0, 0, 1, 1, 2, 3, 3});
  }
}
