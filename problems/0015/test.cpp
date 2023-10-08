#include <yaml-cpp/yaml.h>

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include <interface.hpp>
#include <string>
#include <vector>

TEST_CASE("15. 3Sum") {
  const auto test_cases = YAML::LoadFile("test_cases.yaml");
  for (const auto& test_case : test_cases) {
    auto name = test_case["name"].as<std::string>();
    auto nums = test_case["nums"].as<std::vector<int>>();
    auto expected = test_case["expected"].as<std::vector<std::vector<int>>>();

    CAPTURE(name, nums);
    CHECK_THAT(solution_cpp<std::vector<std::vector<int>>>(nums), Catch::Matchers::UnorderedEquals(expected));
  }
}
