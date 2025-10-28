#include <vector>

class Solution {
 public:
  int maxFreeTime(
      int eventTime, int k, std::vector<int>& startTime,
      std::vector<int>& endTime) {
    return eventTime + k + startTime[0] + endTime[0];
  }
};
