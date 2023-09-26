#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <string>

std::string solution_cpp(std::string s);

struct TestCase {
  std::string title;
  std::string s;
  std::string expected;
};

TEST_CASE("316. Remove Duplicate Letters") {
  auto [title, s, expected] = GENERATE(
      TestCase{.title = "Example 1", .s = "bcabc", .expected = "abc"},
      TestCase{.title = "Example 2", .s = "cbacdcbc", .expected = "acdb"});

  INFO(title);
  CHECK(solution_cpp(s) == expected);
}
