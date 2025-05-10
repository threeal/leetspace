// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("535. Encode and Decode TinyURL") {
  SECTION("Example 1") {
    const std::string url{"https://leetcode.com/problems/design-tinyurl"};
    Solution solution{};
    REQUIRE(solution.decode(solution.encode(url)) == url);
  }
}
