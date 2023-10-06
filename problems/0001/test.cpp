#include <yaml-cpp/yaml.h>

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include <interface.hpp>
#include <string>
#include <vector>

TEST_CASE("1. Two Sum") {
  const auto test_cases = YAML::LoadFile("test_cases.yaml");
  for (const auto& test_case : test_cases) {
    const auto name = test_case["name"].as<std::string>();
    const auto nums = test_case["nums"].as<std::vector<int>>();
    const auto target = test_case["target"].as<int>();
    const auto expected = test_case["expected"].as<std::vector<int>>();

    CAPTURE(name);

    CHECK_THAT(solution_c<std::vector<int>>(nums, target), Catch::Matchers::Equals<int>(expected));
    CHECK_THAT(solution_cpp<std::vector<int>>(nums, target), Catch::Matchers::Equals<int>(expected));
  }
}
