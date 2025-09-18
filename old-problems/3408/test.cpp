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

  SECTION("Test Case 99") {
    std::vector<std::vector<int>> tasks{{10, 26, 25}};
    TaskManager taskManager(tasks);
    taskManager.rmv(26);
    REQUIRE(taskManager.execTop() == -1);
  }

  SECTION("Test Case 623") {
    std::vector<std::vector<int>> tasks{
        {10, 10, 50}, {9, 29, 17}, {1, 21, 3}, {7, 17, 6}};
    TaskManager taskManager(tasks);
    REQUIRE(taskManager.execTop() == 10);
    taskManager.rmv(29);
    taskManager.add(4, 10, 7);
    REQUIRE(taskManager.execTop() == 4);
    taskManager.edit(21, 15);
    taskManager.edit(21, 9);
    taskManager.add(9, 3, 34);
    REQUIRE(taskManager.execTop() == 9);
    REQUIRE(taskManager.execTop() == 1);
  }
}
