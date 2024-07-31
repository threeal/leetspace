// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

TEST_CASE("31. Next Permutation") {
  SECTION("Example 1") {
    std::vector<int> nums{1, 2, 3};
    Solution{}.nextPermutation(nums);
    REQUIRE(nums == std::vector<int>{1, 3, 2});
  }

  SECTION("Example 2") {
    std::vector<int> nums{3, 2, 1};
    Solution{}.nextPermutation(nums);
    REQUIRE(nums == std::vector<int>{1, 2, 3});
  }

  SECTION("Example 3") {
    std::vector<int> nums{1, 1, 5};
    Solution{}.nextPermutation(nums);
    REQUIRE(nums == std::vector<int>{1, 5, 1});
  }

  SECTION("Test Case 202") {
    std::vector<int> nums{1, 3, 2};
    Solution{}.nextPermutation(nums);
    REQUIRE(nums == std::vector<int>{2, 1, 3});
  }

  SECTION("Test Case 213") {
    std::vector<int> nums{1, 5, 1};
    Solution{}.nextPermutation(nums);
    REQUIRE(nums == std::vector<int>{5, 1, 1});
  }
}
