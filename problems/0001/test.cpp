#include <yaml-cpp/yaml.h>

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include <string>
#include <vector>

std::vector<int> solution_cpp(std::vector<int>&, int);

TEST_CASE("1. Two Sum") {
  const auto test_cases = YAML::LoadFile("test_cases.yaml");
  for (const auto& test_case : test_cases) {
    auto name = test_case["name"].as<std::string>();
    auto nums = test_case["nums"].as<std::vector<int>>();
    auto target = test_case["target"].as<int>();
    auto expected = test_case["expected"].as<std::vector<int>>();

    INFO(name);
    CHECK_THAT(solution_cpp(nums, target), Catch::Matchers::Equals<int>(expected));
  }
}
