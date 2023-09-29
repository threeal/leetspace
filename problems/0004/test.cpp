#include <yaml-cpp/yaml.h>

#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

double solution_cpp(std::vector<int>&, std::vector<int>&);

TEST_CASE("4. Median of Two Sorted Arrays") {
  auto test_cases = YAML::LoadFile("test_cases.yaml");
  for (const auto& test_case : test_cases) {
    auto name = test_case["name"].as<std::string>();
    auto nums1 = test_case["nums1"].as<std::vector<int>>();
    auto nums2 = test_case["nums2"].as<std::vector<int>>();
    auto expected = test_case["expected"].as<double>();

    CAPTURE(name);
    CHECK(solution_cpp(nums1, nums2) == expected);
  }
}
