// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

TEST_CASE("1476. Subrectangle Queries") {
  SECTION("Example 1") {
    std::vector<std::vector<int>> rectangle{
        {1, 2, 1}, {4, 3, 4}, {3, 2, 1}, {1, 1, 1}};

    SubrectangleQueries queries(rectangle);

    REQUIRE(queries.getValue(0, 2) == 1);

    queries.updateSubrectangle(0, 0, 3, 2, 5);

    REQUIRE(queries.getValue(0, 2) == 5);
    REQUIRE(queries.getValue(3, 1) == 5);

    queries.updateSubrectangle(3, 0, 3, 2, 10);

    REQUIRE(queries.getValue(3, 1) == 10);
    REQUIRE(queries.getValue(0, 2) == 5);
  }

  SECTION("Example 2") {
    std::vector<std::vector<int>> rectangle{{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    SubrectangleQueries queries(rectangle);

    REQUIRE(queries.getValue(0, 0) == 1);

    queries.updateSubrectangle(0, 0, 2, 2, 100);

    REQUIRE(queries.getValue(0, 0) == 100);
    REQUIRE(queries.getValue(2, 2) == 100);

    queries.updateSubrectangle(1, 1, 2, 2, 20);

    REQUIRE(queries.getValue(2, 2) == 20);
  }
}
