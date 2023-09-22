#include <string>

using namespace std;

#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include "solution.cpp"

struct TestCase {
  string title;
  string haystack;
  string needle;
  int expected;
};

TEST_CASE("28. Find the Index of the First Occurrence in a String") {
  Solution solution;

  auto [title, haystack, needle, expected] = GENERATE(
      TestCase{.title = "Example 1", .haystack = "sadbutsad", .needle = "sad", .expected = 0},
      TestCase{.title = "Example 2", .haystack = "leetcode", .needle = "leeto", .expected = -1});

  INFO(title);
  CHECK(solution.strStr(haystack, needle) == expected);
}
