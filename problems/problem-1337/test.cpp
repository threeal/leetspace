#include <map>
#include <set>
#include <vector>

using namespace std;

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>

#include "solution.cpp"

TEST_CASE("1337. The K Weakest Rows in a Matrix") {
  Solution solution;

  SECTION("Testcase 1") {
    vector<vector<int>> mat = {
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 1}};
    CHECK_THAT(solution.kWeakestRows(mat, 3), Catch::Matchers::Equals<int>({2, 0, 3}));
  }

  SECTION("Testcase 2") {
    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 1, 1},
        {1, 0, 0, 0},
        {1, 0, 0, 0}};
    CHECK_THAT(solution.kWeakestRows(mat, 2), Catch::Matchers::Equals<int>({0, 2}));
  }

  SECTION("Testcase 3") {
    vector<vector<int>> mat = {
        {1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1}};
    CHECK_THAT(solution.kWeakestRows(mat, 1), Catch::Matchers::Equals<int>({0}));
  }
}
