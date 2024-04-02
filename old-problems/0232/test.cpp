#include <catch2/catch_test_macros.hpp>

#include "solution.cpp"

TEST_CASE("232. Implement Queue using Stacks") {
  SECTION("Example 1") {
    MyQueue queue;
    queue.push(1);
    queue.push(2);
    REQUIRE(queue.peek() == 1);
    REQUIRE(queue.pop() == 1);
    REQUIRE_FALSE(queue.empty());
  }
}
