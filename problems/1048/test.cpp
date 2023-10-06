#include <catch2/catch_test_macros.hpp>
#include <interface.hpp>
#include <string>
#include <test_cases.hpp>
#include <vector>

TEST_CASE("1048. Longest String Chain") {
  for (const auto& test_case : test_cases) {
    auto name = test_case["name"].as<std::string>();
    auto words = test_case["words"].as<std::vector<std::string>>();
    auto expected = test_case["expected"].as<int>();

    CAPTURE(name);
    CHECK(solution_cpp<int>(words) == expected);
  }
}
