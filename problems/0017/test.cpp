#include <yaml-cpp/yaml.h>

#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <string>
#include <vector>

std::vector<std::string> solution_cpp(const std::string& digits);

TEST_CASE("17. Letter Combinations of a Phone Number") {
  const auto solution = GENERATE(solution_cpp);

  const auto test_cases = YAML::LoadFile("test_cases.yaml");
  for (const auto& test_case : test_cases) {
    const auto name = test_case["name"].as<std::string>();
    const auto digits = test_case["digits"].as<std::string>();
    const auto expected = test_case["expected"].as<std::vector<std::string>>();

    CAPTURE(name);
    CHECK(solution(digits) == expected);
  }
}
