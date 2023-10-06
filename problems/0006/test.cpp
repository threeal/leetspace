#include <yaml-cpp/yaml.h>

#include <catch2/catch_test_macros.hpp>
#include <interface.hpp>
#include <string>

TEST_CASE("6. Zigzag Conversion") {
  const auto test_cases = YAML::LoadFile("test_cases.yaml");
  for (const auto& test_case : test_cases) {
    const auto name = test_case["name"].as<std::string>();
    const auto s = test_case["s"].as<std::string>();
    const auto numRows = test_case["numRows"].as<int>();
    const auto expected = test_case["expected"].as<std::string>();

    INFO("name: " << name);
    INFO("s: " << s);
    INFO("numRows: " << numRows);

    CHECK(solution_c<std::string>(s, numRows) == expected);
    CHECK(solution_cpp<std::string>(s, numRows) == expected);
  }
}
