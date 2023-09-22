#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <string>

int solution_cpp(int num1, int num2);

struct TestCase {
  std::string title;
  int num1;
  int num2;
  int expected;
};

TEST_CASE("2235. Add Two Integers") {
  auto [title, num1, num2, expected] = GENERATE(
      TestCase{.title = "Example 1", .num1 = 12, .num2 = 5, .expected = 17},
      TestCase{.title = "Example 2", .num1 = -10, .num2 = 4, .expected = -6});

  INFO(title);
  CHECK(solution_cpp(num1, num2) == expected);
}
