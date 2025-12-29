#include <algorithm>
#include <vector>

class Solution {
 public:
  int minProcessingTime(
      std::vector<int>& processorTime, std::vector<int>& tasks) {
    std::sort(processorTime.begin(), processorTime.end());
    std::sort(tasks.begin(), tasks.end(), std::greater<int>());

    int maxTime{0};
    for (std::size_t i{0}; i < processorTime.size(); ++i) {
      for (std::size_t j{0}; j < 4; ++j) {
        const int time{processorTime[i] + tasks[i * 4 + j]};
        if (time > maxTime) maxTime = time;
      }
    }

    return maxTime;
  }
};
