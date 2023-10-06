#include <catch2/catch_test_macros.hpp>
#include <interface.hpp>
#include <string>
#include <test_cases.hpp>
#include <vector>

TEST_CASE("17. Letter Combinations of a Phone Number") {
  for (const auto& test_case : test_cases) {
    const auto name = test_case["name"].as<std::string>();
    const auto digits = test_case["digits"].as<std::string>();
    const auto expected = test_case["expected"].as<std::vector<std::string>>();

    CAPTURE(name);
    CHECK(solution_cpp<std::vector<std::string>>(digits) == expected);
  }
}
