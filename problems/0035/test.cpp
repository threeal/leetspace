#include <catch2/catch_test_macros.hpp>
#include <interface.hpp>
#include <test_cases.hpp>
#include <vector>

TEST_CASE("35. Search Insert Position") {
  for (const auto& test_case : test_cases) {
    auto name = test_case["name"].as<std::string>();
    auto nums = test_case["nums"].as<std::vector<int>>();
    auto target = test_case["target"].as<int>();
    auto expected = test_case["expected"].as<int>();

    CAPTURE(name);
    CHECK(solution_cpp<int>(nums, target) == expected);
  }
}
