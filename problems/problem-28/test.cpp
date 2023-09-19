#include <string>

using namespace std;

#include <catch2/catch_test_macros.hpp>

#include "solution.cpp"

TEST_CASE("28. Find the Index of the First Occurrence in a String") {
  Solution solution;

  SECTION("Testcase 1") {
    INFO("haystack: sadbutsad");
    INFO("needle: sad");
    CHECK(solution.strStr("sadbutsad", "sad") == 0);
  }

  SECTION("Testcase 2") {
    INFO("haystack: leetcode");
    INFO("needle: leeto");
    CHECK(solution.strStr("leetcode", "leeto") == -1);
  }
}
