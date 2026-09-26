// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("2069. Walking Robot Simulation II") {
  SECTION("Example 1") {
    Robot robot(6, 3);
    robot.step(2);
    robot.step(2);
    REQUIRE(robot.getPos() == std::vector<int>{4, 0});
    REQUIRE(robot.getDir() == "East");
    robot.step(2);
    robot.step(1);
    robot.step(4);
    REQUIRE(robot.getPos() == std::vector<int>{1, 2});
    REQUIRE(robot.getDir() == "West");
  }
}
