#include <catch2/catch_test_macros.hpp>

#include "solution.cpp"

TEST_CASE("380. Insert Delete GetRandom O(1)") {
  SECTION("Example 1") {
    RandomizedSet random;
    REQUIRE(random.insert(1));
    REQUIRE_FALSE(random.remove(2));
    REQUIRE(random.insert(2));

    const auto val = random.getRandom();
    REQUIRE((val == 1 || val == 2));

    REQUIRE(random.remove(1));
    REQUIRE_FALSE(random.insert(2));
    REQUIRE(random.getRandom() == 2);
  }
}
