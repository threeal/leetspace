#include <yaml-cpp/yaml.h>

#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

int solution_cpp(std::vector<std::string>& words);

TEST_CASE("1048. Longest String Chain") {
  const auto test_cases = YAML::LoadFile("test_cases.yaml");
  for (const auto& test_case : test_cases) {
    auto name = test_case["name"].as<std::string>();
    auto words = test_case["words"].as<std::vector<std::string>>();
    auto expected = test_case["expected"].as<int>();

    CAPTURE(name);
    CHECK(solution_cpp(words) == expected);
  }
}
