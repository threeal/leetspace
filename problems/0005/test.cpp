#include <catch2/catch_test_macros.hpp>
#include <interface.hpp>
#include <string>
#include <test_cases.hpp>

TEST_CASE("5. Longest Palindromic Substring") {
  for (const auto& test_case : test_cases) {
    const auto name = test_case["name"].as<std::string>();
    const auto input = test_case["input"].as<std::string>();
    const auto expected = test_case["expected"].as<std::string>();

    CAPTURE(name);

    CHECK(solution_c<std::string>(input) == expected);
    CHECK(solution_cpp<std::string>(input) == expected);
  }
}
