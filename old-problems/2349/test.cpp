// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

TEST_CASE("2349. Design a Number Container System") {
  SECTION("Example 1") {
    NumberContainers nc;
    REQUIRE(nc.find(10) == -1);
    nc.change(2, 10);
    nc.change(1, 10);
    nc.change(3, 10);
    nc.change(5, 10);
    REQUIRE(nc.find(10) == 1);
    nc.change(1, 20);
    REQUIRE(nc.find(10) == 2);
  }
}
