// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>

TEST_CASE("895. Maximum Frequency Stack") {
  SECTION("Example 1") {
    FreqStack freqStack{};
    freqStack.push(5);
    freqStack.push(7);
    freqStack.push(5);
    freqStack.push(7);
    freqStack.push(4);
    freqStack.push(5);
    REQUIRE(freqStack.pop() == 5);
    REQUIRE(freqStack.pop() == 7);
    REQUIRE(freqStack.pop() == 5);
    REQUIRE(freqStack.pop() == 4);
  }
}
