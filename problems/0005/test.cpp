#include <yaml-cpp/yaml.h>

#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <string>

std::string solution_c(std::string);
std::string solution_cpp(std::string);

TEST_CASE("5. Longest Palindromic Substring") {
  const auto solution = GENERATE(solution_c, solution_cpp);
  auto test_cases = YAML::LoadFile("test_cases.yaml");
  for (const auto& test_case : test_cases) {
    auto name = test_case["name"].as<std::string>();
    auto input = test_case["input"].as<std::string>();
    auto expected = test_case["expected"].as<std::string>();

    CAPTURE(name);
    CHECK(solution(input) == expected);
  }
}
