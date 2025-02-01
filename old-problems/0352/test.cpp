// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

TEST_CASE("352. Data Stream as Disjoint Intervals") {
  SECTION("Example 1") {
    SummaryRanges obj{};

    obj.addNum(1);
    REQUIRE(obj.getIntervals() == std::vector<std::vector<int>>{{1, 1}});
    obj.addNum(3);
    REQUIRE(obj.getIntervals() == std::vector<std::vector<int>>{{1, 1}, {3, 3}});
    obj.addNum(7);
    REQUIRE(obj.getIntervals() == std::vector<std::vector<int>>{{1, 1}, {3, 3}, {7, 7}});
    obj.addNum(2);
    REQUIRE(obj.getIntervals() == std::vector<std::vector<int>>{{1, 3}, {7, 7}});
    obj.addNum(6);
    REQUIRE(obj.getIntervals() == std::vector<std::vector<int>>{{1, 3}, {6, 7}});
  }
}
