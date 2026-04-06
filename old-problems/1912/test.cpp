// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("1912. Design Movie Rental System") {
  SECTION("Example 1") {
    std::vector<std::vector<int>> entries{
        {0, 1, 5}, {0, 2, 6}, {0, 3, 7}, {1, 1, 4}, {1, 2, 7}, {2, 1, 5}};

    MovieRentingSystem movieRentingSystem(3, entries);

    std::vector<int> expectedEntry{1, 0, 2};
    REQUIRE(movieRentingSystem.search(1) == expectedEntry);

    movieRentingSystem.rent(0, 1);
    movieRentingSystem.rent(1, 2);

    std::vector<std::vector<int>> expectedReport{{0, 1}, {1, 2}};
    REQUIRE(movieRentingSystem.report() == expectedReport);
    movieRentingSystem.drop(1, 2);

    expectedEntry = {0, 1};
    REQUIRE(movieRentingSystem.search(2) == expectedEntry);
  }
}
