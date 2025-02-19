// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

TEST_CASE("1352. Product of the Last K Numbers") {
  SECTION("Example 1") {
    ProductOfNumbers productOfNumbers;
    productOfNumbers.add(3);
    productOfNumbers.add(0);
    productOfNumbers.add(2);
    productOfNumbers.add(5);
    productOfNumbers.add(4);
    REQUIRE(productOfNumbers.getProduct(2) == 20);
    REQUIRE(productOfNumbers.getProduct(3) == 40);
    REQUIRE(productOfNumbers.getProduct(4) == 0);
    productOfNumbers.add(8);
    REQUIRE(productOfNumbers.getProduct(2) == 32);
  }
}
