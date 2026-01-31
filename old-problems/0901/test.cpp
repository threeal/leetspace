// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

TEST_CASE("901. Online Stock Span") {
  SECTION("Example 1") {
    StockSpanner stockSpanner{};
    REQUIRE(stockSpanner.next(100) == 1);
    REQUIRE(stockSpanner.next(80) == 1);
    REQUIRE(stockSpanner.next(60) == 1);
    REQUIRE(stockSpanner.next(70) == 2);
    REQUIRE(stockSpanner.next(60) == 1);
    REQUIRE(stockSpanner.next(75) == 4);
    REQUIRE(stockSpanner.next(85) == 6);
  }
}
