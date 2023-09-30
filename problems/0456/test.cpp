#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <string>
#include <vector>

bool solution_cpp(const std::vector<int>& nums);

struct TestCase {
  std::string name;
  std::vector<int> nums;
  bool expected;
};

TEST_CASE("456. 132 Pattern") {
  const auto solution = GENERATE(solution_cpp);
  const auto [name, nums, expected] = GENERATE(
      TestCase{.name = "Example 1", .nums = {1, 2, 3, 4}, .expected = false},
      TestCase{.name = "Example 2", .nums = {3, 1, 4, 2}, .expected = true},
      TestCase{.name = "Example 3", .nums = {-1, 3, 2, 0}, .expected = true});
  CAPTURE(name, nums);
  CHECK(solution(nums) == expected);
}
