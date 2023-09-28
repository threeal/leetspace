#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include <string>
#include <vector>

std::vector<int> solution_cpp(const std::vector<int>& nums);

struct TestCase {
  std::string name;
  std::vector<int> nums;
  std::vector<int> expected;
};

TEST_CASE("905. Sort Array By Parity") {
  const auto solution = GENERATE(solution_cpp);
  const auto [name, nums, expected] = GENERATE(
      TestCase{.name = "Example 1", .nums = {3, 1, 2, 4}, .expected = {2, 4, 3, 1}},
      TestCase{.name = "Example 2", .nums = {0}, .expected = {0}});

  CAPTURE(name);
  CAPTURE(nums);

  CHECK_THAT(solution(nums), Catch::Matchers::Equals<int>(expected));
}
