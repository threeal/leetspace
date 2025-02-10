// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

TEST_CASE("1845. Seat Reservation Manager") {
  SECTION("Example 1") {
    SeatManager seatManager(5);
    REQUIRE(seatManager.reserve() == 1);
    REQUIRE(seatManager.reserve() == 2);
    seatManager.unreserve(2);
    REQUIRE(seatManager.reserve() == 2);
    REQUIRE(seatManager.reserve() == 3);
    REQUIRE(seatManager.reserve() == 4);
    REQUIRE(seatManager.reserve() == 5);
    seatManager.unreserve(5);
  }
}
