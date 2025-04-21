#include <catch2/catch_test_macros.hpp>

#include "solution.cpp"

TEST_CASE("295. Find Median from Data Stream") {
  SECTION("Example 1") {
    MedianFinder finder;
    finder.addNum(1);
    finder.addNum(2);
    REQUIRE(finder.findMedian() == 1.5);
    finder.addNum(3);
    REQUIRE(finder.findMedian() == 2.0);
  }
}
