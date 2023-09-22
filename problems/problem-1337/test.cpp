#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>

#include "solution.cpp"

struct TestCase {
  string title;
  vector<vector<int>> mat;
  int k;
  vector<int> expected;
};

TEST_CASE("1337. The K Weakest Rows in a Matrix") {
  Solution solution;

  auto [title, mat, k, expected] = GENERATE(
      TestCase{
          .title = "Example 1",
          .mat = {{1, 1, 0, 0, 0}, {1, 1, 1, 1, 0}, {1, 0, 0, 0, 0}, {1, 1, 0, 0, 0}, {1, 1, 1, 1, 1}},
          .k = 3,
          .expected = {2, 0, 3}},
      TestCase{
          .title = "Example 2",
          .mat = {{1, 0, 0, 0}, {1, 1, 1, 1}, {1, 0, 0, 0}, {1, 0, 0, 0}},
          .k = 2,
          .expected = {0, 2}},
      TestCase{
          .title = "Mat same values",
          .mat = {{1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}},
          .k = 1,
          .expected = {0}});

  INFO(title);
  CHECK_THAT(solution.kWeakestRows(mat, k), Catch::Matchers::Equals<int>(expected));
}
