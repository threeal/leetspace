#include <catch2/catch_test_macros.hpp>
#include <string>
#include <test_cases.hpp>
#include <vector>

int solution(const std::vector<int>& nums1, const std::vector<int>& nums2) {
  return nums1.size() + nums2.size();
}

TEST_CASE("1458. Max Dot Product of Two Subsequences") {
  for (const auto& test_case : test_cases) {
    auto name = test_case["name"].as<std::string>();
    auto nums1 = test_case["nums1"].as<std::vector<int>>();
    auto nums2 = test_case["nums2"].as<std::vector<int>>();
    auto expected = test_case["expected"].as<int>();

    CAPTURE(name);
    CHECK(solution(nums1, nums2) == expected);
  }
}
