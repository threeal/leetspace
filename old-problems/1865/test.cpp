// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("1865. Finding Pairs With a Certain Sum") {
  SECTION("Example 1") {
    std::vector<int> nums1{1, 1, 2, 2, 2, 3};
    std::vector<int> nums2{1, 4, 5, 2, 5, 4};
    FindSumPairs pairs(nums1, nums2);
    REQUIRE(pairs.count(7) == 8);
    pairs.add(3, 2);
    REQUIRE(pairs.count(8) == 2);
    REQUIRE(pairs.count(4) == 1);
    pairs.add(0, 1);
    pairs.add(1, 1);
    REQUIRE(pairs.count(7) == 11);
  }
}
