// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

TEST_CASE("732. My Calendar III") {
  SECTION("Example 1") {
    MyCalendarThree calendar;
    REQUIRE(calendar.book(10, 20) == 1);
    REQUIRE(calendar.book(50, 60) == 1);
    REQUIRE(calendar.book(10, 40) == 2);
    REQUIRE(calendar.book(5, 15) == 3);
    REQUIRE(calendar.book(5, 10) == 3);
    REQUIRE(calendar.book(25, 55) == 3);
  }
}
