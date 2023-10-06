#include <catch2/catch_test_macros.hpp>
#include <interface.hpp>
#include <test_cases.hpp>
#include <vector>

TEST_CASE("26. Remove Duplicates from Sorted Array") {
  for (const auto& test_case : test_cases) {
    const auto name = test_case["name"].as<std::string>();
    const auto nums = test_case["nums"].as<std::vector<int>>();
    const auto expected = test_case["expected"].as<std::vector<int>>();

    CAPTURE(name);
    CHECK(solution_cpp<std::vector<int>>(nums) == expected);
  }
}
