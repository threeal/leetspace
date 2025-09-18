// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("3408. Design Task Manager") {
  SECTION("Example 1") {
    std::vector<std::vector<int>> tasks{
        {1, 101, 10}, {2, 102, 20}, {3, 103, 15}};
    TaskManager taskManager(tasks);
    taskManager.add(4, 104, 5);
    taskManager.edit(102, 8);
    REQUIRE(taskManager.execTop() == 3);
    taskManager.rmv(101);
    taskManager.add(5, 105, 15);
    REQUIRE(taskManager.execTop() == 5);
  }
}
