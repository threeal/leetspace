// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("344. Reverse String") {
  SECTION("Example 1") {
    std::vector<char> s{'h', 'e', 'l', 'l', 'o'};
    Solution{}.reverseString(s);
    REQUIRE(std::vector<char>{'o', 'l', 'l', 'e', 'h'} == s);
  }

  SECTION("Example 2") {
    std::vector<char> s{'H', 'a', 'n', 'n', 'a', 'h'};
    Solution{}.reverseString(s);
    REQUIRE(std::vector<char>{'h', 'a', 'n', 'n', 'a', 'H'} == s);
  }
}
