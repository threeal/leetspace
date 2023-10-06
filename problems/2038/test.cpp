#include <yaml-cpp/yaml.h>

#include <catch2/catch_test_macros.hpp>
#include <interface.hpp>
#include <string>

TEST_CASE("2038. Remove Colored Pieces if Both Neighbors are the Same Color") {
  const auto test_cases = YAML::LoadFile("test_cases.yaml");
  for (const auto& test_case : test_cases) {
    const auto name = test_case["name"].as<std::string>();
    const auto colors = test_case["colors"].as<std::string>();
    const auto expected = test_case["expected"].as<bool>();

    CAPTURE(name, colors);
    CHECK(solution_c<bool>(colors) == expected);
    CHECK(solution_cpp<bool>(colors) == expected);
  }
}
