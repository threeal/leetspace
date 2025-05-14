// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

TEST_CASE("1656. Design an Ordered Stream") {
  SECTION("Example 1") {
    OrderedStream os(5);
    REQUIRE(os.insert(3, "ccccc") == std::vector<std::string>{});
    REQUIRE(os.insert(1, "aaaaa") == std::vector<std::string>{"aaaaa"});
    REQUIRE(os.insert(2, "bbbbb") == std::vector<std::string>{"bbbbb", "ccccc"});
    REQUIRE(os.insert(5, "eeeee") == std::vector<std::string>{});
    REQUIRE(os.insert(4, "ddddd") == std::vector<std::string>{"ddddd", "eeeee"});
  }
}
