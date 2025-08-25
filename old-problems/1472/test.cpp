// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

TEST_CASE("1472. Design Browser History") {
  SECTION("Example 1") {
    BrowserHistory history("leetcode.com");
    history.visit("google.com");
    history.visit("facebook.com");
    history.visit("youtube.com");
    REQUIRE(history.back(1) == "facebook.com");
    REQUIRE(history.back(1) == "google.com");
    REQUIRE(history.forward(1) == "facebook.com");
    history.visit("linkedin.com");
    REQUIRE(history.forward(2) == "linkedin.com");
    REQUIRE(history.back(2) == "google.com");
    REQUIRE(history.back(7) == "leetcode.com");
  }
}
