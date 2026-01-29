// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

TEST_CASE("705. Design HashSet") {
  SECTION("Example 1") {
    MyHashSet myHashSet{};
    myHashSet.add(1);
    myHashSet.add(2);
    REQUIRE(myHashSet.contains(1));
    REQUIRE_FALSE(myHashSet.contains(3));
    myHashSet.add(2);
    REQUIRE(myHashSet.contains(2));
    myHashSet.remove(2);
    REQUIRE_FALSE(myHashSet.contains(2));
  }
}
