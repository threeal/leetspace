#include <catch2/catch_test_macros.hpp>
#include <interface.hpp>
#include <string>
#include <test_cases.hpp>
#include <vector>

TEST_CASE("11. Container With Most Water") {
  for (const auto& test_case : test_cases) {
    auto name = test_case["name"].as<std::string>();
    auto height = test_case["height"].as<std::vector<int>>();
    auto expected = test_case["expected"].as<int>();

    CAPTURE(name);
    CHECK(solution_cpp<int>(height) == expected);
  }
}
