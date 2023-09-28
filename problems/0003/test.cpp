#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <string>

int solution_cpp(const std::string& s);

struct TestCase {
  std::string name;
  std::string s;
  int expected;
};

TEST_CASE("3. Longest Substring Without Repeating Characters") {
  const auto solution = GENERATE(solution_cpp);
  const auto [name, s, expected] = GENERATE(
      TestCase{.name = "Example 1", .s = "abcabcbbabcabcbb", .expected = 3},
      TestCase{.name = "Example 2", .s = "bbbbb", .expected = 1},
      TestCase{.name = "Example 3", .s = "pwwkew", .expected = 3});

  CAPTURE(name);
  CAPTURE(s);

  CHECK(solution(s) == expected);
}
