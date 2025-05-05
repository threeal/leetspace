// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("1603. Design Parking System") {
  SECTION("Example 1") {
    ParkingSystem system(1, 1, 0);
    REQUIRE(system.addCar(1));
    REQUIRE(system.addCar(2));
    REQUIRE_FALSE(system.addCar(3));
    REQUIRE_FALSE(system.addCar(1));
  }
}
