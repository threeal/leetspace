#include <catch2/catch_test_macros.hpp>
#include <interface.hpp>
#include <string>
#include <test_cases.hpp>
#include <vector>

TEST_CASE("1658. Minimum Operations to Reduce X to Zero") {
  for (const auto& test_case : test_cases) {
    auto name = test_case["name"].as<std::string>();
    auto nums = test_case["nums"].as<std::vector<int>>();
    auto x = test_case["x"].as<int>();
    auto expected = test_case["expected"].as<int>();

    CAPTURE(name);
    CHECK(solution_cpp<int>(nums, x) == expected);
  }
}
