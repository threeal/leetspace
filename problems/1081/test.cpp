#include <catch2/catch_test_macros.hpp>
#include <interface.hpp>
#include <string>
#include <test_cases.hpp>

TEST_CASE("1081. Smallest Subsequence of Distinct Characters") {
  for (const auto& test_case : test_cases) {
    const auto name = test_case["name"].as<std::string>();
    const auto s = test_case["s"].as<std::string>();
    const auto expected = test_case["expected"].as<std::string>();

    CAPTURE(name);
    CHECK(solution_cpp<std::string>(s) == expected);
  }
}
