#include <catch2/catch_test_macros.hpp>
#include <interface.hpp>
#include <string>
#include <test_cases.hpp>
#include <vector>

TEST_CASE("1337. The K Weakest Rows in a Matrix") {
  for (const auto& test_case : test_cases) {
    auto name = test_case["name"].as<std::string>();
    auto mat = test_case["mat"].as<std::vector<std::vector<int>>>();
    auto k = test_case["k"].as<int>();
    auto expected = test_case["expected"].as<std::vector<int>>();

    CAPTURE(name);
    CHECK(solution_cpp<std::vector<int>>(mat, k) == expected);
  }
}
