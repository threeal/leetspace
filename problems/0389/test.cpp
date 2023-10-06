#include <catch2/catch_test_macros.hpp>
#include <interface.hpp>
#include <string>
#include <test_cases.hpp>

TEST_CASE("389. Find the Difference") {
  for (const auto& test_case : test_cases) {
    const auto name = test_case["name"].as<std::string>();
    const auto s = test_case["s"].as<std::string>();
    const auto t = test_case["t"].as<std::string>();
    const auto expected = test_case["expected"].as<char>();

    CAPTURE(name);
    CHECK(solution_cpp<char>(s, t) == expected);
  }
}
