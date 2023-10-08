#include <catch2/catch_test_macros.hpp>
#include <interface.hpp>
#include <string>
#include <test_cases.hpp>

TEST_CASE("2235. Add Two Integers") {
  for (const auto& test_case : test_cases) {
    const auto name = test_case["name"].as<std::string>();
    const auto num1 = test_case["num1"].as<int>();
    const auto num2 = test_case["num2"].as<int>();
    const auto expected = test_case["expected"].as<int>();

    CAPTURE(name);

    CHECK(solution_c<int>(num1, num2) == expected);
    CHECK(solution_cpp<int>(num1, num2) == expected);
  }
}
