#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <string>

int solution_cpp(std::string s);

struct TestCase {
  std::string title;
  std::string s;
  int expected;
};

TEST_CASE("387. First Unique Character in a String") {
  auto [title, s, expected] = GENERATE(
      TestCase{.title = "Example 1", .s = "leetcode", .expected = 0},
      TestCase{.title = "Example 2", .s = "loveleetcode", .expected = 2},
      TestCase{.title = "Example 3", .s = "aabb", .expected = -1});

  INFO(title);
  CHECK(solution_cpp(s) == expected);
}
