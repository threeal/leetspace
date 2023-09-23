#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <string>
#include <vector>

int solution_cpp(std::vector<int>&, int);

struct TestCase {
  std::string title;
  std::vector<int> nums;
  int x;
  int expected;
};

TEST_CASE("1658. Minimum Operations to Reduce X to Zero") {
  auto [title, nums, x, expected] = GENERATE(
      TestCase{.title = "Example 1", .nums = {1, 1, 4, 2, 3}, .x = 5, .expected = 2},
      TestCase{.title = "Example 2", .nums = {5, 6, 7, 8, 9}, .x = 4, .expected = -1},
      TestCase{.title = "Example 3", .nums = {3, 2, 20, 1, 1, 3}, .x = 10, .expected = 5});

  INFO(title);
  CHECK(solution_cpp(nums, x) == expected);
}
