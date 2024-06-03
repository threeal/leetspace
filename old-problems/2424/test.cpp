// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

TEST_CASE("2424. Longest Uploaded Prefix") {
  SECTION("Example 1") {
    LUPrefix luPrefix(4);
    luPrefix.upload(3);
    REQUIRE(luPrefix.longest() == 0);
    luPrefix.upload(1);
    REQUIRE(luPrefix.longest() == 1);
    luPrefix.upload(2);
    REQUIRE(luPrefix.longest() == 3);
  }
}
