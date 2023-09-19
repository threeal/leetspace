#include <vector>

using namespace std;

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>

#include "solution.cpp"

TEST_CASE("1. Two Sum") {
  Solution solution;

  SECTION("Testcase 1") {
    vector<int> vec = {2, 7, 11, 15};
    CHECK_THAT(solution.twoSum(vec, 9), Catch::Matchers::Equals<int>({0, 1}));
  }

  SECTION("Testcase 2") {
    vector<int> vec = {3, 2, 4};
    CHECK_THAT(solution.twoSum(vec, 6), Catch::Matchers::Equals<int>({1, 2}));
  }

  SECTION("Testcase 3") {
    vector<int> vec = {3, 3};
    CHECK_THAT(solution.twoSum(vec, 6), Catch::Matchers::Equals<int>({0, 1}));
  }
}
