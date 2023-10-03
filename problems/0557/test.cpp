#include <yaml-cpp/yaml.h>

#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <string>

std::string solution_c(const std::string& s);
std::string solution_cpp(const std::string& s);

TEST_CASE("557. Reverse Words in a String III") {
  const auto solution = GENERATE(solution_c, solution_cpp);

  const auto test_cases = YAML::LoadFile("test_cases.yaml");
  for (const auto& test_case : test_cases) {
    const auto name = test_case["name"].as<std::string>();
    const auto s = test_case["s"].as<std::string>();
    const auto expected = test_case["expected"].as<std::string>();

    CAPTURE(name, s);
    CHECK(solution(s) == expected);
  }
}
