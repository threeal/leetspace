#include <yaml-cpp/yaml.h>

#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <string>

int solution_c(int num1, int num2);
int solution_cpp(int num1, int num2);

TEST_CASE("2235. Add Two Integers") {
  const auto solution = GENERATE(solution_c, solution_cpp);

  const auto test_cases = YAML::LoadFile("test_cases.yaml");
  for (const auto& test_case : test_cases) {
    const auto name = test_case["name"].as<std::string>();
    const auto num1 = test_case["num1"].as<int>();
    const auto num2 = test_case["num2"].as<int>();
    const auto expected = test_case["expected"].as<int>();

    CAPTURE(name);
    CHECK(solution(num1, num2) == expected);
  }
}
