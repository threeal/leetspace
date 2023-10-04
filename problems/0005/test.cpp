#include <yaml-cpp/yaml.h>

#include <catch2/catch_test_macros.hpp>
#include <internal.hpp>
#include <string>

TEST_CASE("5. Longest Palindromic Substring") {
  const auto test_cases = YAML::LoadFile("test_cases.yaml");
  for (const auto& test_case : test_cases) {
    const auto name = test_case["name"].as<std::string>();
    const auto input = test_case["input"].as<std::string>();
    const auto expected = test_case["expected"].as<std::string>();

    CAPTURE(name);

    CHECK(solution_c<std::string>(input) == expected);
    CHECK(solution_cpp<std::string>(input) == expected);
  }
}
