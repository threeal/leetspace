// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

TEST_CASE("1622. Fancy Sequence") {
  SECTION("Example 1") {
    Fancy fancy{};
    fancy.append(2);
    fancy.addAll(3);
    fancy.append(7);
    fancy.multAll(2);
    REQUIRE(fancy.getIndex(0) == 10);
    fancy.addAll(3);
    fancy.append(10);
    fancy.multAll(2);
    REQUIRE(fancy.getIndex(0) == 26);
    REQUIRE(fancy.getIndex(1) == 34);
    REQUIRE(fancy.getIndex(2) == 20);
  }
}
