// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("1286. Iterator for Combination") {
  SECTION("Example 1") {
    CombinationIterator itr("abc", 2);
    REQUIRE(itr.next() == "ab");
    REQUIRE(itr.hasNext());
    REQUIRE(itr.next() == "ac");
    REQUIRE(itr.hasNext());
    REQUIRE(itr.next() == "bc");
    REQUIRE_FALSE(itr.hasNext());
  }
}
