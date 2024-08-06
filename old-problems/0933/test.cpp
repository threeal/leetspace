// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

TEST_CASE("933. Number of Recent Calls") {
  SECTION("Example 1") {
    RecentCounter counter;
    REQUIRE(counter.ping(1) == 1);
    REQUIRE(counter.ping(100) == 2);
    REQUIRE(counter.ping(3001) == 3);
    REQUIRE(counter.ping(3002) == 3);
  }
}
