#include <yaml-cpp/yaml.h>

#include <catch2/catch_test_macros.hpp>
#include <string>

int solution(int n) {
  return n;
}

TEST_CASE("343. Integer Break") {
  const auto test_cases = YAML::LoadFile("test_cases.yaml");
  for (const auto& test_case : test_cases) {
    const auto name = test_case["name"].as<std::string>();
    const auto n = test_case["n"].as<int>();
    const auto expected = test_case["expected"].as<int>();

    CAPTURE(name, n);
    CHECK(solution(n) == expected);
  }
}
