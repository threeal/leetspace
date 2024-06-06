// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("303. Range Sum Query - Immutable") {
  SECTION("Example 1") {
    std::vector<int> array{-2, 0, 3, -5, 2, -1};
    NumArray numArray(array);
    REQUIRE(numArray.sumRange(0, 2) == 1);
    REQUIRE(numArray.sumRange(2, 5) == -1);
    REQUIRE(numArray.sumRange(0, 5) == -3);
  }
}
