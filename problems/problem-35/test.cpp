#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <vector>

int solution_cpp(std::vector<int>& nums, int target);

struct TestCase {
  std::string title;
  std::vector<int> nums;
  int target;
  int expected;
};

TEST_CASE("35. Search Insert Position") {
  auto [title, nums, target, expected] = GENERATE(
      TestCase{.title = "Example 1", .nums = {1, 3, 5, 6}, .target = 5, .expected = 2},
      TestCase{.title = "Example 2", .nums = {1, 3, 5, 6}, .target = 2, .expected = 1},
      TestCase{.title = "Example 3", .nums = {1, 3, 5, 6}, .target = 7, .expected = 4});

  INFO(title);
  CHECK(solution_cpp(nums, target) == expected);
}
