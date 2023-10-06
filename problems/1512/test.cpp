#include <yaml-cpp/yaml.h>

#include <catch2/catch_test_macros.hpp>
#include <interface.hpp>
#include <string>
#include <vector>

TEST_CASE("1512. Number of Good Pairs") {
  const auto test_cases = YAML::LoadFile("test_cases.yaml");
  for (const auto& test_case : test_cases) {
    const auto name = test_case["name"].as<std::string>();
    const auto nums = test_case["nums"].as<std::vector<int>>();
    const auto expected = test_case["expected"].as<int>();

    CAPTURE(name, nums);

    CHECK(solution_c<int>(nums) == expected);
    CHECK(solution_cpp<int>(nums) == expected);
  }
}
