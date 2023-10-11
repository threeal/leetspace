#include <catch2/catch_test_macros.hpp>
#include <interface.hpp>
#include <string>
#include <test_cases.hpp>
#include <vector>

std::vector<int> solution(const std::vector<std::vector<int>>&, const std::vector<int>&) {
  return {};
}

TEST_CASE("2251. Number of Flowers in Full Bloom") {
  for (const auto& test_case : test_cases) {
    const auto name = test_case["name"].as<std::string>();
    const auto flowers = test_case["flowers"].as<std::vector<std::vector<int>>>();
    const auto people = test_case["people"].as<std::vector<int>>();
    const auto expected = test_case["expected"].as<std::vector<int>>();

    CAPTURE(name, flowers, people);
    CHECK(solution(flowers, people) == expected);
  }
}
