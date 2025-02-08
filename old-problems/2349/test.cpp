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

  SECTION("Test Case 10") {
    NumberContainers nc;
    nc.change(25, 50);
    nc.change(56, 31);
    REQUIRE(nc.find(50) == 25);
    REQUIRE(nc.find(50) == 25);
    REQUIRE(nc.find(43) == -1);
    nc.change(30, 50);
    REQUIRE(nc.find(31) == 56);
    REQUIRE(nc.find(43) == -1);
    nc.change(25, 20);
    REQUIRE(nc.find(50) == 30);
    nc.change(56, 43);
    nc.change(68, 31);
    nc.change(56, 31);
    REQUIRE(nc.find(20) == 25);
    REQUIRE(nc.find(43) == -1);
    nc.change(25, 43);
    REQUIRE(nc.find(43) == 25);
    nc.change(56, 31);
    nc.change(54, 43);
    nc.change(63, 43);
  }
}
