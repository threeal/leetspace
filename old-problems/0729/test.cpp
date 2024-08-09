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
}
