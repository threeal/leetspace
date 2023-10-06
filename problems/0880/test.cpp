#include <catch2/catch_test_macros.hpp>
#include <interface.hpp>
#include <string>
#include <test_cases.hpp>

TEST_CASE("880. Decoded String at Index") {
  for (const auto& test_case : test_cases) {
    const auto name = test_case["name"].as<std::string>();
    const auto s = test_case["s"].as<std::string>();
    const auto k = test_case["k"].as<int>();
    const auto expected = test_case["expected"].as<std::string>();

    INFO("name: " << name);
    INFO("s: " << s);
    INFO("k: " << k);

    CHECK(solution_c<std::string>(s, k) == expected);
    CHECK(solution_cpp<std::string>(s, k) == expected);
  }
}
