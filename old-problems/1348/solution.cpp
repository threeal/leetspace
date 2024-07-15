#include <string>
#include <vector>

class TweetCounts {
 public:
  TweetCounts() {}

  void recordTweet(std::string /*tweetName*/, int /*time*/) {}

  std::vector<int> getTweetCountsPerFrequency(
      std::string /*freq*/, std::string /*tweetName*/,
      int /*startTime*/, int /*endTime*/) {
    return {};
  }
};
