#include <catch2/catch_test_macros.hpp>
#include <interface.hpp>
#include <test_cases.hpp>
#include <vector>

TEST_CASE("34. Find First and Last Position of Element in Sorted Array") {
  for (const auto& test_case : test_cases) {
    auto name = test_case["name"].as<std::string>();
    auto nums = test_case["nums"].as<std::vector<int>>();
    auto target = test_case["target"].as<int>();
    auto expected = test_case["expected"].as<std::vector<int>>();

    CAPTURE(name, nums, target);
    CHECK(solution_cpp<std::vector<int>>(nums, target) == expected);
  }
}
