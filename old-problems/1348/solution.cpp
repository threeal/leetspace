#include <string>
#include <unordered_map>
#include <vector>

class TweetCounts {
 private:
  std::unordered_map<std::string, std::vector<int>> tweetTimes;

 public:
  TweetCounts() : tweetTimes{} {}

  void recordTweet(std::string tweetName, int time) {
    auto tweetTimesIt = tweetTimes.find(tweetName);
    auto& times = tweetTimesIt == tweetTimes.end()
        ? tweetTimes.emplace(tweetName, std::vector<int>{}).first->second
        : tweetTimesIt->second;

    times.insert(
        std::lower_bound(times.begin(), times.end(), time), time);
  }

  std::vector<int> getTweetCountsPerFrequency(
      std::string freq, std::string tweetName,
      int startTime, int endTime) {
    const int interval = freq[0] == 'm'
        ? 60
        : (freq[0] == 'h' ? 3600 : 86400);

    const int duration = endTime - startTime + 1;
    const int chunkSize = duration / interval +
        (duration % interval == 0 ? 0 : 1);

    std::vector<int> chunks(chunkSize, 0);

    auto tweeTimesIt = tweetTimes.find(tweetName);
    if (tweeTimesIt == tweetTimes.end()) {
      return chunks;
    }

    auto& times = tweeTimesIt->second;
    auto timesIt = std::lower_bound(times.begin(), times.end(), startTime);
    if (timesIt == times.end()) return chunks;

    for (int i = 0; i < chunkSize; ++i) {
      startTime = std::min(startTime + interval, endTime + 1);
      while (timesIt != times.end() && *timesIt < startTime) {
        ++chunks[i];
        ++timesIt;
      }
    }

    return chunks;
  }
};
