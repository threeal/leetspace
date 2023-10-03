#include <yaml-cpp/yaml.h>

#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <string>

bool solution_c(const std::string& colors);
bool solution_cpp(const std::string& colors);

TEST_CASE("2038. Remove Colored Pieces if Both Neighbors are the Same Color") {
  const auto solution = GENERATE(solution_c, solution_cpp);

  const auto test_cases = YAML::LoadFile("test_cases.yaml");
  for (const auto& test_case : test_cases) {
    const auto name = test_case["name"].as<std::string>();
    const auto colors = test_case["colors"].as<std::string>();
    const auto expected = test_case["expected"].as<bool>();

    CAPTURE(name, colors);
    CHECK(solution(colors) == expected);
  }
}
