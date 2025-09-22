// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

TEST_CASE("3508. Implement Router") {
  SECTION("Example 1") {
    Router router(3);
    REQUIRE(router.addPacket(1, 4, 90));
    REQUIRE(router.addPacket(2, 5, 90));
    REQUIRE_FALSE(router.addPacket(1, 4, 90));
    REQUIRE(router.addPacket(3, 5, 95));
    REQUIRE(router.addPacket(4, 5, 105));
    REQUIRE(router.forwardPacket() == std::vector<int>{2, 5, 90});
    REQUIRE(router.addPacket(5, 2, 110));
    REQUIRE(router.getCount(5, 100, 110) == 1);
  }

  SECTION("Example 2") {
    Router router(2);
    REQUIRE(router.addPacket(7, 4, 90));
    REQUIRE(router.forwardPacket() == std::vector<int>{7, 4, 90});
    REQUIRE(router.forwardPacket() == std::vector<int>{});
  }

  SECTION("Test Case 632") {
    Router router(5);
    REQUIRE(router.addPacket(1, 5, 2));
    REQUIRE(router.addPacket(2, 5, 2));
    REQUIRE(router.forwardPacket() == std::vector<int>{1, 5, 2});
    REQUIRE(router.addPacket(2, 5, 3));
    REQUIRE(router.addPacket(1, 3, 3));
  }
}
