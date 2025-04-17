#include "solution.cpp"

// clang-format off
#include <catch2/catch_test_macros.hpp>
#include <vector>
// clang-format on

TEST_CASE("911. Online Election") {
  SECTION("Example 1") {
    std::vector<int> persons{0, 1, 1, 0, 0, 1, 0};
    std::vector<int> times{0, 5, 10, 15, 20, 25, 30};
    TopVotedCandidate topVotedCandidate(persons, times);
    REQUIRE(topVotedCandidate.q(3) == 0);
    REQUIRE(topVotedCandidate.q(12) == 1);
    REQUIRE(topVotedCandidate.q(25) == 1);
    REQUIRE(topVotedCandidate.q(15) == 0);
    REQUIRE(topVotedCandidate.q(24) == 0);
    REQUIRE(topVotedCandidate.q(8) == 1);
  }

  SECTION("Test Case 9") {
    std::vector<int> persons{0, 0, 0, 0, 1};
    std::vector<int> times{0, 6, 39, 52, 75};
    TopVotedCandidate topVotedCandidate(persons, times);
    REQUIRE(topVotedCandidate.q(45) == 0);
    REQUIRE(topVotedCandidate.q(49) == 0);
    REQUIRE(topVotedCandidate.q(59) == 0);
    REQUIRE(topVotedCandidate.q(68) == 0);
    REQUIRE(topVotedCandidate.q(42) == 0);
    REQUIRE(topVotedCandidate.q(37) == 0);
    REQUIRE(topVotedCandidate.q(99) == 0);
    REQUIRE(topVotedCandidate.q(26) == 0);
    REQUIRE(topVotedCandidate.q(78) == 0);
    REQUIRE(topVotedCandidate.q(43) == 0);
  }
}
