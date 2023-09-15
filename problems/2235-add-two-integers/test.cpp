#include <catch2/catch_test_macros.hpp>
#include "solution.cpp"

TEST_CASE("2235. Add Two Integers") {
  Solution solution;

  CHECK(solution.sum(12, 5) == 17);
  CHECK(solution.sum(-10, 4) == -6);
}
