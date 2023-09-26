#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <string>

bool solution_cpp(std::string s, std::string t);

struct TestCase {
  std::string title;
  std::string s;
  std::string t;
  bool expected;
};

TEST_CASE("392. Is Subsequence") {
  auto [title, s, t, expected] = GENERATE(
      TestCase{.title = "Example 1", .s = "abc", .t = "ahbgdc", .expected = true},
      TestCase{.title = "Example 2", .s = "axc", .t = "ahbgdc", .expected = false});

  INFO(title);
  CHECK(solution_cpp(s, t) == expected);
}
