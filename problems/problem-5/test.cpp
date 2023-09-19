#include <string>

using namespace std;

#include <catch2/catch_test_macros.hpp>

#include "solution.cpp"

TEST_CASE("5. Longest Palindromic Substring") {
  Solution solution;

  SECTION("Testcase 1") {
    INFO("babad");
    CHECK(solution.longestPalindrome("babad") == "bab");
  }

  SECTION("Testcase 2") {
    INFO("cbbd");
    CHECK(solution.longestPalindrome("cbbd") == "bb");
  }
}
