// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

TEST_CASE("729. My Calendar I") {
  SECTION("Example 1") {
    MyCalendar myCalendar{};
    REQUIRE(myCalendar.book(10, 20));
    REQUIRE_FALSE(myCalendar.book(15, 25));
    REQUIRE(myCalendar.book(20, 30));
  }

  SECTION("Test Case 2") {
    MyCalendar myCalendar{};
    REQUIRE(myCalendar.book(47, 50));
    REQUIRE(myCalendar.book(33, 41));
    REQUIRE_FALSE(myCalendar.book(39, 45));
    REQUIRE_FALSE(myCalendar.book(33, 42));
    REQUIRE(myCalendar.book(25, 32));
    REQUIRE_FALSE(myCalendar.book(26, 35));
    REQUIRE(myCalendar.book(19, 25));
    REQUIRE(myCalendar.book(3, 8));
    REQUIRE(myCalendar.book(8, 13));
    REQUIRE_FALSE(myCalendar.book(18, 27));
  }
}
