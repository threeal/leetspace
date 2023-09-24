#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <string>

double solution_cpp(int poured, int query_row, int query_glass);

struct TestCase {
  std::string title;
  int poured;
  int query_row;
  int query_glass;
  double expected;
};

TEST_CASE("799. Champagne Tower") {
  auto [title, poured, query_row, query_glass, expected] = GENERATE(
      TestCase{.title = "Example 1", .poured = 1, .query_row = 1, .query_glass = 1, .expected = 0.0},
      TestCase{.title = "Example 2", .poured = 2, .query_row = 1, .query_glass = 1, .expected = 0.5},
      TestCase{.title = "Example 3", .poured = 100000009, .query_row = 33, .query_glass = 17, .expected = 1.0},
      TestCase{.title = "Failed test case 1", .poured = 25, .query_row = 6, .query_glass = 1, .expected = 0.18750});

  INFO(title);
  CHECK(solution_cpp(poured, query_row, query_glass) == expected);
}
