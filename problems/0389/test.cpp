#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <string>

char solution_cpp(std::string s, std::string t);

struct TestCase {
  std::string title;
  std::string s;
  std::string t;
  char expected;
};

TEST_CASE("389. Find the Difference") {
  auto [title, s, t, expected] = GENERATE(
      TestCase{.title = "Example 1", .s = "abcd", .t = "abcde", .expected = 'e'},
      TestCase{.title = "Example 2", .s = "", .t = "y", .expected = 'y'});

  INFO(title);
  CHECK(solution_cpp(s, t) == expected);
}
