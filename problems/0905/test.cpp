#include <yaml-cpp/yaml.h>

#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include <string>
#include <vector>

std::vector<int> solution_cpp(const std::vector<int>& nums);

TEST_CASE("905. Sort Array By Parity") {
  const auto solution = GENERATE(solution_cpp);

  const auto test_cases = YAML::LoadFile("test_cases.yaml");
  for (const auto& test_case : test_cases) {
    const auto name = test_case["name"].as<std::string>();
    const auto nums = test_case["nums"].as<std::vector<int>>();
    const auto expected = test_case["expected"].as<std::vector<int>>();

    CAPTURE(name, nums);
    CHECK_THAT(solution(nums), Catch::Matchers::Equals<int>(expected));
  }
}
