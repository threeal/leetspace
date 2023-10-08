#include <catch2/catch_test_macros.hpp>
#include <interface.hpp>
#include <string>
#include <test_cases.hpp>

TEST_CASE("343. Integer Break") {
  for (const auto& test_case : test_cases) {
    const auto name = test_case["name"].as<std::string>();
    const auto n = test_case["n"].as<int>();
    const auto expected = test_case["expected"].as<int>();

    CAPTURE(name, n);
    CHECK(solution_cpp<int>(n) == expected);
  }
}
