#include <yaml-cpp/yaml.h>

#include <catch2/catch_test_macros.hpp>
#include <interface.hpp>
#include <string>
#include <vector>

TEST_CASE("229. Majority Element II") {
  const auto test_cases = YAML::LoadFile("test_cases.yaml");
  for (const auto& test_case : test_cases) {
    const auto name = test_case["name"].as<std::string>();
    const auto nums = test_case["nums"].as<std::vector<int>>();
    const auto expected = test_case["expected"].as<std::vector<int>>();

    CAPTURE(name, nums);
    CHECK(solution_cpp<std::vector<int>>(nums) == expected);
  }
}
