// clang-format off
#include "solution.cpp"
// clang-format on

#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("355. Design Twitter") {
  SECTION("Example 1") {
    Twitter twitter;
    twitter.postTweet(1, 5);
    REQUIRE(twitter.getNewsFeed(1) == std::vector<int>{5});
    twitter.follow(1, 2);
    twitter.postTweet(2, 6);
    REQUIRE(twitter.getNewsFeed(1) == std::vector<int>{6, 5});
    twitter.unfollow(1, 2);
    REQUIRE(twitter.getNewsFeed(1) == std::vector<int>{5});
  }
}
