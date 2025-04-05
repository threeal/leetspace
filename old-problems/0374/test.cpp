int guess(int n);

// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

static int pick{};

int guess(int n) {
  return n == pick ? 0 : (n > pick ? -1 : 1);
}

TEST_CASE("374. Guess Number Higher or Lower") {
  SECTION("Example 1") {
    pick = 6;
    REQUIRE(Solution{}.guessNumber(10) == pick);
  }

  SECTION("Example 2") {
    pick = 1;
    REQUIRE(Solution{}.guessNumber(1) == pick);
  }

  SECTION("Example 3") {
    pick = 1;
    REQUIRE(Solution{}.guessNumber(2) == pick);
  }
}
