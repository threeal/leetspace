#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <string>
#include <vector>

int solution_cpp(std::vector<int>& height);

struct TestCase {
  std::string title;
  std::vector<int> height;
  int expected;
};

TEST_CASE("11. Container With Most Water") {
  auto [title, height, expected] = GENERATE(
      TestCase{.title = "Example 1", .height = {1, 8, 6, 2, 5, 4, 8, 3, 7}, .expected = 49},
      TestCase{.title = "Example 2", .height = {1, 1}, .expected = 1});

  INFO(title);
  CHECK(solution_cpp(height) == expected);
}
