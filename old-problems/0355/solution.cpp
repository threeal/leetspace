#include <list>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Twitter {
 private:
  std::list<std::tuple<int, int>> tweets;
  std::unordered_map<int, std::unordered_set<int>> followings;

 public:
  Twitter() : tweets{}, followings{} {}

  void postTweet(int userId, int tweetId) {
    tweets.push_front({userId, tweetId});
  }

  std::vector<int> getNewsFeed(int userId) {
    std::vector<int> feeds;
    for (const auto& [tweetUserId, tweetId] : tweets) {
      if (userId == tweetUserId || followings[userId].contains(tweetUserId)) {
        feeds.push_back(tweetId);
        if (feeds.size() >= 10) break;
      }
    }
    return feeds;
  }

  void follow(int followerId, int followeeId) {
    followings[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    followings[followerId].erase(followeeId);
  }
};
