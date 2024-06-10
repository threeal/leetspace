// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("88. Merge Sorted Array") {
  SECTION("Example 1") {
    std::vector<int> nums1{1, 2, 3, 0, 0, 0};
    std::vector<int> nums2{2, 5, 6};
    Solution{}.merge(nums1, 3, nums2, 3);
    REQUIRE(nums1 == std::vector<int>{1, 2, 2, 3, 5, 6});
  }

  SECTION("Example 2") {
    std::vector<int> nums1{1};
    std::vector<int> nums2{};
    Solution{}.merge(nums1, 1, nums2, 0);
    REQUIRE(nums1 == std::vector<int>{1});
  }

  SECTION("Example 3") {
    std::vector<int> nums1{0};
    std::vector<int> nums2{1};
    Solution{}.merge(nums1, 0, nums2, 1);
    REQUIRE(nums1 == std::vector<int>{1});
  }
}
