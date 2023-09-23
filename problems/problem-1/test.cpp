#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include <string>
#include <vector>

std::vector<int> solution_cpp(std::vector<int>&, int);

struct TestCase {
  std::string title;
  std::vector<int> nums;
  int target;
  std::vector<int> expected;
};

TEST_CASE("1. Two Sum") {
  auto [title, nums, target, expected] = GENERATE(
      TestCase{.title = "Example 1", .nums = {2, 7, 11, 15}, .target = 9, .expected = {0, 1}},
      TestCase{.title = "Example 2", .nums = {3, 2, 4}, .target = 6, .expected = {1, 2}},
      TestCase{.title = "Example 3", .nums = {3, 3}, .target = 6, .expected = {0, 1}});

  INFO(title);
  CHECK_THAT(solution_cpp(nums, target), Catch::Matchers::Equals<int>(expected));
}
