bool isBadVersion(int version);

// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

int badVersion{};
bool isBadVersion(int version) {
  return version >= badVersion;
}

TEST_CASE("278. First Bad Version") {
  SECTION("Example 1") {
    badVersion = 4;
    REQUIRE(badVersion == Solution{}.firstBadVersion(5));
  }

  SECTION("Example 2") {
    badVersion = 1;
    REQUIRE(badVersion == Solution{}.firstBadVersion(1));
  }
}
