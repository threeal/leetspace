#include <vector>

class Solution {
 public:
  int findPoisonedDuration(std::vector<int>& timeSeries, int duration) {
    int totalDuration{duration};
    for (std::size_t i{1}; i < timeSeries.size(); ++i) {
      totalDuration += std::min(duration, timeSeries[i] - timeSeries[i - 1]);
    }
    return totalDuration;
  }
};
