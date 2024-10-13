// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

TEST_CASE("432. All O`one Data Structure") {
  SECTION("Example 1") {
    AllOne allOne{};
    allOne.inc("hello");
    allOne.inc("hello");
    REQUIRE(allOne.getMaxKey() == "hello");
    REQUIRE(allOne.getMinKey() == "hello");
    allOne.inc("leet");
    REQUIRE(allOne.getMaxKey() == "hello");
    REQUIRE(allOne.getMinKey() == "leet");
  }
}
