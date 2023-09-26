#include <yaml-cpp/yaml.h>

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include <string>
#include <vector>

std::vector<int> solution_cpp(std::vector<int>, int);

TEST_CASE("1. Two Sum") {
  const auto test_cases = YAML::LoadFile("test_cases_0001.yaml");
  for (const auto& test_case : test_cases) {
    INFO("Test case: " << test_case["name"].as<std::string>());
    const auto res = solution_cpp(
        test_case["nums"].as<std::vector<int>>(),
        test_case["target"].as<int>());
    CHECK_THAT(res, Catch::Matchers::Equals<int>(test_case["expected"].as<std::vector<int>>()));
  }
}
