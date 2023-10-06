#include <yaml-cpp/yaml.h>

#include <catch2/catch_test_macros.hpp>
#include <interface.hpp>
#include <string>

TEST_CASE("316. Remove Duplicate Letters") {
  const auto test_cases = YAML::LoadFile("test_cases.yaml");
  for (const auto& test_case : test_cases) {
    const auto name = test_case["name"].as<std::string>();
    const auto s = test_case["s"].as<std::string>();
    const auto expected = test_case["expected"].as<std::string>();

    CAPTURE(name);
    CHECK(solution_cpp<std::string>(s) == expected);
  }
}
