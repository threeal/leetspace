// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

TEST_CASE("2336. Smallest Number in Infinite Set") {
  SECTION("Example 1") {
    SmallestInfiniteSet smallestInfiniteSet;
    smallestInfiniteSet.addBack(2);
    REQUIRE(smallestInfiniteSet.popSmallest() == 1);
    REQUIRE(smallestInfiniteSet.popSmallest() == 2);
    REQUIRE(smallestInfiniteSet.popSmallest() == 3);
    smallestInfiniteSet.addBack(1);
    REQUIRE(smallestInfiniteSet.popSmallest() == 1);
    REQUIRE(smallestInfiniteSet.popSmallest() == 4);
    REQUIRE(smallestInfiniteSet.popSmallest() == 5);
  }

  SECTION("Test Case 134") {
    SmallestInfiniteSet smallestInfiniteSet;
    REQUIRE(smallestInfiniteSet.popSmallest() == 1);
    smallestInfiniteSet.addBack(1);
    smallestInfiniteSet.addBack(1);
    REQUIRE(smallestInfiniteSet.popSmallest() == 1);
    smallestInfiniteSet.addBack(1);
    REQUIRE(smallestInfiniteSet.popSmallest() == 1);
    REQUIRE(smallestInfiniteSet.popSmallest() == 2);
    REQUIRE(smallestInfiniteSet.popSmallest() == 3);
  }
}
