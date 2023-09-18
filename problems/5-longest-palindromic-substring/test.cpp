#include <string>

using namespace std;

#include <catch2/catch_test_macros.hpp>

#include "solution.cpp"

TEST_CASE("5. Longest Palindromic Substring") {
  Solution solution;

  SECTION("Testcase 1") { CHECK(solution.longestPalindrome("babad") == "bab"); }

  SECTION("Testcase 2") { CHECK(solution.longestPalindrome("cbbd") == "bb"); }
}
