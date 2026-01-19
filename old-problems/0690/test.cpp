#include <vector>

class Employee {
 public:
  int id;
  int importance;
  std::vector<int> subordinates;
};

// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

TEST_CASE("690. Employee Importance") {
  SECTION("Example 1") {
    std::vector<Employee*> employees{
        new Employee{.id = 1, .importance = 5, .subordinates = {2, 3}},
        new Employee{.id = 2, .importance = 3, .subordinates = {}},
        new Employee{.id = 3, .importance = 3, .subordinates = {}}};

    REQUIRE(Solution{}.getImportance(employees, 1) == 11);
  }

  SECTION("Example 2") {
    std::vector<Employee*> employees{
        new Employee{.id = 1, .importance = 2, .subordinates = {5}},
        new Employee{.id = 5, .importance = -3, .subordinates = {}}};

    REQUIRE(Solution{}.getImportance(employees, 5) == -3);
  }
}
