#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <string>
#include <vector>

bool solution_cpp(std::vector<std::vector<int>>& coordinates);

struct TestCase {
  std::string title;
  std::vector<std::vector<int>> coordinates;
  int expected;
};

TEST_CASE("1232. Check If It Is a Straight Line") {
  auto [title, coordinates, expected] = GENERATE(
      TestCase{
          .title = "Example 1",
          .coordinates = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}},
          .expected = true},
      TestCase{
          .title = "Example 2",
          .coordinates = {{1, 1}, {2, 2}, {3, 4}, {4, 5}, {5, 6}, {7, 7}},
          .expected = false});

  INFO(title);
  CHECK(solution_cpp(coordinates) == expected);
}
