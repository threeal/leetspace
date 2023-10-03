#include <yaml-cpp/yaml.h>

#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <string>

int solution_cpp(const std::string& s);

TEST_CASE("58. Length of Last Word") {
  const auto test_cases = YAML::LoadFile("test_cases.yaml");
  for (const auto& test_case : test_cases) {
    const auto name = test_case["name"].as<std::string>();
    const auto s = test_case["s"].as<std::string>();
    const auto expected = test_case["expected"].as<int>();

    CAPTURE(name);
    CHECK(solution_cpp(s) == expected);
  }
}
