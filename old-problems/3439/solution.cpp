#include <vector>

class Solution {
 public:
  int maxFreeTime(
      int eventTime, int k, std::vector<int>& startTime,
      std::vector<int>& endTime) {
    const int n = startTime.size();

    int eventsDuration{0};
    for (int i{0}; i < k; ++i) {
      eventsDuration += endTime[i] - startTime[i];
    }

    if (k == n) return eventTime - eventsDuration;

    int maxFreeDuration{startTime[k] - eventsDuration};
    eventsDuration += (endTime[k] - startTime[k]) - (endTime[0] - startTime[0]);

    for (int i{k + 1}; i < n; ++i) {
      const int freeDuration{
          startTime[i] - endTime[i - k - 1] - eventsDuration};

      if (freeDuration > maxFreeDuration) maxFreeDuration = freeDuration;

      eventsDuration += (endTime[i] - startTime[i]) -
          (endTime[i - k] - startTime[i - k]);
    }

    const int freeDuration{eventTime - endTime[n - k - 1] - eventsDuration};
    if (freeDuration > maxFreeDuration) maxFreeDuration = freeDuration;

    return maxFreeDuration;
  }
};
