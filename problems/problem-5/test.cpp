#include <string>

using namespace std;

#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include "solution.cpp"

struct TestCase {
  string title;
  string input;
  string expected;
};

TEST_CASE("5. Longest Palindromic Substring") {
  Solution solution;

  auto [title, input, expected] = GENERATE(
      TestCase{.title = "Example 1", .input = "babad", .expected = "bab"},
      TestCase{.title = "Example 2", .input = "cbbd", .expected = "bb"});

  INFO(title);
  CHECK(solution.longestPalindrome(input) == expected);
}
