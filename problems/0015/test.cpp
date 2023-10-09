#include <catch2/catch_test_macros.hpp>
#include <interface.hpp>
#include <string>
#include <test_cases.hpp>
#include <vector>

TEST_CASE("15. 3Sum") {
  for (const auto& test_case : test_cases) {
    auto name = test_case["name"].as<std::string>();
    auto nums = test_case["nums"].as<std::vector<int>>();
    auto expected = test_case["expected"].as<std::vector<std::vector<int>>>();

    CAPTURE(name, nums);
    CHECK(solution_cpp<std::vector<std::vector<int>>>(nums) == expected);
  }
}
