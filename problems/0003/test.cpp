#include <yaml-cpp/yaml.h>

#include <catch2/catch_test_macros.hpp>
#include <internal.hpp>
#include <string>

TEST_CASE("3. Longest Substring Without Repeating Characters") {
  const auto test_cases = YAML::LoadFile("test_cases.yaml");
  for (const auto& test_case : test_cases) {
    const auto name = test_case["name"].as<std::string>();
    const auto s = test_case["s"].as<std::string>();
    const auto expected = test_case["expected"].as<int>();

    CAPTURE(name);
    CAPTURE(s);

    CHECK(solution_cpp<int>(s) == expected);
  }
}
