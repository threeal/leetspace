#include <yaml-cpp/yaml.h>

#include <catch2/catch_test_macros.hpp>
#include <internal.hpp>
#include <string>
#include <vector>

TEST_CASE("4. Median of Two Sorted Arrays") {
  auto test_cases = YAML::LoadFile("test_cases.yaml");
  for (const auto& test_case : test_cases) {
    const auto name = test_case["name"].as<std::string>();
    const auto nums1 = test_case["nums1"].as<std::vector<int>>();
    const auto nums2 = test_case["nums2"].as<std::vector<int>>();
    const auto expected = test_case["expected"].as<double>();

    CAPTURE(name);
    CHECK(solution_cpp<double>(nums1, nums2) == expected);
  }
}
