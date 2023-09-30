#include <yaml-cpp/yaml.h>

#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

int solution_cpp(std::vector<int>&, int);

TEST_CASE("1658. Minimum Operations to Reduce X to Zero") {
  const auto test_cases = YAML::LoadFile("test_cases.yaml");
  for (const auto& test_case : test_cases) {
    auto name = test_case["name"].as<std::string>();
    auto nums = test_case["nums"].as<std::vector<int>>();
    auto x = test_case["x"].as<int>();
    auto expected = test_case["expected"].as<int>();

    CAPTURE(name);
    CHECK(solution_cpp(nums, x) == expected);
  }
}
