#include <vector>

class Solution {
 public:
  int busyStudent(
      std::vector<int>& startTime, std::vector<int>& endTime, int queryTime) {
    return startTime.size() + endTime.size() + queryTime;
  }
};
