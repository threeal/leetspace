#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <string>
#include <vector>

int solution_c(const std::vector<int>& nums);
int solution_cpp(const std::vector<int>& nums);

struct TestCase {
  std::string name;
  std::vector<int> nums;
  int expected;
};

TEST_CASE("1512. Number of Good Pairs") {
  const auto solution = GENERATE(solution_c, solution_cpp);
  const auto [name, nums, expected] = GENERATE(
      TestCase{.name = "Example 1", .nums = {1, 2, 3, 1, 1, 3}, .expected = 4},
      TestCase{.name = "Example 2", .nums = {1, 1, 1, 1}, .expected = 6},
      TestCase{.name = "Example 3", .nums = {1, 2, 3}, .expected = 0});

  CAPTURE(name, nums);
  CHECK(solution(nums) == expected);
}
