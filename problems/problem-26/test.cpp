#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include <vector>

std::vector<int> solution_cpp(std::vector<int> nums);

struct TestCase {
  std::string title;
  std::vector<int> nums;
  std::vector<int> expected;
};

TEST_CASE("26. Remove Duplicates from Sorted Array") {
  auto [title, nums, expected] = GENERATE(
      TestCase{
          .title = "Example 1",
          .nums = {1, 1, 2},
          .expected = {1, 2}},
      TestCase{
          .title = "Example 2",
          .nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4},
          .expected = {0, 1, 2, 3, 4}});

  CHECK_THAT(solution_cpp(nums), Catch::Matchers::Equals<int>(expected));
}
