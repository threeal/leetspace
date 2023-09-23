#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <string>

int solution_cpp(std::string, std::string);

struct TestCase {
  std::string title;
  std::string haystack;
  std::string needle;
  int expected;
};

TEST_CASE("28. Find the Index of the First Occurrence in a String") {
  auto [title, haystack, needle, expected] = GENERATE(
      TestCase{.title = "Example 1", .haystack = "sadbutsad", .needle = "sad", .expected = 0},
      TestCase{.title = "Example 2", .haystack = "leetcode", .needle = "leeto", .expected = -1});

  INFO(title);
  CHECK(solution_cpp(haystack, needle) == expected);
}
