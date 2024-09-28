// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

TEST_CASE("641. Design Circular Deque") {
  SECTION("Example 1") {
    MyCircularDeque deque(3);
    REQUIRE(deque.insertLast(1));
    REQUIRE(deque.insertLast(2));
    REQUIRE(deque.insertFront(3));
    REQUIRE_FALSE(deque.insertFront(4));
    REQUIRE(deque.getRear() == 2);
    REQUIRE(deque.isFull());
    REQUIRE(deque.deleteLast());
    REQUIRE(deque.insertFront(4));
    REQUIRE(deque.getFront() == 4);
  }
}
