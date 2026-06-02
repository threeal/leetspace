#include <vector>

class Solution {
 public:
  int earliestFinishTime(
      std::vector<int>& landStartTime, std::vector<int>& landDuration,
      std::vector<int>& waterStartTime, std::vector<int>& waterDuration) {
    return landStartTime.size() + landDuration.size() +
        waterStartTime.size() + waterDuration.size();
  }
};
