#include <yaml-cpp/yaml.h>

#include <catch2/catch_test_macros.hpp>
#include <string>

char solution_cpp(std::string s, std::string t);

TEST_CASE("389. Find the Difference") {
  const auto test_cases = YAML::LoadFile("test_cases.yaml");
  for (const auto& test_case : test_cases) {
    const auto name = test_case["name"].as<std::string>();
    const auto s = test_case["s"].as<std::string>();
    const auto t = test_case["t"].as<std::string>();
    const auto expected = test_case["expected"].as<char>();

    CAPTURE(name);
    CHECK(solution_cpp(s, t) == expected);
  }
}
