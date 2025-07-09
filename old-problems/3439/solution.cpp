#include <queue>
#include <vector>

class Solution {
 public:
  int maxFreeTime(
      int eventTime, int k, std::vector<int>& startTime,
      std::vector<int>& endTime) {
    const std::size_t kk = k + 1;

    int sum{startTime.front()};
    int maxSum{sum};

    std::queue<int> freeTimes{};
    freeTimes.push(startTime.front());

    for (std::size_t i{1}; i < endTime.size(); ++i) {
      sum += startTime[i] - endTime[i - 1];
      freeTimes.push(startTime[i] - endTime[i - 1]);
      while (freeTimes.size() > kk) {
        sum -= freeTimes.front();
        freeTimes.pop();
      }

      if (sum > maxSum) maxSum = sum;
    }

    sum += eventTime - endTime.back();
    freeTimes.push(eventTime - endTime.back());
    while (freeTimes.size() > kk) {
      sum -= freeTimes.front();
      freeTimes.pop();
    }

    if (sum > maxSum) maxSum = sum;
    return maxSum;
  }
};
