class CustomFunction {
 private:
  int id;

 public:
  CustomFunction(int id) : id{id} {}

  int f(int x, int y) {
    switch (id) {
      case 1:
        return x + y;

      case 2:
        return x * y;

      default:
        throw "Unknown ID";
    }
  }
};

// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("1237. Find Positive Integer Solution for a Given Equation") {
  SECTION("Example 1") {
    CustomFunction f(1);
    std::vector<std::vector<int>> expected{{1, 4}, {2, 3}, {3, 2}, {4, 1}};
    REQUIRE(Solution{}.findSolution(f, 5) == expected);
  }

  SECTION("Example 2") {
    CustomFunction f(2);
    std::vector<std::vector<int>> expected{{1, 5}, {5, 1}};
    REQUIRE(Solution{}.findSolution(f, 5) == expected);
  }
}
