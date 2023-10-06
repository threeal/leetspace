#include <catch2/catch_test_macros.hpp>
#include <interface.hpp>
#include <string>
#include <test_cases.hpp>

TEST_CASE("9. Palindrome Number") {
  for (const auto& test_case : test_cases) {
    const auto name = test_case["name"].as<std::string>();
    const auto x = test_case["x"].as<int>();
    const auto expected = test_case["expected"].as<bool>();

    CAPTURE(name);
    CHECK(solution_cpp<bool>(x) == expected);
  }
}
