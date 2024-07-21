#include "solution.cpp"

// clang-format off
#include <catch2/catch_test_macros.hpp>
// clang-format on

TEST_CASE("1348. Tweet Counts Per Frequency") {
  SECTION("Example 1") {
    TweetCounts tweetCounts;
    tweetCounts.recordTweet("tweet3", 0);
    tweetCounts.recordTweet("tweet3", 60);
    tweetCounts.recordTweet("tweet3", 10);

    auto count = tweetCounts.getTweetCountsPerFrequency(
        "minute", "tweet3", 0, 59);
    REQUIRE(count == std::vector<int>{2});

    count = tweetCounts.getTweetCountsPerFrequency(
        "minute", "tweet3", 0, 60);
    REQUIRE(count == std::vector<int>{2, 1});

    count = tweetCounts.getTweetCountsPerFrequency(
        "minute", "tweet3", 0, 60);
    REQUIRE(count == std::vector<int>{2, 1});

    tweetCounts.recordTweet("tweet3", 120);

    count = tweetCounts.getTweetCountsPerFrequency(
        "hour", "tweet3", 0, 210);
    REQUIRE(count == std::vector<int>{4});
  }
}
