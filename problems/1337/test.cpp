#include <yaml-cpp/yaml.h>

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include <string>
#include <vector>

std::vector<int> solution_cpp(std::vector<std::vector<int>>&, int);

TEST_CASE("1337. The K Weakest Rows in a Matrix") {
  const auto test_cases = YAML::LoadFile("test_cases.yaml");
  for (const auto& test_case : test_cases) {
    auto name = test_case["name"].as<std::string>();
    auto mat = test_case["mat"].as<std::vector<std::vector<int>>>();
    auto k = test_case["k"].as<int>();
    auto expected = test_case["expected"].as<std::vector<int>>();

    CAPTURE(name);
    CHECK_THAT(solution_cpp(mat, k), Catch::Matchers::Equals<int>(expected));
  }
}
