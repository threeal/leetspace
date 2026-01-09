// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

TEST_CASE("225. Implement Stack using Queues") {
  SECTION("Example 1") {
    MyStack myStack{};
    myStack.push(1);
    myStack.push(2);
    REQUIRE(myStack.top() == 2);
    REQUIRE(myStack.pop() == 2);
    REQUIRE_FALSE(myStack.empty());
  }
}
