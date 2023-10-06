#include <yaml-cpp/yaml.h>

#include <catch2/catch_test_macros.hpp>
#include <interface.hpp>
#include <string>
#include <vector>

TEST_CASE("1232. Check If It Is a Straight Line") {
  const auto test_cases = YAML::LoadFile("test_cases.yaml");
  for (const auto& test_case : test_cases) {
    auto name = test_case["name"].as<std::string>();
    auto coordinates = test_case["coordinates"].as<std::vector<std::vector<int>>>();
    auto expected = test_case["expected"].as<bool>();

    CAPTURE(name);
    CHECK(solution_cpp<bool>(coordinates) == expected);
  }
}
