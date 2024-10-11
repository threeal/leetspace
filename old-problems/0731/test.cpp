// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

TEST_CASE("731. My Calendar II") {
  SECTION("Example 1") {
    MyCalendarTwo myCalendar{};
    REQUIRE(myCalendar.book(10, 20));
    REQUIRE(myCalendar.book(50, 60));
    REQUIRE(myCalendar.book(10, 40));
    REQUIRE_FALSE(myCalendar.book(5, 15));
    REQUIRE(myCalendar.book(5, 10));
    REQUIRE(myCalendar.book(25, 55));
  }
}
