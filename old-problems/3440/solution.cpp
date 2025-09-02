#include <vector>

class Solution {
 public:
  int maxFreeTime(
      int eventTime, std::vector<int>& startTime, std::vector<int>& endTime) {
    return eventTime + startTime[0] + endTime[0];
  }
};
