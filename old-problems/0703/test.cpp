// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

TEST_CASE("703. Kth Largest Element in a Stream") {
  SECTION("Example 1") {
    std::vector<int> nums{4, 5, 8, 2};
    KthLargest kthLargest(3, nums);
    REQUIRE(kthLargest.add(3) == 4);
    REQUIRE(kthLargest.add(5) == 5);
    REQUIRE(kthLargest.add(10) == 5);
    REQUIRE(kthLargest.add(9) == 8);
    REQUIRE(kthLargest.add(4) == 8);
  }

  SECTION("Test Case 1") {
    std::vector<int> nums{};
    KthLargest kthLargest(1, nums);
    REQUIRE(kthLargest.add(-3) == -3);
    REQUIRE(kthLargest.add(-2) == -2);
    REQUIRE(kthLargest.add(-2) == -2);
    REQUIRE(kthLargest.add(0) == 0);
    REQUIRE(kthLargest.add(4) == 4);
  }
}
