#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
 public:
  int earliestFinishTime(
      std::vector<int>& landStartTime, std::vector<int>& landDuration,
      std::vector<int>& waterStartTime, std::vector<int>& waterDuration) {
    int minLandFinish{std::numeric_limits<int>::max()};
    for (std::size_t i{0}; i < landStartTime.size(); ++i) {
      if (landStartTime[i] + landDuration[i] < minLandFinish) {
        minLandFinish = landStartTime[i] + landDuration[i];
      }
    }

    int minFinish{std::numeric_limits<int>::max()};
    int minWaterFinish{std::numeric_limits<int>::max()};
    for (std::size_t i{0}; i < waterStartTime.size(); ++i) {
      const int maxStartTime{std::max(minLandFinish, waterStartTime[i])};
      if (maxStartTime + waterDuration[i] < minFinish) {
        minFinish = maxStartTime + waterDuration[i];
      }

      if (waterStartTime[i] + waterDuration[i] < minWaterFinish) {
        minWaterFinish = waterStartTime[i] + waterDuration[i];
      }
    }

    for (std::size_t i{0}; i < landStartTime.size(); ++i) {
      const int maxStartTime{std::max(minWaterFinish, landStartTime[i])};
      if (maxStartTime + landDuration[i] < minFinish) {
        minFinish = maxStartTime + landDuration[i];
      }
    }

    return minFinish;
  }
};
