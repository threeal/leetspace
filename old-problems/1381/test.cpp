// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

TEST_CASE("1381. Design a Stack With Increment Operation") {
  SECTION("Example 1") {
    CustomStack stack(3);
    stack.push(1);
    stack.push(2);
    REQUIRE(stack.pop() == 2);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.increment(5, 100);
    stack.increment(2, 100);
    REQUIRE(stack.pop() == 103);
    REQUIRE(stack.pop() == 202);
    REQUIRE(stack.pop() == 201);
    REQUIRE(stack.pop() == -1);
  }
}
