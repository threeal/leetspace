#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <string>

bool solution_cpp(int x);

struct TestCase {
  std::string title;
  int x;
  bool expected;
};

TEST_CASE("9. Palindrome Number") {
  auto [title, x, expected] = GENERATE(
      TestCase{.title = "Example 1", .x = 121, .expected = true},
      TestCase{.title = "Example 2", .x = -121, .expected = false},
      TestCase{.title = "Example 3", .x = 10, .expected = false});

  INFO(title);
  CHECK(solution_cpp(x) == expected);
}
