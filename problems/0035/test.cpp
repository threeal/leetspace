#include <yaml-cpp/yaml.h>

#include <catch2/catch_test_macros.hpp>
#include <vector>

int solution_cpp(std::vector<int>& nums, int target);

TEST_CASE("35. Search Insert Position") {
  const auto test_cases = YAML::LoadFile("test_cases.yaml");
  for (const auto& test_case : test_cases) {
    auto name = test_case["name"].as<std::string>();
    auto nums = test_case["nums"].as<std::vector<int>>();
    auto target = test_case["target"].as<int>();
    auto expected = test_case["expected"].as<int>();

    CAPTURE(name);
    CHECK(solution_cpp(nums, target) == expected);
  }
}
