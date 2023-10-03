#include <yaml-cpp/yaml.h>

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include <vector>

std::vector<int> solution_cpp(std::vector<int> nums, int val);

TEST_CASE("27. Remove Element") {
  const auto test_cases = YAML::LoadFile("test_cases.yaml");
  for (const auto& test_case : test_cases) {
    const auto name = test_case["name"].as<std::string>();
    const auto nums = test_case["nums"].as<std::vector<int>>();
    const auto val = test_case["val"].as<int>();
    const auto expected = test_case["expected"].as<std::vector<int>>();

    CAPTURE(name);
    CHECK_THAT(solution_cpp(nums, val), Catch::Matchers::Equals<int>(expected));
  }
}
