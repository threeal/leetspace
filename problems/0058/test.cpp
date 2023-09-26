#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <string>

int solution_cpp(const std::string& s);

struct TestCase {
  std::string title;
  std::string s;
  int expected;
};

TEST_CASE("58. Length of Last Word") {
  auto [title, s, expected] = GENERATE(
      TestCase{.title = "Example 1", .s = "Hello World", .expected = 5},
      TestCase{.title = "Example 2", .s = "   fly me   to   the moon  ", .expected = 4},
      TestCase{.title = "Example 3", .s = "luffy is still joyboy", .expected = 6});

  INFO(title);
  CHECK(solution_cpp(s) == expected);
}
