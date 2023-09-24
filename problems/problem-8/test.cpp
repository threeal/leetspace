#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <string>

int solution_cpp(std::string s);

struct TestCase {
  std::string title;
  std::string s;
  int expected;
};

TEST_CASE("8. String to Integer (atoi)") {
  auto [title, s, expected] = GENERATE(
      TestCase{.title = "Example 1", .s = "42", .expected = 42},
      TestCase{.title = "Example 2", .s = "   -42", .expected = -42},
      TestCase{.title = "Example 3", .s = "4193 with words", .expected = 4193},
      TestCase{.title = "Starts with word", .s = "words and 987", .expected = 0});

  INFO(title);
  CHECK(solution_cpp(s) == expected);
}
