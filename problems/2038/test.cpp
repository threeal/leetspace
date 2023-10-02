#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <string>

bool solution_cpp(const std::string& colors);

struct TestCase {
  std::string name;
  std::string colors;
  bool expected;
};

TEST_CASE("2038. Remove Colored Pieces if Both Neighbors are the Same Color") {
  const auto solution = GENERATE(solution_cpp);
  const auto [name, colors, expected] = GENERATE(
      TestCase{.name = "Example 1", .colors = "AAABABB", .expected = true},
      TestCase{.name = "Example 2", .colors = "AA", .expected = false},
      TestCase{.name = "Example 3", .colors = "ABBBBBBBAAA", .expected = false});

  CAPTURE(name, colors);
  CHECK(solution(colors) == expected);
}
