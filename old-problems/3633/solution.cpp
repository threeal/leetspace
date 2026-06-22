#include <algorithm>
#include <limits>
#include <vector>

class Solution {
 public:
  int earliestFinishTime(
      std::vector<int>& landStartTime, std::vector<int>& landDuration,
      std::vector<int>& waterStartTime, std::vector<int>& waterDuration) {
    int minTime{std::numeric_limits<int>::max()};
    for (std::size_t i{0}; i < landStartTime.size(); ++i) {
      for (std::size_t j{0}; j < waterStartTime.size(); ++j) {
        const int time{
            std::min(
                std::max(
                    landStartTime[i] + landDuration[i],
                    waterStartTime[j]) +
                    waterDuration[j],
                std::max(
                    waterStartTime[j] + waterDuration[j],
                    landStartTime[i]) +
                    landDuration[i])};
        if (time < minTime) minTime = time;
      }
    }
    return minTime;
  }
};
