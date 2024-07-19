// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("1357. Apply Discount Every n Orders") {
  SECTION("Example 1") {
    std::vector<int> products{1, 2, 3, 4, 5, 6, 7};
    std::vector<int> prices{100, 200, 300, 400, 300, 200, 100};
    Cashier cashier(3, 50, products, prices);

    REQUIRE(cashier.getBill({1, 2}, {1, 2}) == 500.0);
    REQUIRE(cashier.getBill({3, 7}, {10, 10}) == 4000.0);
    REQUIRE(cashier.getBill({1, 2, 3, 4, 5, 6, 7}, {1, 1, 1, 1, 1, 1, 1}) == 800.0);
    REQUIRE(cashier.getBill({4}, {10}) == 4000.0);
    REQUIRE(cashier.getBill({7, 3}, {10, 10}) == 4000.0);
    REQUIRE(cashier.getBill({7, 5, 3, 1, 6, 4, 2}, {10, 10, 10, 9, 9, 9, 7}) == 7350.0);
    REQUIRE(cashier.getBill({2, 3, 5}, {5, 3, 2}) == 2500.0);
  }
}
