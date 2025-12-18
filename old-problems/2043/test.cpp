// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("2043. Simple Bank System") {
  SECTION("Example 1") {
    std::vector<long long> balance{10, 100, 20, 50, 30};
    Bank bank(balance);
    REQUIRE(bank.withdraw(3, 10));
    REQUIRE(bank.transfer(5, 1, 20));
    REQUIRE(bank.deposit(5, 20));
    REQUIRE_FALSE(bank.transfer(3, 4, 15));
    REQUIRE_FALSE(bank.withdraw(10, 50));
  }
}
