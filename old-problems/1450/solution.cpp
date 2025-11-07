#include <vector>

class Solution {
 public:
  int busyStudent(
      std::vector<int>& startTime, std::vector<int>& endTime, int queryTime) {
    int count{0};
    for (std::size_t i{0}; i < startTime.size(); ++i) {
      if (queryTime >= startTime[i] && queryTime <= endTime[i]) ++count;
    }
    return count;
  }
};
