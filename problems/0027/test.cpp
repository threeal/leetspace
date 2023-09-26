#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include <vector>

std::vector<int> solution_cpp(std::vector<int> nums, int val);

struct TestCase {
  std::string title;
  std::vector<int> nums;
  int val;
  std::vector<int> expected;
};

TEST_CASE("27. Remove Element") {
  auto [title, nums, val, expected] = GENERATE(
      TestCase{
          .title = "Example 1",
          .nums = {3, 2, 2, 3},
          .val = 3,
          .expected = {2, 2}},
      TestCase{
          .title = "Example 2",
          .nums = {0, 1, 2, 2, 3, 0, 4, 2},
          .val = 2,
          .expected = {0, 1, 3, 0, 4}});

  INFO(title);
  CHECK_THAT(solution_cpp(nums, val), Catch::Matchers::Equals<int>(expected));
}
